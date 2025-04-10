/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ualkan <ualkan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:33:31 by ualkan            #+#    #+#             */
/*   Updated: 2025/03/25 18:02:13 by ualkan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	**splitted_argv;
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	else if (argc == 2 && !argv[1][0])
		exit_command();
	else if (argc == 2)
	{
		splitted_argv = ft_split(argv[1]);
		init_stack(&a, splitted_argv, argc - 1);
	}
	else
		init_stack(&a, argv + 1, argc - 1);
	if (!stack_sorted(a))
		sort_stacks(&a, &b);
	if (argc == 2)
		ft_free_split(splitted_argv);
	free_stack(&a);
	return (0);
}
