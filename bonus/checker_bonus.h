/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ualkan <ualkan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 20:13:18 by ualkan            #+#    #+#             */
/*   Updated: 2025/03/25 20:01:11 by ualkan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_stack
{
	long			value;
	long			index;
	int				push_cost;
	int				above_median;
	int				cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
}				t_stack;

char	*get_next_line(int fd);
t_stack	*find_last(t_stack *stack);
int		ft_strcmp(char *s1, char *s2);

int		stack_sorted(t_stack *stack);
int		duplicate_checker(t_stack *a, int n);
int		number_checker(char *str_n);
size_t	ft_strlen(char *s);
int		stack_len(char **arr);
void	ft_free_split(char **result);
void	free_errors(t_stack **a, char **argv, int argc);
void	free_stack(t_stack **stack);
void	exit_command(void);

void	r(t_stack **a, t_stack **b, char target);
void	rr(t_stack **a, t_stack **b, char target);
void	s(t_stack **a, t_stack **b, char target);
void	p(t_stack **a, t_stack **b, char target);

void	init_stack(t_stack **a, char **argv, int argc);
char	**ft_split(char *s);
void	ft_free_gnl_stack(void);

#endif
