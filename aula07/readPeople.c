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
    printf("Person: %s, %d, %.2f\n", p->name, p->age, p->height);
}

int main (int argc, char *argv[])
{
    Person peopleArray[100];
    FILE *fp = NULL;
    Person p;
    int index = 0;

    /* Validate number of arguments */
    if(argc != 2)
    {
        printf("USAGE: %s fileName\n", argv[0]);
        return EXIT_FAILURE;
    }

    /* Open the file provided as argument */
    errno = 0;
    fp = fopen(argv[1], "r");
    if(fp == NULL)
    {
        perror ("Error opening file!");
        return EXIT_FAILURE;
    }

    /* read all the itens of the file */
    while(fread(&p, sizeof(Person), 1, fp) == 1)
    {
        peopleArray[index++] = p;
        printPersonInfo(&p);
    }
    fclose(fp);

    printf("Do you want to add more people? (y/n): ");
    char answer;
    scanf(" %c", &answer);
    switch(answer){
        case 'y':
            printf("How many people do you want?: ");
            int n;
            scanf("%d", &n);
            fp = fopen(argv[1], "wb");
            for (int i = 0; i < n; i++){
                Person p;
                printf("New person\n Enter the name of the person: ");
                scanf("%s", p.name);
                printf(" Enter the age of the person: ");
                scanf("%d", &(p.age));
                printf(" Enter the height of the person: ");
                scanf("%lf", &(p.height));
                printf("\n");
                peopleArray[index++] = p;
            }
            break;
        case 'n':
            printf("Ok, bye!\n");
            break;
    }
    for (int i = 0; i < index; i++){
        fwrite(&peopleArray[i], sizeof(Person), 1, fp);
    }

    fclose(fp);

    printf("-----------------END OF FILE-----------------\n");

    return EXIT_SUCCESS;
}
