/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheired <akheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:04:38 by akheired          #+#    #+#             */
/*   Updated: 2024/01/31 16:44:09 by akheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

int	find_new_line(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

char	*ft_strjoin(char *holder, char *buffer)
{
	char	*new_str;
	int		i;

	i = 0;
	new_str = malloc(ft_strlen(holder) + ft_strlen(buffer) + 1);
	if (!new_str)
		return (free(new_str), free(holder), NULL);
	while (holder && holder[i])
	{
		new_str[i] = holder[i];
		i++;
	}
	while (buffer && *buffer)
		new_str[i++] = *buffer++;
	new_str[i] = '\0';
	free(holder);
	return (new_str);
}

char	*first_line(char *str)
{
	char	*dst;
	int		i;

	i = 0;
	while (str && str[i] && str[i] != '\n')
		i++;
	dst = malloc(i + 1);
	if (!dst)
		return (free(dst), NULL);
	i = 0;
	while (str[i])
	{
		dst[i] = str[i];
		if (str[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	dst[i] = 0;
	return (dst);
}

char	*last_line(char *str)
{
	char	*nw_line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str && str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	nw_line = malloc(ft_strlen(str) - i + 1);
	if (!nw_line)
		return (free(nw_line), NULL);
	// if (str[i] == '\n')
		// i++;
	int size = ft_strlen(str) - i;
	while (j < size)
		nw_line[j++] = str[i++];
	nw_line[j] = 0;
	if (str)
		free(str);
	return (nw_line);
}
