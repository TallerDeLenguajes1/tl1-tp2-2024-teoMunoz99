#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct{
int velocidad;//entre 1 y 3 GHz
int anio;//entre 2015 y 2023
int cantidad;//entre 1 y 8
char *tipo_cpu; //valores del arreglo tipos
}Compu;

char tipos[6][10]={"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};

void listarPc(Compu arreglo[], int tama);
void listarPc(Compu arreglo[], int tama){
    for (int i = 0; i < tama; i++)
    {
        printf("Procesador: %s \n", arreglo[i].tipo_cpu);
        printf("Velocidad: %d Ghz\n", arreglo[i].velocidad);
        printf("Nucleos: %d \n", arreglo[i].cantidad);
        printf("Anio: %d \n", arreglo[i].anio);
        printf("---------------\n");
    }
    
}

void listarPcMasVieja(Compu arreglo[], int tama);
void listarPcMasVieja(Compu arreglo[], int tama){
    //guardo en aux el anio de la primer pc del arreglo
    int aux = arreglo[0].anio, indice = 0;
    for (int i = 0; i < tama; i++)
    {
        if(arreglo[i].anio < aux){
            aux = arreglo[i].anio;
            indice = i;
        }
    }
    printf("--Listar pc mas antigua\n");
    printf("Procesador: %s \n", arreglo[indice].tipo_cpu);
    printf("Velocidad: %d Ghz\n", arreglo[indice].velocidad);
    printf("Nucleos: %d \n", arreglo[indice].cantidad);
    printf("Anio: %d \n", arreglo[indice].anio);
    printf("---------------\n");
}

int main(){
    srand(time(NULL));
    //declaro el arreglo con 5 lugares
    Compu computadoras[5];

    //carga de datos aleatorios para el arreglo de pc
    for (int i = 0; i < 5; i++)
    {
        //genero los numeros random y los guardo donde van
        computadoras[i].velocidad = 1 + rand() % 3;
        computadoras[i].anio = rand() % 10 + 2015;
        computadoras[i].cantidad = 1 + rand() % 8;
        //para cargar el nombre del procesador, primero doy el tamaño del elemento del arreglo al puntero de la estrucura donde
        //se va a guardar ese nombre, sumandole 1 para el caracter de fin de cadena \0
        computadoras[i].tipo_cpu = (char *)malloc(1 + strlen(tipos[i]) * sizeof(char));
        //ahora copio el nombre del procesador en el puntero, uso la funcion strcpy(cadena_destino, cadena_origen);
        strcpy(computadoras[i].tipo_cpu, tipos[i]);
    }

    listarPc(computadoras, 5);
    listarPcMasVieja(computadoras, 5);
    
    return 0;
}