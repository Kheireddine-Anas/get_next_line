/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheired <akheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 08:32:49 by akheired          #+#    #+#             */
/*   Updated: 2024/02/01 17:31:12 by akheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*holder;
	char		*buffer;
	ssize_t		readed;
	char		*line;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(holder), NULL);
	while (1)
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed < 0)
			return (free(buffer), free(holder), NULL);
		buffer[readed] = '\0';
		holder = ft_strjoin(holder, buffer);
		if((!holder || *holder == '\0') && readed < BUFFER_SIZE)
			return (free(buffer), free(holder), NULL);
		if (find_new_line(buffer) == 1 || readed < BUFFER_SIZE)
			break ;
	}
	free(buffer);
	line = first_line(holder);
	holder = last_line(holder);
	return (line);
}
