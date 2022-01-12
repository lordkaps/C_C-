#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){
    srand(time(NULL));

    int randon = rand() % 4;

    printf("%d", randon+1); 
}