#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

/* SUGESTÂO: utilize as páginas do manual para conhecer mais sobre as funções usadas:
  man opendir
  man readdir
*/
#define MAX_PATH 1024

void listDir(char dirname[])
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
            //printf("%s" , dent->d_type == DT_DIR ? "d " : "  ");   
            if(dent->d_type == DT_DIR){
                char path[MAX_PATH];
                snprintf(path, MAX_PATH, "%s/%s", dirname, dent->d_name);
                printf("d %s\n",path);
                listDir(path);
            }
            else{
                printf("  %s/%s\n",dirname,dent->d_name);
            }
        } 
    }
    closedir(dp);
    
}

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        fprintf(stderr,"Usage: %s base_directory\n",argv[0]);
        return EXIT_FAILURE;
    }

    listDir(argv[1]);
    
    return EXIT_SUCCESS;
}

