/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdwyynen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 16:46:40 by cdwyynen          #+#    #+#             */
/*   Updated: 2021/05/14 16:46:42 by cdwyynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i = i + 1;
	return (i);
}

static char	*ft_clear_and_write(char *line, char *buf)
{
	char	*clear;

	clear = line;
	line = ft_strjoin(line, buf);
	free(clear);
	return (line);
}

static int	ft_write_and_clean(char *n_pointer, char **line, char *buf, char
**cut)
{
	char	*clear;

	*n_pointer = '\0';
	n_pointer++;
	clear = *line;
	*line = ft_strjoin(*line, buf);
	free(clear);
	*cut = ft_strdup(n_pointer);
	free(buf);
	return (1);
}

static char	*ft_check_cut(char *cut, char **line, char **buf)
{
	char	*n_pointer;

	n_pointer = NULL;
	if (cut != 0)
	{
		n_pointer = ft_strchr(cut, '\n');
		if (n_pointer != 0)
		{
			*n_pointer = '\0';
			n_pointer++;
			*line = ft_strdup(cut);
			ft_strcpy(cut, n_pointer);
		}
		else
		{
			*line = ft_strdup(cut);
			free(cut);
			cut = NULL;
		}
	}
	else
		*line = ft_strdup("");
	if (n_pointer != NULL)
		free(*buf);
	return (n_pointer);
}

int	get_next_line(int fd, char **line)
{
	char		*buf;
	ssize_t		count;
	char		*n_pointer;
	static char	*cut;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0 || fd > 19)
		return (-1);
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buf == NULL)
		return (-1);
	n_pointer = ft_check_cut(cut, line, &buf);
	if (n_pointer != NULL)
		return (1);
	count = read(fd, buf, BUFFER_SIZE);
	while (count != 0)
	{
		buf[count] = '\0';
		n_pointer = ft_strchr(buf, '\n');
		if (n_pointer != 0)
			return (ft_write_and_clean(n_pointer, line, buf, &cut));
		*line = ft_clear_and_write(*line, buf);
		count = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	return (0);
}
