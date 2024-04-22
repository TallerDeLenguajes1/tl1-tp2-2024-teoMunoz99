#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
int velocidad;//entre 1 y 3 GHz
int anio;//entre 2015 y 2023
int cantidad;//entre 1 y 8
char *tipo_cpu; //valores del arreglo tipos
}Compu;

char tipos[6][10]={"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};

int main(){
    Compu computadoras[5];

    //carga de datos aleatorios para el arreglo de pc
    for (int i = 0; i < 5; i++)
    {
        //genero los numeros random y los guardo donde van
        computadoras[i].velocidad = 1 + rand() % 3;
        computadoras[i].anio = 2015 + rand() % 2024;
        computadoras[i].cantidad = 1 + rand() % 8;
        //para cargar el nombre del procesador, primero doy el tamaño del elemento del arreglo al puntero de la estrucura donde
        //se va a guardar ese nombre, sumandole 1 para el caracter de fin de cadena \0
        computadoras[i].tipo_cpu = (char *)malloc(1 + strlen(tipos[i]) * sizeof(char));
        //ahora copio el nombre del procesador en el puntero, uso la funcion strcpy(cadena_destino, cadena_origen);
        strcpy(computadoras[i].tipo_cpu, tipos[i]);
    }
    
    return 0;
}