/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ualkan <ualkan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:06:31 by ualkan            #+#    #+#             */
/*   Updated: 2025/03/26 16:08:17 by ualkan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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

char	**ft_split(char *str);
t_stack	*find_last(t_stack *stack);
t_stack	*find_min(t_stack *stack);
t_stack	*find_max(t_stack *stack);
t_stack	*get_cheapest(t_stack *stack);
int		stack_sorted(t_stack *stack);
int		duplicate_checker(t_stack *a, int n);
int		number_checker(char *str_n);
int		stack_len(t_stack *stack);
void	ft_free_split(char **result);
void	free_errors(t_stack **a, char **argv, int argc);
void	free_stack(t_stack **stack);
void	exit_command(void);
void	r(t_stack **a, t_stack **b, char target);
void	rr(t_stack **a, t_stack **b, char target);
void	s(t_stack **a, t_stack **b, char target);
void	p(t_stack **a, t_stack **b, char target);
void	sort_stacks(t_stack **a, t_stack **b);
void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
void	move_a_to_b(t_stack **a, t_stack **b);
void	move_b_to_a(t_stack **a, t_stack **b);
void	min_on_top(t_stack **a, t_stack **b);
void	prep_for_push(t_stack **a, t_stack **b, t_stack *top_node, char target);
void	init_stack(t_stack **a, char **argv, int argc);
void	current_index(t_stack *stack);
void	init_nodes_a(t_stack *a, t_stack *b);
void	init_nodes_b(t_stack *a, t_stack *b);
void	handle_sort(t_stack **a, t_stack **b);

#endif
