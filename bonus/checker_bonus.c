/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ualkan <ualkan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 20:13:11 by ualkan            #+#    #+#             */
/*   Updated: 2025/03/25 19:41:38 by ualkan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	execute_command(t_stack **a, t_stack **b, char *command, int *f)
{
	if (!ft_strcmp(command, "sa\n"))
		s(a, b, 'a');
	else if (!ft_strcmp(command, "sb\n"))
		s(a, b, 'b');
	else if (!ft_strcmp(command, "ss\n"))
		s(a, b, 's');
	else if (!ft_strcmp(command, "pa\n"))
		p(a, b, 'a');
	else if (!ft_strcmp(command, "pb\n"))
		p(a, b, 'b');
	else if (!ft_strcmp(command, "ra\n"))
		r(a, b, 'a');
	else if (!ft_strcmp(command, "rb\n"))
		r(a, b, 'b');
	else if (!ft_strcmp(command, "rr\n"))
		r(a, b, 'r');
	else if (!ft_strcmp(command, "rra\n"))
		rr(a, b, 'a');
	else if (!ft_strcmp(command, "rrb\n"))
		rr(a, b, 'b');
	else if (!ft_strcmp(command, "rrr\n"))
		rr(a, b, 'r');
	else
		*f = -1;
}

static void	read_commands(t_stack **a, t_stack **b)
{
	int		f;
	char	*command;

	command = get_next_line(0);
	while (command)
	{
		f = 0;
		execute_command(a, b, command, &f);
		if (f == -1)
		{
			free(command);
			get_next_line(-1);
			free_stack(a);
			free_stack(b);
			exit_command();
		}
		free(command);
		command = get_next_line(0);
	}
}

static void	checker_command(t_stack *a, t_stack *b)
{
	if (stack_sorted(a) && (b == NULL))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

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
		init_stack(&a, splitted_argv, stack_len(splitted_argv));
	}
	else
		init_stack(&a, argv + 1, argc - 1);
	read_commands(&a, &b);
	checker_command(a, b);
	if (argc == 2)
		ft_free_split(splitted_argv);
	free_stack(&a);
	free_stack(&b);
}
