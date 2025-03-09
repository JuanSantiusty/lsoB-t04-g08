#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

#include "listar.h"

int main(int argc,char *ruta[],char *patron[]) {
    struct dirent *ent;

    /**
     * @brief Validacion, si el programa recibe un numero de argumentos distinto de 3 finaliza la ejecución
     */
    
    if (argc != 3) {
		fprintf(stderr, "Debe especificar:./listar <nombre_dir> <patron_arch> \n");
		exit(EXIT_FAILURE);
	}
    
    /**
     * @brief Validación, verificar si el directorio existe
     */

    if (es_directorio(ruta[1])==1) {
      printf("Si es un directorio");
    }else{
      printf("No es un directorio");
      exit(EXIT_FAILURE);
    }

     DIR *dir = opendir(".");  /* Abre el directorio actual*/
    

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
