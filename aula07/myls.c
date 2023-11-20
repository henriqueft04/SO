#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/* SUGESTÂO: utilize as páginas do manual para conhecer mais sobre as funções usadas:
  man opendir
  man readdir
*/
#define MAX_PATH 1000000

void listDir(char dirname[], int option)
{
    DIR *dp; 
    struct dirent *dent;

    dp = opendir(dirname); 
    if(dp == NULL)
    {
        perror("Error opening directory");
        return;
    }

    while((dent = readdir(dp)) !=NULL) 
    {
        if(dent->d_name[0] != '.'){
            
            if(option == 2 && dent->d_type == DT_DIR){
                char path[MAX_PATH];
                snprintf(path, MAX_PATH, "%s/%s", dirname, dent->d_name);
                printf(" %s\n",path);
                listDir(path, option);
            }
            if(option == 1 && dent->d_type == DT_REG){
                printf(" %s\n", dent->d_name);
            }
            if(option == 3){
                char *ext = strrchr(dent->d_name, '.');
                if(ext != NULL && strcmp(ext, ".c") == 0){
                    printf(" %s\n", dent->d_name);
                }
            }
        } 
    }
    closedir(dp);
    
}

int main(int argc, char *argv[])
{

    int opt;

    if(argc != 3)
    {
        fprintf(stderr,"Usage: %s base_directory\n",argv[0]);
        return EXIT_FAILURE;
    }
    
    while((opt = getopt(argc, argv, "fde:")) != -1 ){

        switch(opt){
            case 'f':
                printf("---------YOu chose to see files------------\n");
                listDir(argv[1], 1);
                break;
            case 'd':
                printf("-----------------You chose to see directories-----------------\n");
                listDir(argv[1], 2);
                break;
            case 'e':
                printf("e\n");
                listDir(argv[1], 3);
                break;
            default:
                printf("default\n");
                break;
        }
    }

    
    return EXIT_SUCCESS;
}

