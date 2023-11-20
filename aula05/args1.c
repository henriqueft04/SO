#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if(argc != 3){
        printf("%s","Insufficient arguments \n");
        return EXIT_FAILURE;

    }

    for(int i = 0 ; i < argc ; i++)
    {
        printf("Argument %02d: \"%s\"\n", i, argv[i]);        
    }

    return EXIT_SUCCESS;
}