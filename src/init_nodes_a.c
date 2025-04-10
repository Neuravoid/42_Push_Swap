/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ualkan <ualkan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:06:16 by ualkan            #+#    #+#             */
/*   Updated: 2025/03/26 19:56:45 by ualkan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_target_a(t_stack *a, t_stack *b)
{
	t_stack	*current_b;
	t_stack	*target_node;
	int		best_match_index;

	while (a)
	{
		best_match_index = INT_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->value < a->value
				&& current_b->value > best_match_index)
			{
				best_match_index = current_b->value;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match_index == INT_MIN)
			a->target_node = find_max(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}

static int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
#include <stdio.h>

static void	cost_calculate(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;
	int	a_moves;
	int	b_moves;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		if (a->above_median == 1)
			a_moves = a->index;
		else
			a_moves = len_a - a->index;
		if (a->target_node->above_median == 1)
			b_moves = a->target_node->index;
		else
			b_moves = len_b - a->target_node->index;
		if ((a->above_median && a->target_node->above_median)
			|| (!a->above_median && !a->target_node->above_median))
			a->push_cost = max(a_moves, b_moves);
		else
			a->push_cost = a_moves + b_moves;
		a = a->next;
	}
}

static void	set_cheapest(t_stack *stack)
{
	int		cheapest_value;
	t_stack	*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = INT_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = 1;
	//printf("cheapest selected: %ld (cost: %d)\n", cheapest_node->value, cheapest_value);

}

void	init_nodes_a(t_stack *a, t_stack *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	cost_calculate(a, b);
	set_cheapest(a);
}
