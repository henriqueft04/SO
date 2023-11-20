#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int certo = rand()%100;
    int tentativas = 0;
    int guess;

    while (1) {

        printf("%s","Adivinha aí o número boi: ");
        scanf("%d", &guess);
        tentativas++;
        if (guess > certo){
            printf("O número é mais baixo\n");
        }
        else if (guess < certo){
            printf("O número é mais alto\n");
        }
        else{
            printf("Ganda burro, demoraste %d tentativas LOL\n", tentativas);
            break;
        }
    }

   return EXIT_SUCCESS; 
}

