#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

/* SUGESTÂO: utilize as páginas do manual para conhecer mais sobre as funções usadas:
 man fopen
 man fgets
*/

#define LINEMAXSIZE 800 /* or other suitable maximum line size */


int main(int argc, char *argv[]){

    FILE *fp = NULL;
    char line [LINEMAXSIZE]; 

    /* Open the file provided as argument */
    for (int i = 1; i < argc; i++){
        printf("File: %s\n", argv[i]);
        int count = 1;
        errno = 0;
        fp = fopen(argv[i], "r");
        if( fp == NULL )
        {
            perror ("Error opening file!");
            return EXIT_FAILURE;
        }

        /* Read all the lines of the file */
        while( fgets(line, sizeof(line), fp) != NULL )
        {
            printf("-> %d %s",count++, line); /* not needed to add '\n' to printf because fgets will read the '\n' that ends each line in the file */
        }
        printf("\n ------------Next OUPAAAAAA------------\n");

        fclose(fp);

    }

    return EXIT_SUCCESS;
}
