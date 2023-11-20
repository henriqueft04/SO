#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <getopt.h>

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
    int option_index = 0;
    struct option long_options[] = {
                {   "file",       no_argument, 0,  'f'  },
                {    "dir",       no_argument, 0,  'd' },
                {    "ext",       no_argument, 0,  'e'  },
                {        0,                 0, 0,  0  }
    };
    
    while((opt = getopt_long(argc, argv, "fde:", long_options, &option_index)) != -1 ){

        switch(opt){
            case 0:
                break;
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

