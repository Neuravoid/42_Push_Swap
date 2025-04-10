/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ualkan <ualkan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:07:28 by ualkan            #+#    #+#             */
/*   Updated: 2025/03/26 18:51:47 by ualkan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		r(a, b, 'r');
	current_index(*a);
	current_index(*b);
}

void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rr(a, b, 'r');
	current_index(*a);
	current_index(*b);
}

void	move_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!cheapest_node->above_median
		&& !cheapest_node->target_node->above_median)
		rev_rotate_both(a, b, cheapest_node);
	prep_for_push(a, b, cheapest_node, 'a');
	prep_for_push(a, b, cheapest_node->target_node, 'b');
	p(a, b, 'b');
}

void	move_b_to_a(t_stack **a, t_stack **b)
{
	prep_for_push(a, b, (*b)->target_node, 'a');
	p(a, b, 'a');
}

void	min_on_top(t_stack **a, t_stack **b)
{
	current_index(*a);
	while ((*a)->value != find_min(*a)->value)
	{
		if (find_min(*a)->above_median)
			r(a, b, 'a');
		else
			rr(a, b, 'a');
	}
}
