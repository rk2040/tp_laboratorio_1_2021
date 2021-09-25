/*
 ============================================================================
 Name        : TP1.c
 Author      : Pardo Roberto
 Version     :
 Copyright   : utnFra 1G
 Description : TP1 Calculadora
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "pardoTp1.h"

int main()
{
	setbuf(stdout,NULL);

    int numA = 0;
    int numB = 0;
    int resultados;
    int flagOpcion = 0;
    float resultadoDiv;
    unsigned long int resultadoFact;
    char salir = 'n';



    do{
        system("cls");

        switch(menu(numA, numB))
        {
            case 1:
            	if(flagOpcion == 0)
            	{
					printf("Ingrese el primer numero: ");
					fflush(stdin);
					scanf("%d", &numA);
					flagOpcion = 1;
            	}
            	else{
            		printf("Antes tiene que terminar todas las operaciones para volver a empezar o salir.\n");
            	}
                break;

            case 2:
            	if(flagOpcion == 1)
            	{
					printf("Ingrese el segundo numero: ");
					fflush(stdin);
					scanf("%d", &numB);
					flagOpcion = 2;
            	}
            	else{
            		printf("Antes tiene que ingresar el primer operando o salir.\n");
            	}
            	break;

            case 3:
            	if(flagOpcion == 2)
            	{
					printf("a) Calcular la suma (%d + %d)\n", numA, numB);
					printf("b) Calcular la resta (%d - %d)\n", numA, numB);
					printf("d) Calcular la division (%d / %d)\n", numA, numB);
					printf("c) Calcular la multiplicacion (%d * %d)\n", numA, numB);
					printf("e) Calcular el factorial (%d! y %d!)\n", numA, numB);
					flagOpcion = 3;
            	}
            	else{
            		printf("Antes tiene que ingresar ambos operandos o salir.\n");
            	}
            	break;

            case 4:
            	if(flagOpcion == 3)
            	{
					if(suma(numA, numB, &resultados)){
						printf("El resultado de %d + %d es: %d \n", numA, numB, resultados);
					}
					else{
						printf("No se pudo realizar la suma.\n");
					}

					if(resta(numA, numB, &resultados)){
						printf("El resultado de %d - %d es: %d \n", numA, numB, resultados);
					}
					else{
						printf("No se pudo realizar la resta. \n");
					}


					if(division(numA, numB, &resultadoDiv)){
						printf("El resultado de %d / %d es: %.2f \n", numA, numB, resultadoDiv);
					}
					else{
						printf("Error. El divisor debe ser distinto de 0. \n");
					}


					if(multiplicacion(numA, numB, &resultados)){
						printf("El resultado de %d * %d es: %d \n", numA, numB, resultados);
					}
					else{
						printf("No se pudo realizar la division. El divisor debe ser distinto de 0. \n");
					}


					if(factorial(numA, &resultadoFact) && numA <=12){
						        printf("El factorial de %d ! es: %lu.\n", numA, resultadoFact);
						    }
						    else
						    {
						    	if(numA < 0){
						    		printf("Error %d!. FACTORIAL < 0 no es posible calcular.\n", numA);
						    	}
						    	else{
						    		printf("Error %d!. FACTORIAL > 12! pierde precision.\n", numA);
						    	}
					}
					if(factorial(numB, &resultadoFact) && numB <=12){
						        printf("El factorial de %d! es: %lu\n", numB, resultadoFact);
						    }
						    else
						    {
						    	if(numB < 0){
									printf("Error %d!. FACTORIAL < 0 no es posible calcular.\n", numB);
						    	}
						    	else{
						    		printf("Error %d!. FACTORIAL > 12! pierde precision.\n", numB);
						    	}
					}
					numA = 0;
					numB = 0;
					flagOpcion = 0;
            	}
            	else{
            		printf("Antes tienen que mostrar las operaciones o salir.\n");
            	}
                break;

            case 5:
                printf("Seguro que quiere salir? s/n ");
                fflush(stdin);
                scanf("%c", &salir);
                salir = tolower(salir);
                while(salir != 's' && salir != 'n')
                {
                    printf("Error, vuelva a intentarlo. Salir? s/n ");
                    fflush(stdin);
                    scanf("%c", &salir);
                    salir = tolower(salir);
                }
                break;

            default:
                printf("Opcion invalida. Intente nuevamente.");
        }

        system("pause");


    }while(salir == 'n');



    return 0;
}
