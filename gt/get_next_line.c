/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheired <akheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 08:32:49 by akheired          #+#    #+#             */
/*   Updated: 2024/02/09 12:55:52 by akheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
*	GET_NEXT_LINE
*	-------------
*	DESCRIPTION
*	This function takes an opened file descriptor and returns its next line.
*	This function has undefined behavior when reading from a binary file.
*	PARAMETERS
*	#1. A file descriptor 
*	RETURN VALUES
*	If successful, get_next_line returns a string with the full line ending in
*	a line break (`\n`) when there is one. 
*	If an error occurs, or there's nothing more to read, it returns NULL.
*	----------------------------------------------------------------------------
*	AUXILIARY FUNCTIONS
*	-------------------
*	READ_TO_LEFT_STR
*	-----------------
*	DESCRIPTION
*	Takes the opened file descriptor and saves on a "buff" variable what readed
*	from it. Then joins it to the cumulative static variable for the persistence
*	of the information.
*	PARAMETERS
*	#1. A file descriptor.
*	#2. The pointer to the cumulative static variable from previous runs of
*	get_next_line.
*	RETURN VALUES
*	The new static variable value with buffer joined for the persistence of the info,
*	or NULL if error.
*/

#include "get_next_line.h"
#include <unistd.h>
//#include <stdio.h>
//#include <fcntl.h>

char	*ft_read_to_left_str(int fd, char *left_str)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(left_str, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		left_str = ft_strjoin(left_str, buff);
	}
	free(buff);
	return (left_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*left_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	left_str = ft_read_to_left_str(fd, left_str);
	if (!left_str)
		return (NULL);
	line = ft_get_line(left_str);
	left_str = ft_new_left_str(left_str);
	return (line);
}
/*#include <stdio.h>
int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	fd1 = open("t", O_RDONLY);

	i = 1;
	while (i < 2)
	{
		line = get_next_line(fd1);
		printf("line : %s", line);
		free(line);
		line = get_next_line(fd1);
		printf("line : %s", line);
		free(line);
		i++;
	}
	close(fd1);
	return (0);
}*/