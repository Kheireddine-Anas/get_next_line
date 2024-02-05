#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

int ft_strlen(const char *str) {
    int i = 0;
    while (str && str[i])
        i++;
    return i;
}

char *ft_strjoin(char *s1, const char *s2) {
    if (!s1)
        s1 = "";

    size_t len_s1 = ft_strlen(s1);
    size_t len_s2 = ft_strlen(s2);

    char *new_str = malloc(len_s1 + len_s2 + 1);
    if (!new_str)
        return NULL;

    for (size_t i = 0; i < len_s1; i++)
        new_str[i] = s1[i];

    for (size_t i = 0; i < len_s2; i++)
        new_str[len_s1 + i] = s2[i];

    new_str[len_s1 + len_s2] = '\0';

    free(s1);
    return new_str;
}

char *find_newline_pos(const char *str, char newline) {
    if (!str)
        return NULL;

    while (*str && *str != newline)
        str++;

    return (char *)str;
}

char *get_next_line(int fd) {
    static char *holder = NULL;
    char buffer[BUFFER_SIZE + 1];
    ssize_t readed;

    while ((readed = read(fd, buffer, BUFFER_SIZE)) > 0) {
        buffer[readed] = '\0';
        holder = ft_strjoin(holder, buffer);

        char *newline_pos = find_newline_pos(holder, '\n');
        if (holder && *newline_pos)
            break;
    }

    if (readed == 0 && holder && *holder) {
        // The end of the file is reached, return the remaining content
        char *line = holder;
        holder = NULL;
        return line;
    }

    if (readed <= 0 || !holder)
        return NULL;

    char *newline_pos = find_newline_pos(holder, '\n');
    char *line = ft_strjoin(NULL, newline_pos);

    // Skip the newline character
    if (*newline_pos == '\n')
        holder = ft_strjoin(NULL, newline_pos + 1);
    else
        holder = NULL;

    return line;
}

int main() {
    int fd = open("txt", O_RDONLY);
    if (fd < 0) {
        perror("Error opening file");
        return 1;
    }

    char *line;
    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);
        free(line);
    }

    close(fd);
    return 0;
}
