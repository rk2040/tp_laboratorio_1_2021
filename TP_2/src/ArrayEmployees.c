/*
 * ArrayEmployees.c
 *
 *  Created on: 11 oct. 2021
 *      Author: Roberto Pardo
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include<string.h>
#include <conio.h>
#include "ArrayEmployees.h"
#include "utn.h"
#include "rPardo.h"


int menu(){
    int opcion;
    //system("cls");
    printf("\n\n        *** ABM Empleados ***        \n\n");
    printf("1- Altas \n");
    printf("2- Modificar \n");
    printf("3- Baja \n");
    printf("4- Informar \n");
    printf("5- Salir \n");
    scanf("%d", &opcion);

    return opcion;
}



// inicializa
int initEmployees(Employee* list, int len){
	int estado = -1;

	    if(list != NULL && len > 0){
	        for(int i=0; i<len; i++){
	            list[i].isEmpty = 1;
	        }
	        estado = 0;
	    }

	return estado;
}

//-------------------------------------------------------------------------------------------------------------
// Busco la primer posicion id libre
int freeId(Employee* list, int len){
    int indice = -1;

    if(list != NULL && len > 0){
        for(int i=0; i<len; i++){
            if(list[i].isEmpty == 1){
            	indice = i;
            	break;
            }
        }
    }

    return indice;
}


//-------------------------------------------------------------------------------------------------------------
// Cargo los datos del empleado
int cargaDatosEmpleados(char* nombre, char* apellido, float* salario, int* sector, int tamNombre, int tamApellido){
	int todoOk = 0;

	if(nombre != NULL && apellido != NULL && salario != NULL && sector != NULL /*&& tamNombre > 0 && tamApellido > 0*/){

		if(utn_getCadena(nombre, tamNombre, "Ingrese nombre del empleado: ", "Error. Ingrese nombre nuevamente.", 4) &&
				utn_getCadena(apellido, tamApellido, "Ingrese apellido del empleado: ", "Error. Ingrese apellido nuevamente.", 4) &&
				utn_getNumeroFloat(salario, "Ingrese salario: ", "Error. Ingrese salario nuevamente.", 0, 999999999, 4) &&
				utn_getNumero(sector, "Ingrese sector: 1 - 10: ", "Error. Ingrese sector nuevamente.", 1, 10, 4))
		{
			while(!esNombreValido(nombre, tamNombre)){
				printf("\nError al ingresar %s. Solo puede ingresar letras.\n", nombre);
				utn_getCadena(nombre, tamNombre, "Ingrese nombre del empleado: ", "Error. Ingrese nombre nuevamente.", 4);
			}
			while(!esNombreValido(apellido, tamApellido)){
				printf("\nError al ingresar %s. Solo puede ingresar letras.\n", apellido);
				utn_getCadena(apellido, tamApellido, "Ingrese nombre del empleado: ", "Error. Ingrese nombre nuevamente.", 4);
			}
			formatoInicialMayuscula(nombre);
			formatoInicialMayuscula(apellido);

			todoOk = 1;
		}
	}
	return todoOk;
}



// Alta empleado
int addEmployees(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector){
	int estado = -1;
	int indice;

	if(list != NULL && len > 0 && id > 0 && name != NULL && lastName != NULL /*&& salary > 0 && sector > 0*/){
		// busco cual es la primer posicion libre
		indice = freeId(list, len);

		//system("cls");

			if(indice == -1){
				printf("No hay espacio disponible \n");
	        }
			else{
				list[indice].id = id;
				strcpy(list[indice].name, name);
				strcpy(list[indice].lastName, lastName);
				list[indice].salary = salary;
				list[indice].sector = sector;
				list[indice].isEmpty = 0;

			    estado = 0;
			}
	}

	return estado;
}

//-------------------------------------------------------------------------------------------------------------
// Busca empleado por id
int findEmployeeById(Employee* list, int len, int id){
	int indice = -1;

	    if(list != NULL && len > 0){
	        for(int i=0; i<len; i++){
	            if(list[i].id == id && list[i].isEmpty == 0){
	            	indice = i;
	                break;
	            }
	        }
	    }

	return indice;
}



int menuModificarPersona(){
    int opcion;

    printf("        *** Modificar Empleado ***        \n\n");
    printf("1- Nombre Empleado \n");
    printf("2- Apellido Empleado \n");
    printf("3- Salario Empleado \n");
    printf("4- Sector Empleado \n");
    printf("5- Volver \n");
    scanf("%d", &opcion);

    return opcion;
}

