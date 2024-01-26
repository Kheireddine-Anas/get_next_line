
#include <string.h>
#include "get_next_line.h"

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
char	*ft_strdup(const char *str)
{
    if (str == NULL)
        return NULL;
    size_t len = 0;
    while (str[len] != '\0') {
        len++;
    }

    char *dup_str = (char *)malloc((len + 1) * sizeof(char));
    if (dup_str == NULL) {
        return NULL;
    }

    for (size_t i = 0; i <= len; i++) {
        dup_str[i] = str[i];
    }

    return dup_str;
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
char *get_next_line(int fd)
{
    static char *holder = NULL;
    char buffer[BUFFUR_SIZE + 1];
    char *tmp = NULL;

    while (1)
    {
        ssize_t fd_num = read(fd, buffer, BUFFUR_SIZE);
        if (fd_num == -1 || BUFFUR_SIZE < 0 || fd_num == 0)
        {
            free(holder);
            return NULL;
        }

        buffer[fd_num] = '\0';

        if (find_new_line(buffer) == 1)
        {
            holder = ft_strjoin(holder, buffer);
            tmp = holder;
            holder = ft_strdup(strchr(holder, '\n') + 1);
            return tmp;
        }
        else
        {
            holder = ft_strjoin(holder, buffer);
        }
    }

    return tmp;
}


#include <fcntl.h>
#include <stdio.h>

int main()
{
    int fd = open("txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s\n", line);
        free(line);  // Don't forget to free the line after using it
    }

    close(fd);
	while(1);

}
