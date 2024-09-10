/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:11:50 by jyap              #+#    #+#             */
/*   Updated: 2024/03/22 16:25:31 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_nl(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = -1;
	while (str[++i])
	{
		if (str[i] == '\n')
			return (1);
	}
	return (0);
}

char	*get_next_nl(int fd, char *output)
{
	char	*buf;
	int		i;

	buf = malloc(sizeof(*buf) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	i = 1;
	while (check_nl(output) == 0 && i != 0)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[i] = '\0';
		output = ft_strcomb(output, buf);
	}
	free(buf);
	return (output);
}

char	*get_read(char *input)
{
	int		i;
	char	*output;

	if (input[0] == '\0')
		return (NULL);
	i = 0;
	while (checkend(input[i]))
		i++;
	output = malloc(sizeof(*output) * (i + 1 + (input[i] == '\n')));
	if (!output)
		return (NULL);
	i = -1;
	while (checkend(input[++i]))
		output[i] = input[i];
	if (input[i] == '\n')
	{
		output[i] = input[i];
		i++;
	}
	output[i] = '\0';
	return (output);
}

char	*savepoint(char *input)
{
	int		i;
	int		j;
	char	*output;

	i = 0;
	while (checkend(input[i]))
		i++;
	if (input[i] == '\0')
	{
		free(input);
		return (NULL);
	}
	output = malloc(sizeof(*output) * (ft_strlen(input) - i++ + 1));
	if (!output)
		return (NULL);
	j = 0;
	while (input[i])
		output[j++] = input[i++];
	output[j] = '\0';
	free(input);
	return (output);
}

char	*get_next_line(int fd)
{
	char		*output;
	static char	*history[1025];

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	history[fd] = get_next_nl(fd, history[fd]);
	if (!history[fd])
		return (NULL);
	output = get_read(history[fd]);
	history[fd] = savepoint(history[fd]);
	return (output);
}
