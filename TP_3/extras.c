/*
 * extras.c
 *
 *  Created on: 10 nov. 2021
 *      Author: Roberto i3
 */

#include <stdio.h>
#include <stdlib.h>

#include "extras.h"
#include "utn.h"


int menu(){
    int opcion;

    printf("--- Menu de Opciones ---\n\n");
    printf("1 Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n");
    printf("2 Cargar los datos de los empleados desde el archivo data.bin (modo binario)\n");
    printf("3 Alta de empleado\n");
    printf("4 Modificar datos de empleado\n");
    printf("5 Baja de empleado\n");
    printf("6 Listar empleados\n");
    printf("7 Ordenar empleados\n");
    printf("8 Guardar los datos de los empleados en el archivo data.csv (modo texto)\n");
    printf("9 Guardar los datos de los empleados en el archivo data.bin (modo binario)\n");
    printf("10 Finalizar programa\n\n");
    utn_getNumero(&opcion, "Elija una opcion: ", "\nError. ", 1, 10, 4);

    return opcion;
}

