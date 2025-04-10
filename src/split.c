/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ualkan <ualkan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:18:32 by ualkan            #+#    #+#             */
/*   Updated: 2025/03/25 18:52:10 by ualkan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	count_words(char const *s)
{
	size_t	count;
	int		in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if ((*s) == ' ' || (*s) == '\t' || (*s) == '\n')
			in_word = 0;
		else if (in_word == 0)
		{
			in_word = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (src[i])
		i++;
	len = i;
	if (dstsize == 0)
		return (len);
	i = 0;
	while (i < dstsize - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}

static char	*allocate_word(char const *s, size_t start, size_t length)
{
	char	*word;

	word = malloc((length + 1) * sizeof(char));
	if (!word)
		exit_command();
	ft_strlcpy(word, s + start, length + 1);
	return (word);
}

static char	**allocate_arr(char *s)
{
	int		word_count;
	char	**arr;

	if (!s)
		exit_command();
	word_count = count_words(s);
	arr = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!arr)
		exit_command();
	arr[word_count] = NULL;
	return (arr);
}

char	**ft_split(char *s)
{
	char	**result;
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	result = allocate_arr(s);
	while (s[i])
	{
		while (s[i] && (s[i] == 32 || s[i] == '\t' || s[i] == '\n'))
			i++;
		start = i;
		while (s[i] && !(s[i] == 32 || s[i] == '\t' || s[i] == '\n'))
			i++;
		if (i > start)
		{
			result[j] = allocate_word(s, start, i - start);
			if (!result[j])
				return (ft_free_split(result), NULL);
			j++;
		}
	}
	result[j] = NULL;
	return (result);
}
