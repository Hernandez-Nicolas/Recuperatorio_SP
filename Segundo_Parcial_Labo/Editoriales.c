#include"Editoriales.h"

eEditorial* Editoriales_newEditorial(void){
	eEditorial* editorial;
	editorial=(eEditorial*)malloc(sizeof(eEditorial));
	return editorial;
}

eEditorial* Editoriales_newParam(char* idEditorialStr, char* nombreStr){
	eEditorial* editorial;
	int idEditorial;
	char nombre[LEN];
	editorial=Editoriales_newEditorial();
	if(editorial!=NULL&&idEditorialStr!=NULL&&nombreStr!=NULL){
		idEditorial=atoi(idEditorialStr);
		strcpy(nombre,nombreStr);
		Editoriales_setIdEditorial(editorial,idEditorial);
		Editoriales_setNombre(editorial,nombre);
	}
	return editorial;
}

int Editoriales_delete(eEditorial* editorial){
	int retorno;
	retorno=ERROR;
	if(editorial!=NULL){
		free(editorial);
		retorno=0;
	}
	return retorno;
}

int Editoriales_setIdEditorial(eEditorial* editorial, int idEditorial){
	int retorno;
	retorno=ERROR;
	if(editorial!=NULL){
		editorial->idEditorial=idEditorial;
		retorno=0;
	}
	return retorno;
}

int Editoriales_getIdEditorial(eEditorial* editorial, int* idEditorial){
	int retorno;
	retorno=ERROR;
	if(editorial!=NULL&&idEditorial!=NULL){
		*idEditorial=editorial->idEditorial;
		retorno=0;
	}
	return retorno;
}

int Editoriales_setNombre(eEditorial* editorial, char* nombre){
	int retorno;
	retorno=ERROR;
	if(editorial!=NULL&&nombre!=NULL){
		strcpy(editorial->nombre,nombre);
		retorno=0;
	}
	return retorno;
}

int Editoriales_getNombre(eEditorial* editorial, char* nombre){
	int retorno;
	retorno=ERROR;
	if(editorial!=NULL&&nombre!=NULL){
		strcpy(nombre,editorial->nombre);
		retorno=0;
	}
	return retorno;
}
