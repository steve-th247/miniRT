/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:28:27 by jyap              #+#    #+#             */
/*   Updated: 2024/04/29 13:11:42 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_array(char **lst)
{
	int	i;

	i = 0;
	while (lst[i])
	{
		free(lst[i]);
		i++;
	}
	free(lst);
	return (NULL);
}

static size_t	ft_count_word(const char *str, char c)
{
	size_t	count;

	if (!str)
		return (0);
	if (!*str)
		return (0);
	count = 0;
	while (*str)
	{
		while (*str == c)
			str++;
		if (*str)
			count++;
		while (*str != c && *str)
			str++;
	}
	return (count);
}

char	**ft_split(const char *str, char c)
{
	char	**lst;
	size_t	word_len;
	int		i;

	lst = malloc((ft_count_word(str, c) + 1) * sizeof(*lst));
	if (!str || !lst)
		return (NULL);
	i = 0;
	while (*str)
	{
		while (*str == c && *str)
			str++;
		if (*str)
		{
			word_len = ft_strchr(str, c) - str;
			if (!ft_strchr(str, c))
				word_len = ft_strlen(str);
			lst[i] = ft_substr(str, 0, word_len);
			if (lst[i++] == NULL)
				free_array(lst);
			str += word_len;
		}
		lst[i] = 0;
	}
	return (lst);
}
