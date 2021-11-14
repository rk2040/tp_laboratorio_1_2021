/*
 * parser.h
 *
 *  Created on: 10 nov. 2021
 *      Author: Roberto i3
 */

#ifndef PARSER_H_
#define PARSER_H_



#endif /* PARSER_H_ */


/** \brief Transforma los datos del archivo de empleados data.csva modo texto
 * \param pFile ruta al archiv data.csv
 * \param pArrayListEmployee puntero al array de empleados donde van los dat
 * \return devuelve 0 si salio ok -1 si salio mal
 */

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);

/** \brief Transforma los datos del archivo de empleados databin.csv modo binario
 * \param pFile ruta al archiv databin.csv
 * \param pArrayListEmployee puntero al array de empleados donde van los datos
 * \return devuelve 0 si salio ok -1 si salio mal
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);
