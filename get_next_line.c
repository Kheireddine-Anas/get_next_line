/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheired <akheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 08:32:49 by akheired          #+#    #+#             */
/*   Updated: 2024/01/29 16:03:00 by akheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <fcntl.h>
#include <stdio.h>
void	ft_putchar(char c)
{
	write(1, &c, 1);
}
int	ft_strlen(char *str)
{
	int	i;
	
	i = 0;
	
	while (str && str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}
char	*ft_strdup(char *str)
{
	int		i;
	char	*dst;

	i = 0;
	dst = malloc(ft_strlen(str) +1);
	if (!dst)
		return (NULL);
	while(str[i])
	{	
		dst[i] = str[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}

int	find_new_line(char *str)
{
	if(!str)
		return 0;
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
	int		j = 0;

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
	int		j;

	i = 0;
	j = 0;
	while(str && str[i] && str[i] != '\n')
		i++;
	dst = malloc(i + 1);
	while (str[i])
	{
		dst[j] = str[i];
		j++;
		if(str[i] == '\n')
			break;
		i++;
	}
	dst[i] = 0;
	return (dst);
}

char    *ft_strchr(char *str)
{
	int i = 0;
	int j = 0;
	while(str && str[i] && str[i] != '\n')
		i++;
	char *nw_line = malloc(ft_strlen(str +i) + 1);
	i++;
	while(str && str[i] && str[i] != '\n')
	{
		nw_line[j] = str[i++];
	}
	nw_line[j] = 0;
	return (nw_line);
}

char	*get_next_line(int fd)
{
	static char	*holder;
	char		buffer[BUFFUR_SIZE +1];
	int			fd_num;
	char		*line;

	while (1)
	{
		fd_num = read(fd, buffer, BUFFUR_SIZE);
		if (fd_num <= 0 || BUFFUR_SIZE <= 0)
			return (NULL);
		buffer[fd_num] = '\0';
		holder = ft_strjoin(holder, buffer);
		if (find_new_line(buffer) == 1)
			break;
	}
	line = last_line(holder);
	holder = ft_strchr(holder);
	printf("%s", line);
	return (line);
}
 
int main()
{
	int fd = open("txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("ssssss\n");
	while (1);
	// printf("%s", ft_strchr(get_next_line(fd)));
}