#include"Parser.h"

int Parser_editoriales(FILE* archivo, eLinkedList* editoriales){
	eEditorial* newEditorial;
	int retorno;
	char idEditorial[LEN];
	char nombre[LEN];
	retorno=ERROR;
	if(archivo!=NULL&&editoriales!=NULL){
		fscanf(archivo,"%[^,],%[^\n]\n",idEditorial,nombre);
		newEditorial=Editoriales_newParam(idEditorial,nombre);
		Ll_add(editoriales,(eEditorial*)newEditorial);
		while(!feof(archivo)){
			fscanf(archivo,"%[^,],%[^\n]\n",idEditorial,nombre);
			newEditorial=Editoriales_newParam(idEditorial,nombre);
			Ll_add(editoriales,(eEditorial*)newEditorial);
			if(feof(archivo)){
				break;
			}
		}
		retorno=0;
	}
	return retorno;
}

int Parser_libros(FILE* archivo, eLinkedList* libros){
	eLibro* newLibro;
	int retorno;
	char id[LEN];
	char titulo[LEN];
	char autor[LEN];
	char precio[LEN];
	char idEditorial[LEN];
	retorno=ERROR;
	if(archivo!=NULL&&libros!=NULL){
		fscanf(archivo,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,titulo,autor,precio,idEditorial);
		newLibro=Libros_newParam(id,titulo,autor,precio,idEditorial);
		Ll_add(libros,(eLibro*)newLibro);
		while(!feof(archivo)){
			fscanf(archivo,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,titulo,autor,precio,idEditorial);
			newLibro=Libros_newParam(id,titulo,autor,precio,idEditorial);
			Ll_add(libros,(eLibro*)newLibro);
			if(feof(archivo)){
				break;
			}
		}
		retorno=0;
	}
	return retorno;
}
