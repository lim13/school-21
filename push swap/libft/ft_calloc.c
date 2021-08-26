/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdwyynen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 16:39:56 by cdwyynen          #+#    #+#             */
/*   Updated: 2021/05/04 16:39:58 by cdwyynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*A;

	A = (void *)malloc(count * size);
	if (A == NULL)
		return (0);
	ft_bzero(A, count * size);
	return (A);
}
