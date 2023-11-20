#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if(argc != 4){
        printf("%s","Argumentos errados Ó BÓI\n");
        return EXIT_FAILURE;

    }

    //double primeiro = atof(argv[1]);
    //double segundo = atof(argv[3]);
    char *ptr;

    double primeiro = strtod(argv[1], &ptr);
    double segundo = strtod(argv[3], &ptr);
    if (argv[2][0] == '+'){
        printf("%f + %f = %f", segundo, primeiro, segundo+primeiro);
    }
    else if (argv[2][0] == '-'){
        printf("%f - %f = %f", segundo, primeiro, segundo-primeiro);

    }
    else if(argv[2][0] == 'x'){
        printf("%f * %f = %f", segundo, primeiro, segundo*primeiro);
    }
    else if(argv[2][0] == '/'){
        if(segundo != 0){
            printf("%f / %f= %f", segundo, primeiro, segundo/primeiro);
        }
        else{
            printf("Division by zero is not allowed.\n");
            return EXIT_FAILURE;
        }
    }
    else if(argv[2][0] == 'p'){
        printf("%.3lf ^ %.3lf = %.3lf \n", primeiro, segundo, pow(primeiro,segundo));
    }
    else{
        printf("%c is a shit operator \n", argv[2][0]);
    }

    return EXIT_SUCCESS;
}