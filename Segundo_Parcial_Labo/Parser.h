#ifndef PARSER_H_
#define PARSER_H_
#include"Libros.h"
#include"LinkedList.h"
#include"Editoriales.h"

#define ERROR -1

int Parser_editoriales(FILE* archivo, eLinkedList* editoriales);

int Parser_libros(FILE* archivo, eLinkedList* libros);

#endif /* PARSER_H_ */
