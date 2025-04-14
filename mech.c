#include "push_swap.h"

int find_min_index(t_stack *stack) {
    t_node *current = stack->top;
    int min = current->value;
    int index = 0;
    int min_index = 0;

    current = current->next;
    while (current) {
        index++;
        if (current->value < min) {
            min = current->value;
            min_index = index;
        }
        current = current->next;
    }
    return min_index;
}

void rotate_min_to_top(t_stack *a) {
    int min_pos = find_min_index(a);
    int size = a->size;
    
    if (min_pos == 0) return;
    
    if (min_pos <= size/2)
    {
        while (min_pos-- > 0)
            ra(a);
    }
    else
    {
        min_pos = size - min_pos;
        while (min_pos-- > 0)
            rra(a);
    }
}

// Main Algorithm
void mechanical_turk(t_stack *a, t_stack *b) {
    if (is_sorted(a)) return;
    
    if (a->size == 2) {
        if (peek(a) > a->top->next->value)
            sa(a);
        return;
    }
    
    if (a->size == 3) {
        sort_three(a);
        return;
    }

    while (a->size > 0) {
        rotate_min_to_top(a);
        pb(a, b);
    }
    print_stack(b);
    while (b->size > 0)
        pa(a, b);
}
