
#include "push_swap.h"
#include <stdio.h>

static void ft_free(t_params *params)
{
    int     i;
    t_stack *tmp;

    i = 0;
    while (i < params->num_of_el_in_a)
    {
        tmp = params->a;
        params->a = params->a->next;
        free(tmp);
        i++;
    }
    i = 0;
    while (i < params->num_of_el_in_b)
    {
        tmp = params->b;
        params->b = params->b->next;
        free(tmp);
        i++;
    }
}

static void ft_null_params(t_params *params)
{
	params->a = 0;
	params->b = 0;
	params->num_of_el_in_a = 0;
	params->num_of_el_in_b = 0;
	params->min = 0;
	params->max = 0;
	params->median = 0;
};

int main (int argc, char **argv)
{
    t_fill      *created_list;
	t_params    *params;
	int         check;

    if (argc < 2)
        exit(1);
    created_list = (t_fill *)malloc(sizeof(t_fill));
    if (created_list == NULL)
		exit(1);
	created_list->count = 0;
	params = (t_params *)malloc(sizeof(t_params));
	if (params == NULL)
		exit(1);
	ft_null_params(params);
	if (ft_check_data(argc, argv) == 1)
	{
        ft_str_to_num_array(argc, argv, created_list);
		ft_check_if_copies(created_list, params);
        check = ft_check_if_sorted(created_list);
        if (check == 1)
        {
            ft_initialization(created_list, params);
            ft_type_of_sorting(params);
            ft_free(params);
        }
	}
	free(params);
	free(created_list);
	return (0);
}