// Modificar empleado
int modificarEmpleado(Employee* list, int len){
    int todoOk = 0;
    int indice;
    int id;
    char confirma;

    if(list != NULL && len > 0){
        printf("        *** Modificar Empleado ***        \n\n");
        printf("Ingrese Id: ");
        scanf("%d", &id);


        indice = findEmployeeById(list, len, id);

        if(indice == -1){   // -1 era lo que devolvia la funcion findEmployeeById cuando no encontraba el id en el sistema
            printf("No se encuentra el Id %d en el sistema \n", id);
        }
        else{
        	printAnEmployee(list[indice]);

            switch(menuModificarPersona()){
                case 1:
                    printf("Desea modificar el nombre? s/n ");
                    fflush(stdin);
                    scanf("%c", &confirma);
                    if(confirma == 's'){
                        printf("Ingrese el nuevo nombre: ");
                        fflush(stdin);
                        gets(list[indice].name);
                        todoOk = 1;
                        confirma = 'n';
                    }
                    else{
                        printf("\nModificacion cancelada por el usuario \n");
                    }
                    break;

                case 2:
                    printf("Desea modificar el apellido? s/n ");
                    fflush(stdin);
                    scanf("%c", &confirma);
                    if(confirma == 's'){
                        printf("Ingrese el nuevo apellido: ");
                        fflush(stdin);
                        gets(list[indice].lastName);
                        todoOk = 1;
                        confirma = 'n';
                    }
                    else{
                        printf("\nModificacion cancelada por el usuario \n");
                    }
                    break;

                case 3:
                    printf("Desea modificar el salario? s/n ");
                    fflush(stdin);
                    scanf("%c", &confirma);
                    if(confirma == 's'){
                        printf("Ingrese el nuevo salario: ");
                        scanf("%f", &list[indice].salary);
                        todoOk = 1;
                        confirma = 'n';
                    }
                    else{
                        printf("\nModificacion cancelada por el usuario \n");
                    }
                    break;

                case 4:
                    printf("Desea modificar el sector? s/n ");
                    fflush(stdin);
                    scanf("%c", &confirma);
                    if(confirma == 's'){
                        printf("Ingrese el nuevo sector: ");
                        fflush(stdin);
                        scanf("%d", &list[indice].sector);
                        todoOk = 1;
                        confirma = 'n';
                    }
                    else{
                        printf("\nModificacion cancelada por el usuario \n");
                    }
                    break;

                case 5:
                    break;
                default:
                    printf("Operacion invalida. Intente nuevamente. \n");
            }
        }
    }
    return todoOk;
}


//-------------------------------------------------------------------------------------------------------------
int removeEmployee(Employee* list, int len, int id){
    int todoOk = 0;
    int indice;
    //int id;
    char confirma;

    if(list != NULL && len > 0){
        printf("        *** Baja Empleado ***        \n\n");
        printf("Ingrese Id: ");
        scanf("%d", &id);

        //printEmployees(list, len);

        indice = findEmployeeById(list, len, id);

        if(indice == -1){   // -1 era lo que devolvia la funcion findEmployeeById cuando no encontraba el id en el sistema
            printf("\nNo se encuentra el Id %d en el sistema \n", id);
        }
        else{
        	printAnEmployee(list[indice]);
            confirma = opcionConfirmar("Confirma Baja? s/n ", "Error, vuelva a intentar. Confirma Baja? s/n ");
            if(confirma == 's'){
                list[indice].isEmpty = 1;
                todoOk = 1;
            }
            else{
                printf("\nBaja cancelada por el usuario \n");
            }

        }
    }
    return todoOk;
}



//-------------------------------------------------------------------------------------------------------------
int menuOrdenar(){
    int opcion;

    printf("        *** Ordenar Lista ***        \n\n");
    printf("1- Listado de empleados ordenados alfabéticamente por Apellido y Sector.\n");
    printf("2- Total y promedio de salarios, y cuántos empleados superan el salario promedio. \n");
    printf("3- Lista original. Ordenados por Id. \n");
    printf("4- Volver \n");
    scanf("%d", &opcion);

    return opcion;
}




int ordenaEmpleados(Employee* list, int len){
	int todoOk = 0;
	int criterio;

	if(list != NULL && len > 0){
		switch(menuOrdenar()){
			case 1:
				printf("Ascendente: 1. \nDescendente: 0. ");
				scanf("%d", &criterio);
				if(criterio == 1){
					sortEmployees(list, len, criterio);	// 1 orden ascendente
					printEmployees(list, len);
				}
				else{
					sortEmployees(list, len, criterio);	// 0 orden descendente
					printEmployees(list, len);
				}
				break;

			case 2:
				promedioEmpleados(list, len);
				break;

			case 3:
				ordenPorId(list, len);
				printEmployees(list, len);
				break;

			case 4:
				break;

			default:
				printf("Opcion invalida. Intente nuevamente. \n");
				break;
			}
			todoOk = 1;
	}
	return todoOk;
}




