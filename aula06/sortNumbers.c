#include <stdio.h>
#include <stdlib.h>

/* SUGESTÂO: utilize as páginas do manual para conhecer mais sobre as funções usadas:
 man qsort
*/

#define LINEMAX 10

int compareInts(const void *px1, const void *px2)
{
    int x1 = *((int *)px1);
    int x2 = *((int *)px2);
    return(x1 < x2 ? -1 : x1 == x2 ? 0 : 1);
}

int main(int argc, char *argv[])
{

    FILE *fp = NULL;
    char line[LINEMAX];

    fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        perror("Error opening file!");
        return EXIT_FAILURE;
    }

    int i,numSize;
    int index = 0;
    int *numbers;
    char *str = NULL;
    
    

    while( fgets(line, sizeof(line), fp) != NULL ){
        numSize++;
    }
    
    numbers = (int *) malloc(sizeof(int) * numSize);
    rewind(fp);

    /* Memory allocation for all the numbers in the arguments */
    

    /* Storing the arguments in the "array" numbers */
    while( fgets(line, sizeof(line), fp) != NULL ){
        numbers[index++] = strtod(line, &str);
    }

    /* void qsort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *)); 
         The qsort() function sorts an array with nmemb elements of size size.*/
    qsort(numbers, numSize, sizeof(int), compareInts);

    /* Printing the sorted numbers */

    printf("Sorted numbers: \n");
    for(i = 0 ; i < numSize ; i++)
    {
        printf("%d\n", numbers[i]);
    }
    fclose(fp);

    return EXIT_SUCCESS;
}
