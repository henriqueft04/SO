#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{

    int tamanho = argc * sizeof(argv);
    char letras[tamanho];
    char texto[tamanho];
    int count = 0;
    
    for(int i = 1 ; i < argc ; i++){
        for (int j = 0 ; argv[i][j] != '\0' ; j++){
            letras[count++] = argv[i][j];
        }

    }

    strcpy(texto, letras);
    printf("%s\n", texto);


    return EXIT_SUCCESS;
}