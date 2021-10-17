/*
 * ArrayEmployees.h
 *
 *  Created on: 11 oct. 2021
 *      Author: Roberto Pardo
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_


typedef struct{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;    // 1 esta vacio, 0 esta lleno
}Employee;

#endif /* ARRAYEMPLOYEES_H_ */



/** \brief print the menu
*
*\return int Return opcion elegida 1 altas, 2 modificar, 3 baja, 4 informar, 5 salir
*
*/
int menu();



/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initEmployees(Employee* list, int len);



/** \brief To search for the first free position,
* this function finds a free position (if there is any) and assigns that position as id
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] or position ID if Ok
*
*/
int freeId(Employee* list, int len);



int cargaDatosEmpleados(char* nombre, char* apellido, float* salario, int* sector, int tamNombre, int tamApellido);


/** \brief add in a existing list of employees the values received as parameters
* in the first empty position
* \param list employee*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*
*/
int addEmployees(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector);



/** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*
*/
int findEmployeeById(Employee* list, int len, int id);




/** \brief print the menu modificar
*

* \return int Return opcion elegida 1 modificar nombre, 2 modificar apellido, 3 modificar salario, 4 modificar sector, 5 volver
*
*/
int menuModificarPersona();




/** \brief Modify a Employee by Id
*
* \param list Employee*
* \param len int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/
int modificarEmpleado(Employee* list, int len);



/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/
int removeEmployee(Employee* list, int len, int id);



int menuOrdenar();


int ordenaEmpleados(Employee* list, int len);


int ordenPorId(Employee* list, int len);


/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
*
* \param list Employee*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployees(Employee* list, int len, int order);



/** \brief print the content of employees array
*
* \param list Employee*
* \param length int
* \return int
*
*/
int printEmployees(Employee* list, int length);



/** \brief print the content an employee
*
* \param an Employee
*
*/
void printAnEmployee(Employee new);


int promedioEmpleados(Employee* list, int length);
