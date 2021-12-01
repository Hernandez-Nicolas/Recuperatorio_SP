#ifndef EDITORIALES_H_
#define EDITORIALES_H_
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ERROR -1
#define LEN 51

typedef struct{
	int idEditorial;
	char nombre[LEN];
}eEditorial;

eEditorial* Editoriales_newEditorial(void);
/** \brief Reserva espacio en memoria para un nuevo editorial
 *
 * \return Retorna un puntero al nuevo editorial
 *
 */

eEditorial* Editoriales_newParam(char* idEditorialStr, char* nombreStr);
/** \brief Crea un nuevo editorial e inicializa sus campos
 *
 * \param char* idEditorialStr	Pasa una cadena con el idEditorial
 * \param char* nombreStr		Pasa una cadena con el nombre
 * \return Retorna un puntero al nuevo editorial con sus campos inicializados
 *
 */

int Editoriales_delete(eEditorial* editorial);
/** \brief Libera el espacio en memoria del editorial
 *
 * \param eEditorial* editorial		Pasa el puntero al editorial
 * \return Retorna ERROR en caso de error o 0 en caso de exito
 *
 */

int Editoriales_setIdEditorial(eEditorial* editorial, int idEditorial);
/** \brief Reemplaza un antiguo idEditorial por el pasadopor valor
 *
 * \param eEditorial* editorial		Pasa el puntero al editorial
 * \param int idEditorial			Pasa por valor el nuevo idEditorial
 * \return Retorna ERROR en caso de error o 0 en caso de exito
 *
 */

int Editoriales_getIdEditorial(eEditorial* editorial, int* idEditorial);
/** \brief Pasa una variable por referencia para obtener el idEditorial del editorial
 *
 * \param eEditorial* editorial		Pasa el puntero al editorial
 * \param	int* idEditorial		Pasa una variable por referencia para obtener el idEditorial
 * \return Retorna ERROR en caso de error o 0 en caso de exito
 *
 */

int Editoriales_setNombre(eEditorial* editorial, char* nombre);
/** \brief Reemplaza un antiguo nombre por el pasado como parametro
 *
 * \param eEditorial* editorial		Pasa el puntero al editorial
 * \param char* nombre				Pasa una cadena con el nombre
 * \return Retorna ERROR en caso de error o 0 en caso de exito
 *
 */

int Editoriales_getNombre(eEditorial* editorial, char* nombre);
/** \brief Pasa una cadena en donde se copiara el nombre del editorial
 *
 * \param eEditorial* editorial		Pasa el puntero al editorial
 * \param char* nombre				Pasa una cadena para obtener el nombre del editorial
 * \return Retorna ERROR en caso de error o 0 en caso de exito
 *
 */

#endif /* EDITORIALES_H_ */
