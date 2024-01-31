
#include "get_next_line.h"
#include <stdio.h>

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
    int fd1 = open("txt", O_RDONLY);
	// char *ln = get_next_line(fd1);
	printf("%s",  get_next_line(fd1));
	// printf("%s",  get_next_line(fd1));
	// printf("%s",  get_next_line(fd1));
	// free(ln);
	close(fd1);

    // int fd = open("txt", O_RDONLY);
	// char *ln1 = get_next_line(fd);
	// printf("%s", ln);
	// free(ln1);
	// close(fd);

	printf("\n");
	while (1);
 }