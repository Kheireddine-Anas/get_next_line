#include <stdio.h>
#include <fcntl.h>   // for open
#include <unistd.h>  // for close
#include <stdlib.h>
#include <string.h>


#ifndef BUFFER_SIZE
#define BUFFER_SIZE 5
#endif

int find_new_line(char *str)
{
    int i;

    i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}


int main()
{
    static char *line = NULL;
    char *plc = "NULL\n";
    printf("%d", find_new_line(plc));
    plc = malloc(sizeof(char) * BUFFER_SIZE + 1);
    if (!plc)
        return (free(plc), 0);
    int fd = open("txt",O_RDONLY);
    if (fd == -1)
    {
        return (free(plc), 0);
    }
    static int che7al = 1;
    while(che7al != 0)
    {
        int i;

        i = 0;
        che7al = read(fd, plc, BUFFER_SIZE);
        if (find_new_line(plc) == 1)
        {
            while (plc[i])
            {
                if (plc[i] == '\n')
                {

                }
            }
            
        }
        plc[che7al] = '\0';
        printf("%s", plc);
        printf("%d", che7al);
    }
    return 0;
}
