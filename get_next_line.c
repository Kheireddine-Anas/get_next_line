/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheired <akheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 08:32:49 by akheired          #+#    #+#             */
/*   Updated: 2024/01/31 20:02:50 by akheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*holder;
	char		*buffer;
	long		readed;
	char		*line;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(holder), NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(buffer), NULL);
	while (1)
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed < 0)
			return (free(buffer), NULL);
		buffer[readed] = '\0';
		holder = ft_strjoin(holder, buffer);
		if(holder[0] == '\0' && readed < BUFFER_SIZE)
			return (NULL);
		if (find_new_line(buffer) == 1 || readed < BUFFER_SIZE)
			break ;
	}

	free(buffer);
	line = first_line(holder);
	holder = last_line(holder);
	return (line);
}
