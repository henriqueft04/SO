#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int ret;

    printf("Antes do fork: PID = %d, PPID = %d\n", getpid(), getppid());
    if ((ret = fork()) < 0) { 
        perror("erro na duplicação do processo");
        return EXIT_FAILURE;
    }

    if (ret > 0) sleep(1);
    printf("Quem sou eu?\nApós o fork: PID = %s %d , PPID = %d, retorno do fork = %d\n", ret ? "Pai" : "Filho", getpid(), getppid(), ret);

    return EXIT_SUCCESS;
}
