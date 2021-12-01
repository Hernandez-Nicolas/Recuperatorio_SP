#ifndef CONTROLADOR_H_
#define CONTROLADOR_H_
#include<stdio.h>
#include<stdlib.h>
#include"inputs.h"
#include"Editoriales.h"
#include"LinkedList.h"
#include"Libros.h"
#include"Parser.h"

int Controlador_leerEditoriales(char* nombreArchivo, eLinkedList* editoriales);

int Controlador_leerLibros(char* nombreArchivo, eLinkedList* editoriales);

int Controlador_maximoIdEditoriales(eLinkedList* lista);

int Controlador_maximoIdLibros(eLinkedList* lista);

int Controlador_altaEditorial(eLinkedList* listaEditoriales,int* idEditorial);

int Controlador_altaLibro(eLinkedList* libros, eLinkedList* editorial, int* idLibros);

int Controlador_ordenar(eLinkedList* libros,int orden);

int Controlador_mostrarEditoriales(eLinkedList* lista);

int Controlador_mostrarLibros(eLinkedList* lista, eLinkedList* editoriales);

eLinkedList* Controlador_listaFiltrado(eLinkedList* lista, int (*pFunc)(void*));

int Controlador_buscarMinotauro(void* libros);

int Controlador_buscarPearson(void* libro);

eLinkedList* Controlador_listaDescontada(eLinkedList* lista);

int Controlador_descontar(void* libros);

eLinkedList* Controlador_mayores(eLinkedList* lista, int* contador);

eLinkedList* Controlador_sumaPearson(eLinkedList* lista, float* suma);

int Controlador_guardarLibros(char* nombreArchivo, eLinkedList* libros);

int Controlador_guardarEditoriales(char* nombreArchivo, eLinkedList* editoriales);

#endif /* CONTROLADOR_H_ */
