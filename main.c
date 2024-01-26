#include <stdio.h>
#include <fcntl.h>   // for open
#include <unistd.h>  // for close
#include <stdlib.h>
#include <string.h>

void stc()
{
    static char *tgf;
    char *text;
    tgf = malloc(7);

    text  = "laster";
    tgf = text;
    text = "dsds";
    free(tgf);
    printf("%s-\n", tgf);
    printf("%s\n", text);
}


int main()
{
    stc();
}
