
#include "push_swap.h"

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

	}

}

