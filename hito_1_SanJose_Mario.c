#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main(int argc, char **argv){
    // -- VARIABLES DEL HITO 1 -- //

    char *path = "./procesa";
    char *comando = "procesa";
    char *arg1 = argv[1]; // fichero de entrada
    char *arg2 = argv[2]; // fichero de salida
    int estado; // estado del hijo 
    __pid_t pid; 
    int salida; // codigo de salida del exit del hijo

    // -------------------------- //

    // comprobamos que el numero de argumentos es correcto
    if(argc != 3){
        fprintf(stderr,"Argumentos incorrectos. Se necesitan 3 parametros para ejecutar el hito 1\n");
        exit(1);
    } 

    // creamos un hijo
    pid = fork();
    if(pid == -1){
        printf("Error al crear el hijo\n");
        exit(1);
    }

    // el hijo ejecuta el prgrama procesa
    if(pid == 0){
        if((execl(path,comando,arg1,arg2,NULL)) == -1){  
            fprintf(stdout,"Error en execl\n");
            exit(1);
        }

    // esperamos a que termine el hijo y comprobamos su salida    
    } else {
        wait(&estado);
        if(WIFEXITED(estado)){
            salida = WEXITSTATUS(estado);
            if(salida == 0){
                fprintf(stdout,"main : Procesado de fichero terminado\n");
            } else {
                fprintf(stderr,"main : Procesado de fichero con error\n");
            }
        } else {
            fprintf(stderr,"main : Proceso hijo finalizó con errores\n");
        }
        
    }

}