/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:36:38 by yalkhidi          #+#    #+#             */
/*   Updated: 2025/04/16 18:17:22 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_chunking	*inti_chunk(t_stack *a)
{
	t_chunking *info;

	info = (t_chunking *)malloc(sizeof(t_chunking));
	info->arr = copy_sort(a);
	info->total_size = a->size;
	info->num_chunks = chunk_count(a->size);
	info->chunk_size = info->total_size / info->num_chunks;
	info->current_chunk = 0;
    info->start = 0;
    info->end = 0;
    return (info);
}
void	pushing_to_b(t_stack *a, t_stack *b, t_chunking *chunking)
{
    int     index;

	while (chunking->current_chunk < chunking->num_chunks)
	{
        // printf("chunk size: %d\n", chunking->chunk_size);
        // printf("total: %d\n", chunking->total_size);
        chunking->start = chunking->current_chunk * chunking->chunk_size;
        chunking->end = chunking->start + chunking->chunk_size - 1;
        // printf("a->size: %d\n", a->size);
        // printf("start: %d\n", chunking->start);
        if (chunking->end >= chunking->total_size)
            chunking->end = chunking->total_size - 1;
        // printf("end: %d\n", chunking->end);
        // if (has_value_in_chunk(a, chunking))
        //     printf("true\n");
        // else
        //     printf("false\n");
        while(has_value_in_chunk(a, chunking))
        {
            index = get_closest_in_chunk(a, chunking);
            // print_stack(a);
            if (index>= 0)
            {
                while(index > 0)
                {
                    ra(a);
                    index--;
                }
            }
            else
            {
                while (index < 0)
                {
                    rra(a);
                    index++;
                }
            }
            if (peek(a) >= chunking->arr[chunking->end - 1])
            {
                pb(a, b);
                rb(b);
            }
            else
                pb(a, b);
        }
        // print_stack(b);
        chunking->current_chunk++;
        // printf("DONE\n");
	}
    push_back_to_a(a, b);
}

// void pushing_to_b(t_stack *a, t_stack *b, t_chunking *chunking)
// {
//     int index;
//     int top;
//     int mid_index;

//     while (chunking->current_chunk < chunking->num_chunks)
//     {
//         chunking->start = chunking->current_chunk * chunking->chunk_size;
//         chunking->end = chunking->start + chunking->chunk_size - 1;
//         if (chunking->end >= chunking->total_size)
//             chunking->end = chunking->total_size - 1;

//         while (has_value_in_chunk(a, chunking))
//         {
//             index = get_closest_in_chunk(a, chunking);
//             if (index == -1)
//                 break;

//             // Rotate the stack to position the element at the top
//             if (index >= 0)
//             {
//                 while (index > 0)
//                 {
//                     ra(a);
//                     index--;
//                 }
//             }
//             else
//             {
//                 index = -index;
//                 while (index > 0)
//                 {
//                     rra(a);
//                     index--;
//                 }
//             }

//             top = peek(a);
//             pb(a, b);

//             // Correct mid_index based on chunk boundaries
//             mid_index = (chunking->start + chunking->end) / 2;
//             if (top < chunking->arr[mid_index])
//                 rb(b); // rotate b if the value is smaller than the mid value
//         }
//         chunking->current_chunk++;
//     }
// }



bool    is_in_chunk(t_chunking *chunk, int value)
{
    if (value >= chunk->arr[chunk->start] && value <= chunk->arr[chunk->end])
        return (true);
    return (false);
}

bool    has_value_in_chunk(t_stack *a, t_chunking *chunk)
{
    t_node  *current;

    current = a->top;
    while(current)
    {
        // printf("current->value: %ld\n", current->value);
        if (is_in_chunk(chunk, current->value))
            return (true);
        current = current->next;
    }
    return (false);
}

int value_index(t_stack *a, t_chunking *chunk)
{
    int index;
    t_node *current;

    current = a->top;
    index = 0;
    while (current)
    {
        if (is_in_chunk(chunk, current->value))
            return (index);
        index++;
        current = current->next;
    }
    return (-1);
}

int get_closest_in_chunk(t_stack *a, t_chunking *chunk)
{
    t_node  *current;
    int     top_steps;
    int     bottom_steps;
    int     i;

    // Count from top
    current = a->top;
    top_steps = 0;
    while (current)
    {
        if (is_in_chunk(chunk, current->value))
            break;
        current = current->next;
        top_steps++;
    }

    // Count from bottom
    current = a->top;
    i = 0;
    bottom_steps = -1;
    while (current)
    {
        if (is_in_chunk(chunk, current->value))
            bottom_steps = i;
        current = current->next;
        i++;
    }

    if (bottom_steps == -1)
        return (-1); // No element in the chunk found, return -1

    // Calculate steps from the bottom
    bottom_steps = a->size - bottom_steps;

    // Compare steps from top and bottom, return the smaller number of steps
    if (top_steps <= bottom_steps)
        return (top_steps);
    else
        return (-bottom_steps); // Negative means rra (reverse rotate)
}



// int	get_closest_in_chunk(t_stack *a, t_chunking *chunk)
// {
// 	t_node	*top_node;
// 	t_node	*bottom_node;
// 	int		top_steps;
// 	int		bottom_steps;
// 	int		i;

// 	top_node = a->top;
// 	bottom_node = a->top;
// 	top_steps = 0;
// 	bottom_steps = 0;
// 	i = 0;

// 	// move bottom_node to the bottom
// 	while (bottom_node && bottom_node->next)
// 	{
// 		bottom_node = bottom_node->next;
// 	}

// 	// count from top
// 	while (top_node && !is_in_chunk(chunk, top_node->value))
// 	{
// 		top_node = top_node->next;
// 		top_steps++;
// 	}

// 	// count from bottom
// 	while (bottom_node && !is_in_chunk(chunk, bottom_node->value))
// 	{
// 		t_node *temp = a->top;
// 		i = 0;
// 		while (temp && temp != bottom_node)
// 		{
// 			temp = temp->next;
// 			i++;
// 		}
// 		bottom_steps = a->size - i;
// 		bottom_node = bottom_node->next; // exit loop
// 	}

// 	if (top_steps <= bottom_steps)
// 		return (top_steps);
// 	else
// 		return (-bottom_steps); // negative means use rra
// }