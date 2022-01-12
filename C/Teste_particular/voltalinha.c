#include <stdio.h>

int main()//int argc, char* argv[]
{
    while(1)
    {
        printf("***********");
        fflush(stdout);
        sleep(1);
        printf("\r");
        printf("...........");
        fflush(stdout);
        sleep(1);
        printf("\r");
    }

    return 0;
}