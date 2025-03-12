#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <limits.h>
#include "listar.h"

/**
 *@brief Funcion que verifica si un directorio existe
 *@param ruta cadena de texto con la ruta del directorio
 *@return 1 si el directorio existe o 0 si no existe
*/

int es_directorio(char ruta[]){
  struct stat s;
  int resultado=stat(ruta,&s);
  if (resultado<0){
    perror("stat");
    return 0;
  }

  if (S_ISDIR(s.st_mode)){
    return 1;
  }else{
    return 0;
  }
}

/**
 * @brief Realiza una búsqueda recursiva de archivos que contengan el patrón en su nombre.
 * @param directorio Directorio base desde donde iniciar la búsqueda.
 * @param patron Cadena de texto que debe estar contenida en el nombre del archivo.
 * @return 0 si la búsqueda se realizó correctamente, -1 en caso de error.
 */

int buscar(char directorio[], char patron[]){
    DIR *dir = opendir(directorio);
    if (!dir) {
        perror("opendir");
        return -1;
    }

    struct dirent *ent;
    char ruta_completa[PATH_MAX];
    int se_encontro_algo = 0;  // Para saber si encontramos al menos un archivo

    while ((ent = readdir(dir)) != NULL) {
        // Saltar entradas especiales "." y ".."
        if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0)
            continue;

        // Construir la ruta completa para la entrada
        snprintf(ruta_completa, sizeof(ruta_completa), "%s/%s", directorio, ent->d_name);

        // Si la entrada es un directorio, llamamos recursivamente
        if (es_directorio(ruta_completa)) {
            int resultado_subdir = buscar(ruta_completa, patron);
            if (resultado_subdir == 1) {
                se_encontro_algo = 1;
            }
            // Si hay error (-1), podrías manejarlo aquí, pero continuamos
        }

        // Verificar si el nombre del archivo contiene el patrón
        if (strstr(ent->d_name, patron) != NULL) {
            se_encontro_algo = 1;
            // Mostrar la ruta absoluta
            char ruta_abs[PATH_MAX];
            if (realpath(ruta_completa, ruta_abs) != NULL) {
                printf("Encontrado: %s\n", ruta_abs);
            } else {
                printf("Encontrado: %s\n", ruta_completa);
            }
        }
    }

    closedir(dir);
    return se_encontro_algo;
}

