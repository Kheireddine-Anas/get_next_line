/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheired <akheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 08:32:49 by akheired          #+#    #+#             */
/*   Updated: 2024/01/26 13:49:59 by akheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

int	find_new_line(char *str)
{
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;
	
	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *holder, char *buffer)
{
	char	*new_str;
	int		i;
	int		j = 0;
	char	tmp[12];

	i = 0;
	new_str = malloc(ft_strlen(holder) + ft_strlen(buffer) + 1);
	if (!new_str)
		return (free(new_str), NULL);
	while (holder && *holder)
	{
		new_str[i++] = *holder++;
	}
	while (buffer && *buffer)
	{
		// ft_putchar('d');
		if (*buffer == '\n')
		{
			new_str[i++] = *buffer++;
			while (*buffer)
			{
				tmp[j++] = *buffer++;
			}
			
			break;
		}
		new_str[i++] = *buffer++;
	}
	new_str[i] = 0;
	ft_putchar('[');
	ft_putstr(tmp);
	ft_putchar('-');
	return (new_str);
}
char	*get_next_line(int fd)
{
	static char	*holder;
	char		*buffer;
	int			fd_num;
	char	*tmp = holder;

	buffer = malloc(BUFFUR_SIZE + 1);
	buffer[BUFFUR_SIZE] = '\0';
	while (1)
	{
		// printf("| %p |\n", holder);
		fd_num = read(fd, buffer, BUFFUR_SIZE);
		if (fd_num == -1 || BUFFUR_SIZE < 0 || fd_num == 0)
			return (0);
		if (find_new_line(buffer) == 1)
		{
			holder = ft_strjoin(holder, buffer);
			free(buffer);
			free(holder);
			break ;
		}
		else
			holder = ft_strjoin(holder, buffer);
		free(holder);
	}
	return (holder);
}
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int fd = open("txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	while (1);
}