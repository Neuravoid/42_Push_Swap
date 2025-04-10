/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ualkan <ualkan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:07:02 by ualkan            #+#    #+#             */
/*   Updated: 2025/03/26 19:06:06 by ualkan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_stack **a, t_stack **b)
{
	t_stack	*biggest_node;

	biggest_node = find_max(*a);
	if (biggest_node == *a)
		r(a, b, 'a');
	else if ((*a)->next == biggest_node)
		rr(a, b, 'a');
	if ((*a)->value > (*a)->next->value)
		s(a, b, 'a');
}

static	void	sort_small(t_stack **a, t_stack **b)
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a == 2)
		s(a, b, 'a');
	if (len_a == 3)
		sort_three(a, b);
}

void	sort_stacks(t_stack **a, t_stack **b)
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a == 2 || len_a == 3)
		sort_small(a, b);
	else
	{
		if (len_a-- > 3 && !stack_sorted(*a))
			p(a, b, 'b');
		if (len_a-- > 3 && !stack_sorted(*a))
			p(a, b, 'b');
		while (len_a-- > 3 && !stack_sorted(*a))
		{
			init_nodes_a(*a, *b);
			move_a_to_b(a, b);
		}
		sort_three(a, b);
		while (*b)
		{
			init_nodes_b(*a, *b);
			move_b_to_a(a, b);
		}
		current_index(*a);
		min_on_top(a, b);
	}
}
