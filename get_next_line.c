/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheired <akheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 08:32:49 by akheired          #+#    #+#             */
/*   Updated: 2024/01/26 16:54:01 by akheired         ###   ########.fr       */
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

char	*behind_line(char *str)
{
	int		i;
	char	*new_line;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			i++;
			while (str[i])
			{
				*new_line++ = str[i];
			}
		}
		if (!str[i])
			break;
		i++;
	}
	return (new_line);
}


char *ft_strdup(const char *str)
{
    if (str == NULL)
        return NULL;

    // Calculate the length of the input string
    size_t len = 0;
    while (str[len] != '\0') {
        len++;
    }

    // Allocate memory for the duplicate string (+1 for the null terminator)
    char *dup_str = (char *)malloc((len + 1) * sizeof(char));
    if (dup_str == NULL) {
        // Memory allocation failed
        return NULL;
    }

    // Copy the characters from the original string to the duplicate
    for (size_t i = 0; i <= len; i++) {
        dup_str[i] = str[i];
    }

    return dup_str;
}

char *behind_line(char *str)
{
    int i = 0;
    char *new_line = NULL;

    while (str[i])
    {
        if (str[i] == '\n')
        {
            i++;
            new_line = ft_strdup(&str[i]);
            break;
        }
        i++;
    }
    return new_line;
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
		return ( NULL);
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
			break;
		}
		new_str[i++] = *buffer++;
	}
	new_str[i] = 0;
	return (new_str);
}
char	*get_next_line(int fd)
{
	static char	*holder;
	char		*buffer;
	int			fd_num;
	char		*tmp;

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
			tmp = holder;
			holder = behind_line(holder);
			free(buffer);
			free(holder);
			break ;
		}
		else
			holder = ft_strjoin(holder, buffer);
		free(holder);
	}
	return (tmp);
}
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int fd = open("txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	while (1);
}