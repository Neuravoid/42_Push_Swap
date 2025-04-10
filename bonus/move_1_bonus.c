/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_1_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ualkan <ualkan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 20:15:13 by ualkan            #+#    #+#             */
/*   Updated: 2025/03/21 21:39:09 by ualkan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
		swap(a);
	if (target == 'b')
		swap(b);
	if (target == 's')
	{
		swap(a);
		swap(b);
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
	}
	if (target == 'b')
	{
		push(b, a);
	}
}
