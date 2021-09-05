
#include "push_swap.h"

static int *ft_copy(int *dest, const int *source, int count)
{
	int i;

	i = 0;
	while (i++ < count)
		dest[i] = source[i];
	return (dest);
}

void	ft_check_if_copies(t_fill *created_list, t_params *params)
{
	int	*no_double;

	no_double = (int *)malloc(sizeof(int) * (created_list->count));
	if (no_double == NULL)
		exit (-1);
	no_double = ft_copy(no_double, created_list->stack_a, created_list->count);




}

