/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tf.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheired <akheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 08:32:49 by akheired          #+#    #+#             */
/*   Updated: 2024/01/30 16:24:12 by akheired         ###   ########.fr       */
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
	if(!str)
		return (0);
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

 #include <stdio.h>
char	*ft_strjoin(char *holder, char *buffer)
{
	char	*new_str;
	int		i;

	i = 0;
	new_str = malloc(ft_strlen(holder) + ft_strlen(buffer) + 1);
	if (!new_str)
		return ( NULL);
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
	while(str && str[i] && str[i] != '\n')
		i++;
	dst = malloc(i + 1);
	i = 0;
	while (str[i])
	{
		dst[i] = str[i];
		if(str[i] == '\n')
		{
			i++;
			break;
		}
		i++;
	}
	dst[i] = 0;
	return (dst);
}

char	*ft_strchr(char *str)
{
	char *nw_line;
	int i;
	int j;

	i = 0;
	j = 0;
	while(str && str[i] && str[i] != '\n')
		i++;
	nw_line = malloc(ft_strlen(str +i) + 1);
	// printf("#%p#", nw_line);
	if (!nw_line)
		return (NULL);
	if(str[i] == '\n')
		i++;
	while(str && str[i] && str[i] != '\n')
		nw_line[j++] = str[i++];
	nw_line[j] = 0;
	if(str)
		free(str);
	return (nw_line);
}

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
		if (readed < 0 || BUFFER_SIZE <= 0)
			return (NULL);
		buffer[readed] = '\0';
		holder = ft_strjoin(holder, buffer);
		// printf("===> %s\n", holder);
		if (find_new_line(buffer) == 1 || readed < BUFFER_SIZE)
			break;
	}
	
	// printf(" holder ===> %s\n", holder);
	if (buffer)
		free(buffer);
	line = first_line(holder);
	holder = ft_strchr(holder);
	// printf("#%s#", holder);
	return (line);
}
int main()
{
	int fd = open("txt", O_RDONLY);
	char *line1 = get_next_line(fd);
	printf("%s", line1);
	free(line1);

	char *line2 = get_next_line(fd);
	printf("%s", line2);
	free(line2);
	char *line5 = get_next_line(fd);
	printf("%s", line5);
	free(line2);
	printf("\n");
	close(fd);
	// sleep(1000);
	// while(1);
}