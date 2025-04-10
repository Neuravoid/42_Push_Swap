/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ualkan <ualkan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:07:33 by ualkan            #+#    #+#             */
/*   Updated: 2025/03/25 15:12:39 by ualkan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **head)
{
	t_stack	*first;
	t_stack	*second;

	if (!*head || !(*head)->next)
		return ;
	first = *head;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*head = second;
}

void	s(t_stack **a, t_stack **b, char target)
{
	if (target == 'a')
	{
		swap(a);
		write(1, "sa\n", 3);
	}
	if (target == 'b')
	{
		swap(b);
		write(1, "sb\n", 3);
	}
	if (target == 's')
	{
		swap(a);
		swap(b);
		write(1, "ss\n", 3);
	}
}

static void	push(t_stack **dst, t_stack **src)
{
	t_stack	*push_node;

	if (!*src)
		return ;
	push_node = *src;
	*src = (*src)->next;
	push_node->next = *dst;
	*dst = push_node;
}

void	p(t_stack **a, t_stack **b, char target)
{
	if (target == 'a')
	{
		push(a, b);
		write(1, "pa\n", 3);
	}
	if (target == 'b')
	{
		push(b, a);
		write(1, "pb\n", 3);
	}
}
