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
      printf("Si es un directorio\n");
    }else{
      printf("No es un directorio\n");
      exit(EXIT_FAILURE);
    }
    
    int resultado = buscar(ruta[1], ruta[2]);

    if (resultado == -1) {
        // Ocurrió un error en la búsqueda
        fprintf(stderr, "Ocurrió un error buscando en %s\n", ruta[1]);
        return EXIT_FAILURE;
    } else if (resultado == 0) {
        // No se encontraron archivos que contengan el patrón
        printf("No hay archivos con el nombre especificado.\n");
    }

    return EXIT_SUCCESS;
    
    return 0;
}  
