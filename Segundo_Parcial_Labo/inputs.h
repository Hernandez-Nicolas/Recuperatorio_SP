#ifndef INPUTS_H_
#define INPUTS_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int inputs_entero(char[],int,int);
/*
 * Resumen: Ingresa y devuelve un entero validado en cierto rango
 * param char[]		Ingresa un mensaje a mostrar
 * param int		ingresa el minimo del rango a validar
 * param int		ingresa el maximo del rango a validar
 */

long int inputs_enteroLargo(char[],long int,long int);
/*
 * Resumen: Ingresa y devuelve un entero validado en cierto rango
 * param char[]		Ingresa un mensaje a mostrar
 * param long int	ingresa el minimo del rango a validar
 * param long int	ingresa el maximo del rango a validar
 */

float inputs_flotante(char[],float,float);
/*
 * Resumen: Ingresa y devuelve un flotante validado en cierto rango
 * param char[]		Ingresa un mensaje a mostrar
 * param float		ingresa el minimo del rango a validar
 * param float		ingresa el maximo del rango a validar
 */

void inputs_cadena(char[],char[],int);
/*
 * Resumen:	Ingresa un mensaje, una cadena de caracteres y la longitud de la misma
 * 			para escribir y validar la longitud de un mensaje en dicha cadena.
 * param1 char[]	Ingresa un mensaje a mostrar.
 * param2 char[]	cadena de caracteres a la cual se le ingresara texto por teclado
 * param3 int		longitud de la cadena de caracteres, la cual se usara para validadr que lo escrito este dentro del rango
 */

void inputs_nombre(char[],char[],int);
/*
 * Resumen	Ingresa un mensaje, una cadena de caracteres y la longitud de la misma
 * 			para escribir un mensaje y validar la longitud, que solo contenga letras o espacios
 * 			y pasar el mensaje a minusculas transformando solo la pocicion 0 de la cadena
 * 			y la primera letra luego de cada espacio.
 * param1 char[]	ingresa un mensaje a mostrar.
 * param2 char[]	cadena de caracteres a la cual se le ingresara texto por teclado.
 * param3 int		longitud maxima de la cadena de caracteres.
 */

#endif /* INPUTS_H_ */