int ordenPorId(Employee* list, int len){
	int todoOk = 0;
	Employee auxEmpleado;

	if(list != NULL && len > 0){
		for(int i=0; i<len-1; i++){

			for(int j=i+1; j<len; j++){
				if(list[i].id > list[j].id)
				{
					auxEmpleado = list[i];
					list[i] = list[j];
					list[j] = auxEmpleado;
				}
			}
		}
			todoOk = 1;
	}
	return todoOk;
}


// ordenamiento del array
int sortEmployees(Employee* list, int len, int order){
	int todoOk =-1;
	Employee auxEmpleado;
	//int auxInt;
	//char auxCad[51];
	//float auxFloat;

	if(list != NULL && len > 0){
		for(int i=0; i<len-1; i++){

			for(int j=i+1; j<len; j++){
				if((order && list[i].sector == list[j].sector &&
							 strcmp(list[i].lastName, list[j].lastName) == 1) ||
							(list[i].sector != list[j].sector &&
							 list[i].sector > list[j].sector))
				{
					auxEmpleado = list[i];
					list[i] = list[j];
					list[j] = auxEmpleado;
				/*	auxInt = list[i].id;
					list[i].id = list[j].id;
					list[j].id = auxInt;

                    strcpy(auxCad, list[i].name);
                    strcpy(list[i].name, list[j].name);
                    strcpy(list[j].name, auxCad);

                    strcpy(auxCad, list[i].lastName);
                    strcpy(list[i].lastName, list[j].lastName);
                    strcpy(list[j].lastName, auxCad);

                    auxFloat = list[i].salary;
                    list[i].salary = list[j].salary;
                    list[j].salary = auxFloat;

					auxInt = list[i].sector;
					list[i].sector = list[j].sector;
					list[j].sector = auxInt;*/
				}
				else if((!order && list[i].sector == list[j].sector &&
						 strcmp(list[i].lastName, list[j].lastName) == -1) ||
						(list[i].sector != list[j].sector &&
						 list[i].sector > list[j].sector))
				{
					auxEmpleado = list[i];
					list[i] = list[j];
					list[j] = auxEmpleado;
				/*
					auxInt = list[i].id;
					list[i].id = list[j].id;
					list[j].id = auxInt;

				   strcpy(auxCad, list[i].name);
				   strcpy(list[i].name, list[j].name);
				   strcpy(list[j].name, auxCad);

				   strcpy(auxCad, list[i].lastName);
				   strcpy(list[i].lastName, list[j].lastName);
				   strcpy(list[j].lastName, auxCad);

				   auxFloat = list[i].salary;
				   list[i].salary = list[j].salary;
				   list[j].salary = auxFloat;

					auxInt = list[i].sector;
					list[i].sector = list[j].sector;
					list[j].sector = auxInt;*/
				}
			}
		}
		todoOk = 1;
	}
	return todoOk;
}






//-------------------------------------------------------------------------------------------------------------
// muestra un solo empleado, para usar en la funcion que muestra a todos los empleados
void printAnEmployee(Employee new){

    printf(" %d	  %-20s	%-20s %10.2f		%02d \n",
    	new.id,
		new.name,
		new.lastName,
		new.salary,
		new.sector
		);
}




int printEmployees(Employee* list, int length){
    int todoOk = 0;
    int flag = 1;

    if(list != NULL && length > 0){
        system("cls");
        printf("\n             	--- Lista de Empleados ---           \n");
        printf(" ============================================================================\n");
        printf("  Id      Nombre      		Apellido    		Salario       Sector \n");
        printf(" ============================================================================\n");
        for(int i=0; i<length; i++){
            if(list[i].isEmpty==0){
            	printAnEmployee(list[i]);
                flag = 0;
            }
        }
        if(flag){
            printf(" No hay empleados para mostrar \n");
        }
        todoOk = 1;
    }
    return todoOk;
}




int promedioEmpleados(Employee* list, int length){
    int todoOk = 0;
    int flag = 0;
    int totalEmpleados = 0;
    int superaPromedio = 0;
    float totalSalarios = 0;
    float promedio;


    if(list != NULL && length > 0){
        //system("cls");
        printf("\n             			--- Lista de Empleados ---           \n");
        printf(" ===============================================================================\n");
        printf(" Total salarios     Promedio salarios     Superan promedio 	Total empleados \n");
        printf(" ===============================================================================\n");
        for(int i=0; i<length; i++){
            if(list[i].isEmpty==0){
            	totalEmpleados++;
            	totalSalarios = totalSalarios + list[i].salary;

                flag = 1;
            }
        }
        promedio = (float) totalSalarios / totalEmpleados;

        for(int i=0; i<length; i++){
            if(list[i].isEmpty==0 && list[i].salary > promedio){
                superaPromedio++;
            }
        }

        if(flag){
        	printf("   %10.2f         %10.2f	       %3d   		    %3d \n", totalSalarios, promedio, superaPromedio, totalEmpleados);
        }
        else{
            printf(" No hay empleados para mostrar \n");
        }
        todoOk = 1;
    }
    return todoOk;
}
