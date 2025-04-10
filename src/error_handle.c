/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ualkan <ualkan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:06:06 by ualkan            #+#    #+#             */
/*   Updated: 2025/03/25 20:01:11 by ualkan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	number_checker(char *str)
{
	if (!(*str == '+' || *str == '-'
			|| (*str >= '0' && *str <= '9')))
		return (1);
	if ((*str == '+' || *str == '-')
		&& !(str[1] >= '0' && str[1] <= '9'))
		return (1);
	while (*++str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (1);
	}
	return (0);
}

int	duplicate_checker(t_stack *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->value == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	exit_command(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
