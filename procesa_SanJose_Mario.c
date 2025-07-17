#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>


bool es_numerico(char str[]){
    for(int i=0; str[i] != '\0';i++){
        if (!isdigit(str[i])  && str[i] != '\n') 
        return false;
    }

    return true;
}

int main(int argc, char **argv){
char *linea = NULL;
size_t espacio = 0;
FILE *entrada;
FILE *salida;
ssize_t i; //numero de caracteres por linea

    if (argc !=3){
        fprintf(stderr,"ERROR: NUMERO INCORRECTO DE ARGUMENTOS\n");
        return 1;
    }

    salida = fopen(argv[2],"r");
    if(salida != NULL){
        fprintf(stderr,"ERROR: EL FICHERO DE %s YA EXISTE\n",argv[2]);  
        exit(1);
    }

    entrada = fopen(argv[1],"r");
    if(entrada == NULL){
        fprintf(stderr,"ERROR AL ABRIR EL FICHERO %s\n",argv[1]);
        exit(1);
    }

    salida = fopen(argv[2],"w");
    if(salida == NULL){
        fprintf(stderr,"ERROR AL CREAR EL ARCHIVO %s \n",argv[2]);  
        fclose(entrada);
        exit(1);
    }

    while((i = getline(&linea, &espacio,entrada)) !=-1){
        if(es_numerico(linea)){
            fprintf(salida,"%s",linea);
        }
    }

    free(linea);
    fclose(entrada);
    fclose(salida);

    printf("Procesa : Procesado el fichero %s Resultado escrito en %s.\n",argv[1],argv[2]); 
    return 0;
}

