
#include "push_swap.h"

static int ft_count_numbers(char *str)
{
    int i;
    int count;

    count = 0;
    i  = 0;
    while (str[i] != '\0')
    {
        if (str[i] != '\t' && str[i] != ' ')
        {
            count++;
            while ((str[i] != '\0') && (str[i] != '\t') && (str[i] != ' '))
                i++;
        }
        else
            i++;
    }
    return (count);
}


void ft_str_to_num_array(int argc, char **argv, t_fill *created_list)
{
	char    **array;
	int     i;
    int     j;
    int     count;
	int		*tmp;
	int  	k;

    i = 1;
    while (i < argc)
    {
        j = -1;
        count = ft_count_numbers(argv[i]);
		tmp = (int *)malloc(count * sizeof(int));
		if (tmp == NULL)
			exit (1);
		array = ft_split(argv[i], ' ');
		while (j < count)
		{
			j++;
			tmp[j] = ft_atoi(array[j]);
			free (array[j]);
		}
		free(array);
		k = -1;
		while (k < count)
		{
			k++;
			created_list->stack_a[created_list->count + k] = tmp[i];
		}
		created_list->count += count;
		free(tmp);
    }
}
