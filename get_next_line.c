/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheired <akheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 08:32:49 by akheired          #+#    #+#             */
/*   Updated: 2024/01/30 16:03:33 by akheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*holder;
	char		*buffer;
	long		readed;
	char		*line;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (1)
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed <= 0 || BUFFER_SIZE <= 0)
			return (NULL);
		buffer[readed] = '\0';
		holder = ft_strjoin(holder, buffer);
		if (find_new_line(buffer) == 1 || readed < BUFFER_SIZE)
			break ;
	}
	if (buffer)
		free(buffer);
	line = first_line(holder);
	holder = last_line(holder);
	return (line);
}
#include <stdio.h>
int main()
{
    int fd = open("txt", O_RDONLY);
    char *line1 = get_next_line(fd);
    printf("%s", line1);


    char *line2 = get_next_line(fd);
    printf("%s", line2);


    close(fd);
    return 0;
}
