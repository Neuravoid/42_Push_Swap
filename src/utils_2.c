/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ualkan <ualkan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:19:53 by ualkan            #+#    #+#             */
/*   Updated: 2025/03/19 20:32:54 by ualkan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_cheapest(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	prep_for_push(t_stack **a, t_stack **b, t_stack *top_node, char target)
{
	t_stack	**stack;

	if (target == 'a')
		stack = a;
	else
		stack = b;
	while (*stack != top_node)
	{
		if (target == 'a')
		{
			if (top_node->above_median)
				r(a, b, 'a');
			else
				rr(a, b, 'a');
		}
		else if (target == 'b')
		{
			if (top_node->above_median)
				r(a, b, 'b');
			else
				rr(a, b, 'b');
		}
	}
}

void	current_index(t_stack *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = 1;
		else
			stack->above_median = 0;
		stack = stack->next;
		++i;
	}
}
