
#include "get_next_line.h"
#include <stdio.h>
#include <string.h>
int main()
{
    // int fd = open("txt", O_RDONLY);
    // char *line1 = get_next_line(fd);
//     printf("%s", line1);


//     char *line2 = get_next_line(fd);
//     printf("%s", line2);
	
//     char *line3 = get_next_line(fd);
//     printf("%s", line3);
	
//     char *line4 = get_next_line(fd);
//     printf("%s", line4);
//     char *line5 = get_next_line(fd);
//     printf("%s", line5);
	// printf("%s", get_next_line(fd));
	// free(get_next_line(fd));
	// close(fd);
    int fd1 = open("empty", O_RDONLY);
	// char ln[4];
	// static char *holder1;
	// int rd = read(fd1, ln, 3);
	// free(holder1);
	// printf("%s",  holder1);
	// holder1 = "333";
	// printf("%s", holder1);
	// if (ln[0] == '\0')
	// {
	// 	printf("%d", ft_strlen(holder1));
	// }
	// get_next_line(fd1);
	char *cdf = get_next_line(fd1);
	printf("%s",  cdf);
	free(cdf);
	// printf("%s",  get_next_line(fd1));
	// printf("%s",  get_next_line(fd1));
	// printf("%s",  get_next_line(fd1));
	// printf("%s",  get_next_line(fd1));
	while(1);
	// printf("%s",  get_next_line(fd1));
	// printf("%s",  get_next_line(fd1));
	// free(ln);


    // int fd = open("txt", O_RDONLY);
	// char *ln1 = get_next_line(fd);
	// printf("%s", ln);
	// free(ln1);
	// close(fd);
	// while(1);
	printf("####\n");
	// while (1);
 }


// #include <unistd.h>

// void wdmatch(char *s1, char *s2)
// {
// 	int len = 0;
// 	int i = 0;

// 	while(s1[len])
// 		len++;
// 	while (*s2 && i < len)
// 		if (*s2++ == s1[i])
// 			i++;
// 	if (i == len)
// 		write(1, s1, len);
// }

// int main(int ac, char **av)
// {
// 	if (ac ==3)
// 		wdmatch(av[1], av[2]);
// 	write(1, "\n", 1);
	
// }