/*
 ============================================================================
 Name        : TP2.c
 Author      : Pardo Roberto
 Version     :
 Copyright   : Pardo Roberto ABM TP2
 Description : ABM
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include "ArrayEmployees.h"
#include "utn.h"
#include "rPardo.h"

#define TAM_LISTA 999
#define TAM_NOMBRE 51
#define TAM_APELLIDO 51
#define ASC 1
#define DES 0

int main(void) {

	setbuf(stdout,NULL);

	Employee lista[TAM_LISTA];
	int nextId = 0;
	char nombre[TAM_NOMBRE];
	char apellido[TAM_APELLIDO];
	float salario;
	int sector;
	char salir = 'n';
	char continuarOpciones;
	int flagMenu = 0;


	if(initEmployees(lista, TAM_LISTA) == -1){
	        printf("Hubo algun problema al inializar \n");
	}
	else{
		printf("Inicializacion exitosa \n");
	}

	do{
	   system("cls");
	   switch(menu()){
	   	   case 1:
	   		   continuarOpciones = opcionConfirmar("Continuar con el Alta? s/n ", "Error, vuelva a intentarlo. Continuar con el Alta? s/n ");
	   		   if(continuarOpciones == 's'){
				   if(cargaDatosEmpleados(nombre, apellido, &salario, &sector, TAM_NOMBRE, TAM_APELLIDO)){
					   nextId++;
				   }

	   			   addEmployees(lista, TAM_LISTA, nextId, nombre, apellido, salario, sector);

	               printf("Alta exitosa\n");

	               flagMenu = 1;
	           }
	           else{
	   			   printf("No se pudo realizar el alta\n");
	           }
	           break;

	       case 2:
	    	   if(flagMenu){
				   printEmployees(lista, TAM_LISTA);
				   if(!modificarEmpleado(lista, TAM_LISTA)){
					   printf("No se pudo realizar la modificacion \n");
				   }
				   else{
					   printf("Modificacion exitosa \n");
				   }
	    	   }
	    	   else{
	    		   printf("Antes tiene que dar de alta al menos un empleado. \n");
	    	   }
	           break;

	       case 3:
	    	   if(flagMenu){
				   printEmployees(lista, TAM_LISTA);
				   if(!removeEmployee(lista, TAM_LISTA, nextId)){
					   printf("No se pudo realizar la baja \n");
				   }
				   else{
					   printf("Baja exitosa\n");
				   }
	    	   }
	    	   else{
	    		   printf("Antes tiene que dar de alta al menos un empleado. \n");
	    	   }
	    	   break;

	       case 4:
	    	   if(flagMenu){
	    	   	   ordenaEmpleados(lista, TAM_LISTA);
	    	   }
	    	   else{
	    		   printf("Antes tiene que dar de alta al menos un empleado. \n");
	    	   }
	    	   break;

	       case 5:
	    	   salir = opcionConfirmar("Seguro que quiere salir? s/n ", "Error, vuelva a intentarlo. Salir? s/n ");
	           break;
	       default:
	           printf("Opacion invalida. Intente nuevamente. \n");
	   }

	   system("pause");
	}while(salir == 'n');

	return EXIT_SUCCESS;
}
