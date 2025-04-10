/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ualkan <ualkan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 20:15:19 by ualkan            #+#    #+#             */
/*   Updated: 2025/03/21 21:32:19 by ualkan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
	}
	if (target == 'b')
	{
		rotate(b);
	}
	if (target == 'r')
	{
		rotate(a);
		rotate(b);
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
	}
	if (target == 'b')
	{
		rev_rotate(b);
	}
	if (target == 'r')
	{
		rev_rotate(a);
		rev_rotate(b);
	}
}
