#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(int argc, char * argv[]) {
    struct dirent *ent;
    DIR *dir = opendir(".");  /* Abre el directorio actual*/
    
    if (argc != 2) {
		fprintf(stderr, "Debe especificar:./listar <nombre_dir>\n");
		exit(EXIT_FAILURE);
	}

    if (dir == NULL) {
        perror("No se pudo abrir el directorio");
        return 1;
    }

    while ((ent = readdir(dir)) != NULL) {
        printf("Nombre de la entrada: %s\n", ent->d_name);
    }

    closedir(dir);
    return 0;
}  
