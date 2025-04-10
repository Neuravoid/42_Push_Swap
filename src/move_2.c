/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ualkan <ualkan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:06:52 by ualkan            #+#    #+#             */
/*   Updated: 2025/03/21 20:26:51 by ualkan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = first->next;
	last = find_last(first);
	first->next = NULL;
	last->next = first;
}

void	r(t_stack **a, t_stack **b, char target)
{
	if (target == 'a')
	{
		rotate(a);
		write(1, "ra\n", 3);
	}
	if (target == 'b')
	{
		rotate(b);
		write(1, "rb\n", 3);
	}
	if (target == 'r')
	{
		rotate(a);
		rotate(b);
		write(1, "rr\n", 3);
	}
}

static void	rev_rotate(t_stack **stack)
{
	t_stack	*prev;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	prev = NULL;
	last = *stack;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rr(t_stack **a, t_stack **b, char target)
{
	if (target == 'a')
	{
		rev_rotate(a);
		write(1, "rra\n", 4);
	}
	if (target == 'b')
	{
		rev_rotate(b);
		write(1, "rrb\n", 4);
	}
	if (target == 'r')
	{
		rev_rotate(a);
		rev_rotate(b);
		write(1, "rrr\n", 4);
	}
}
