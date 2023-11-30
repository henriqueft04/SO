#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char *argv[]){
    char fras[] = "Portugal venceu Espanha";
    printf("%ld\n", sizeof(fras));

    int port = atoi(argv[1]);
    int esp = atoi(argv[2]);
    char *idk = argv[0];

    printf("Portugal: %d\n", port);
    printf("Espanha: %d\n", esp);
    printf("idk: %s*\n", idk);
    
    for (int i=1; i<argc; i++){
        printf("argv[%d] = %s\n", i, argv[i]);
    }

    return 0;
}