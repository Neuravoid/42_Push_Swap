/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ualkan <ualkan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 20:14:40 by ualkan            #+#    #+#             */
/*   Updated: 2025/03/20 20:24:44 by ualkan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int		ft_srcnl(const char *s);
size_t	ft_l(const char *s);
char	*ft_strjoin(char *old_stack, char *buffer);
char	*get_next_line(int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_c(size_t num, size_t size);

#endif