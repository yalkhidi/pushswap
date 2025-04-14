#include "push_swap.h"

bool    is_sorted(t_stack *stack)
{
    t_node  *nodes;

    nodes = stack->top;
    while(nodes->next)
    {
        if(nodes->value > nodes->next->value)
            return (false);
        nodes = nodes->next;
    }
    return (true);
}

void    sort_three(t_stack *stack)
{
    int first;
    int middle;
    int last;

    first = peek(stack);
    middle = stack->top->next->value;
    last = stack->top->next->next->value;
    if (first > middle && middle < last && last > first)
        sa(stack);
    else if (first > middle && middle < last && last < first)
        ra(stack);
    else if (first < middle && middle > last && last < first)
        rra(stack);
    else if (first > middle && middle > last && last < first)
    {
        sa(stack);
        rra(stack);
    }
    else if (first < middle && middle > last && last > first)
    {
        sa(stack);
        ra(stack);
    }
}
