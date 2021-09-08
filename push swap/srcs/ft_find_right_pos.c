
#include "push_swap.h"

static int ft_compare_and_find_best_pos(t_stack *a, int tmp, int data)
{
    t_stack	*s;
    int		res;

    s = a;
    res = 0;
    while (s && res == 0)
    {
        if (s->data < tmp && s->data > data)
            res = 1;
        s = s->next;
    }
    return (res);
}

static void ft_best_pos_to_insert(t_params *count, t_stack *b, int *act, int *tmp)
{
    while (count->a)
    {
        *tmp = count->a->data;
        if (b->data > count->a->data)
        {
            *act += 1;
            if (b->data < count->a->next->data)
                break ;
            count->a = count->a->next;
        }
        else
            break ;
    }
    if (ft_compare_and_find_best_pos(count->a, *tmp, b->data) == 1)
    {
        while (count->a)
        {
            if (count->a->data > b->data && count->a->data < *tmp )
                break ;
            *act += 1;
            count->a = count->a->next;
        }
    }
}

int		ft_find_right_pos(t_params *count, t_stack *b, t_moves *moves, int min)
{
    int ans;
    int tmp;
    int act;

    act = 0;
    tmp = 0;
    ft_best_pos_to_insert(count, b, &act, &tmp);
    if (count->a->rot == -1)
        act = count->num_of_el_in_a - act;
    if (min == -1 || (act + b->move) < min)
    {
        moves->a_pos = count->a->rot;
        moves->b_pos = b->rot;
        moves->a_count = act;
        moves->b_count = b->move;
        ans = act + b->move;
    }
    else
        ans = min;
    return (ans);
}