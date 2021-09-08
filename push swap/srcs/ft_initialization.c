
#include "push_swap.h"

void ft_initialization(t_fill *created_list, t_params *params)
{
    int         i;
    t_stack    *newlist;
    t_stack    *firstel;

    i = 0;
    params->b = NULL;
    newlist = (t_stack *)malloc(sizeof(t_stack));
    if (newlist == NULL)
        exit (1);
    firstel = newlist;
    while (i < created_list->count)
    {
        if (i < created_list->count - 1)
        {
            newlist->next = (t_stack *)malloc(sizeof(t_stack));
            if (newlist->next == NULL)
                exit (1);
        }
        newlist->data = created_list->stack_a[i];
        if (i == created_list->count - 1)
            newlist->next = NULL;
        else
            newlist = newlist->next;
        i++;
    }
    params->a = firstel;
}
