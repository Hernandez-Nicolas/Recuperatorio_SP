#ifndef LIBROS_H_
#define LIBROS_H_
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define LEN 51
#define ERROR -1

typedef struct{
	int id;
	char titulo[LEN];
	char autor[LEN];
	float precio;
	int idEditorial;
}eLibro;

eLibro* Libros_newLibro(void);
/** \brief Reserva espacio en memoria para un nuevo libro
 *
 * \return Retorna un puntero al nuevo libro o NULL en caso de no haber encontrado espacio
 *
 */

eLibro* Libros_newParam(char* idStr, char* tituloStr, char* autorStr, char* precioStr, char* idEditorialStr);
/** \brief Crea un nuevo libro e inicializa sus campos desde strings pasados como parametros
 *
 * \param char* idStr	Cadena que contiene el id
 * \param char* tituloStr	Cadena que contiene el titulo
 * \param char* autorStr	Cadena que contiene el autor
 * \param char* precioStr	Cadena que contiene el precio
 * \param char* idEditorial	Cadena que contiene el idEditorial
 * \return Retorna el nuevo con todos sus campos inicializados
 *
 */

int Liros_delete(eLibro* libro);
/** \brief Libera el espacio en memoria del libro
 *
 * \param eLibro* libro		Pasa el puntero a al libro a eliminar
 * \return Retorna ERROR en caso de error o 0 en caso de exito
 *
 */

int Libros_setId(eLibro* libro, int id);
/** \brief Reemplaza un antiguo id por el pasado por valor
 *
 * \param eLibro* libro		Pasa el puntero al libro
 * \param int id			Pasa el nuevo id
 * \return Retorna ERROR en caso de error o 0 en caso de exito
 *
 */

int Libros_getId(eLibro* libro, int* id);
/** \brief Se pasa una variable por referencia para obtener el id del libro
 *
 * \param eLibro* libro		Pasa el puntero al libro
 * \param int* id			Pasa la variable donde se guardara el id
 * \return Retorna ERROR en caso de error o 0 en caso de exito
 *
 */

int Libros_setTitulo(eLibro* libro, char* titulo);
/** \brief Pasa una cadena que se guardara en su respectivo campo en el libro
 *
 * \param eLibro* libro		Pasa el puntero al libro
 * \param char* titulo		Pasa la cadena con el titulo
 * \return Retorna ERROR en caso de error o 0 en caso de exito
 *
 */

int Libros_getTitulo(eLibro* libro, char* titulo);
/** \brief Pasa una cadena en la que copiara el titulo del libro
 *
 * \param eLibro* libro		Pasa el puntero al libro
 * \param char* titulo		Pasa una cadena en la que copiar el titulo
 * \return Retorna ERROR en caso de error o 0 en caso de exito
 *
 */

int Libros_setAutor(eLibro* libro, char* autor);
/** \brief Pasa una cadena que se guardara en su respectivo campo en el libro
 *
 * \param eLibro* libro		Pasa el puntero al libro
 * \param char* autor		Pasa una cadena con el autor
 * \return Retorna ERROR en caso de error o 0 en caso de exito
 *
 */

int Libros_getAutor(eLibro* libro, char* autor);
/** \brief Pasa una cadena en la que copiara el autor del libro
 *
 * \param eLibro* libro		Pasa el puntero al libro
 * \param char* autor		Pasa una cadena en la que copiar el autor
 * \return Retorna ERROR en caso de error o 0 en caso de exito
 *
 */

int Libros_setPrecio(eLibro* libro, float precio);
/** \brief Reemplaza un antiguo precio por el pasado por valor
 *
 * \param eLibro* libro		Pasa el puntero al libro
 * \param float precio		Pasa por valor el nevo precio
 * \return Retorna ERROR en caso de error o 0 en caso de exito
 *
 */

int Libros_getPrecio(eLibro* libro, float* precio);
/** \brief Pasa una variable por referencia para obtener el precio del libro
 *
 * \param eLibro* libro		Pasa el puntero al libro
 * \param float* precio		Pasa una variable por referencia para obtener el precio
 * \return Retorna ERROR en caso de error o 0 en caso de exito
 *
 */

int Libros_setIdEditorial(eLibro* libro, int idEditoral);
/** \brief Reemplaza un antiguo idEditorial por el pasado por valor
 *
 * \param eLibro* libro		Pasa el puntero al libro
 * \param int idEditorial	Pasa por valor el nuevo idEditorial
 * \return Retorna ERROR en caso de error o 0 en caso de exito
 *
 */

int Libros_getIdEditorial(eLibro* libro, int* idEditorial);
/** \brief Pasa una variable por referencia para obtener el idEditorial del libro
 *
 * \param eLibro* libro		Pasa el puntero al libro
 * \param int* idEditorial	Pasa una variable por referencia para obtener el valor de idEditorial
 * \return Retorna ERROR en caso de error o 0 en caso de exito
 *
 */

int Libros_compararAutor(void* primero, void* segundo);

#endif /* LIBROS_H_ */
