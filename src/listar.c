#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

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

int buscar(char directorio[],char patron[]){
  return 0;
}

