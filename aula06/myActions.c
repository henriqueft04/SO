#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[])
{
    char text[1024];
    FILE *log=fopen("command.log", "a");
    if (log ==NULL){
        perror("Error opening the file!\n");
        return EXIT_FAILURE;
    }

    do
    {
        printf( "Command: ");
        scanf("%1023[^\n]%*c", text);

        if(strcmp(text, "end") != 0) {
            fprintf(log,"\n * Command to be executed: %s\n", text);
            
            system(text);
            char date[100];
            
            FILE *dateF = popen("date '+%Y-%m-%d %H:%M:%S'", "r");
            if (dateF == NULL){
                perror("Error executing date command!\n");
                return 1;
            }
            fgets(date, sizeof(date), dateF);
            pclose(dateF);
            
            date[strcspn(date, "\n")] = '\0';

            fprintf(log, "%s, %s\n ", date, text);
            fprintf(log,"---------------------------------\n");
        }
    } while(strcmp(text, "end"));
    fclose(log);

    printf("-----------The End---------------\n");
    
    return EXIT_SUCCESS;
}
