/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ualkan <ualkan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:07:17 by ualkan            #+#    #+#             */
/*   Updated: 2025/03/25 20:01:11 by ualkan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(const char *s)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while ((*s) == ' ' || (*s) == '\t' || (*s) == '\n')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
		result = result * 10 + (*s++ - '0');
	return (result * sign);
}

static void	append_node(t_stack **stack, int n)
{
	t_stack	*node;
	t_stack	*last;

	if (!stack)
		exit_command();
	node = malloc(sizeof(t_stack));
	if (!node)
		exit_command();
	node->next = NULL;
	node->value = n;
	node->cheapest = 0;
	if (!(*stack))
		*stack = node;
	else
	{
		last = find_last(*stack);
		last->next = node;
	}
}

void	init_stack(t_stack **a, char **argv, int argc)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (number_checker(argv[i]))
			free_errors(a, argv, argc);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_errors(a, argv, argc);
		if (duplicate_checker(*a, (int)n))
			free_errors(a, argv, argc);
		append_node(a, (int)n);
		i++;
	}
}
