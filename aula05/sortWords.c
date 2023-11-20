#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int compareString(const void *s1, const void *s2){

    return strcasecmp(*(const char **) s1, *(const char **) s2);
}

int main(int argc, char **argv){
  
    char *sort = getenv("SORTORDER");
    
    if (argc > 2){

        int descending = sort && strcmp(sort, "DESC") == 0;

        char *words[argc - 1];
        int index = 0;

        for(int i = 1 ; i < argc ; i++){
            if (argv[i][0] != '\0' && isalpha(argv[i][0])){
                words[index++] = argv[i];
            }
        }

        qsort(words, index, sizeof(char *), compareString);

        if (descending){
            for (int i = index-1 ; i >= 0  ; i--){
                printf("%s\n", words[i]);
            }
        }
        else{
            for (int i = 0 ; i < index ; i++){
                printf("%s\n", words[i]);
            }
        }
    }
    else{
        printf("%s","Fui NECA, errei os argumentos lixei-me com f1\n");
    }

    return 0;
}