#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

typedef struct
{
    int age;
    double height;
    char name[64];
} Person;

void printPersonInfo(Person *p)
{
    printf("Person: %s, %d, %f\n", p->name, p->age, p->height);
}

int main (int argc, char *argv[])
{
    /* Validate number of arguments */
    if(argc != 2)
    {
        printf("USAGE: %s fileName\n", argv[0]);
        return EXIT_FAILURE;
    }

    int n;

    printf("How many people do you want?: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++){
        FILE *fp = NULL;
        Person p;

        printf("New person\n Enter the name of the person: ");
        scanf("%s", p.name);
        printf(" Enter the age of the person: ");
        scanf("%d", &(p.age));
        printf(" Enter the height of the person: ");
        scanf("%lf", &(p.height));
        printf("\n");

        /* Open the file provided as argument */
        errno = 0;
        fp = fopen(argv[1], "ab");
        if(fp == NULL)
        {
            perror ("Error opening file!");
            return EXIT_FAILURE;
        }

        fwrite(&p, sizeof(Person), 1, fp);
    

        fclose(fp);
    }
    printf("-----------------END OF FILE-----------------\n");

    return EXIT_SUCCESS;
}
