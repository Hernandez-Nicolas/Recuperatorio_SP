#include"Libros.h"

eLibro* Libros_newLibro(void){
	eLibro* newLibro;
	newLibro=(eLibro*)malloc(sizeof(eLibro));
	return newLibro;
}

eLibro* Libros_newParam(char* idStr, char* tituloStr, char* autorStr, char* precioStr, char* idEditorialStr){
	eLibro* libro;
	int id;
	char titulo[LEN];
	char autor[LEN];
	float precio;
	int idEditorial;
	libro=Libros_newLibro();
	if(libro!=NULL&&idStr!=NULL&&tituloStr!=NULL&&autorStr!=NULL&&precioStr!=NULL&&idEditorialStr!=NULL){
		id=atoi(idStr);
		strcpy(titulo,tituloStr);
		strcpy(autor,autorStr);
		precio=atof(precioStr);
		idEditorial=atoi(idEditorialStr);
		Libros_setId(libro,id);
		Libros_setTitulo(libro,titulo);
		Libros_setAutor(libro,autor);
		Libros_setPrecio(libro,precio);
		Libros_setIdEditorial(libro,idEditorial);
	}
	return libro;

}

int Libros_delete(eLibro* libro){
	int retorno;
	retorno=ERROR;
	if(libro!=NULL){
		free(libro);
		retorno=0;
	}
	return retorno;
}

int Libros_setId(eLibro* libro, int id){
	int retorno;
	retorno=ERROR;
	if(libro!=NULL&&id>0){
		libro->id=id;
		retorno=0;
	}
	return retorno;
}

int Libros_getId(eLibro* libro, int* id){
	int retorno;
	retorno=ERROR;
	if(libro!=NULL&&id!=NULL){
		*id=libro->id;
		retorno=0;
	}
	return retorno;
}

int Libros_setTitulo(eLibro* libro, char* titulo){
	int retorno;
	retorno=ERROR;
	if(libro!=NULL&&titulo!=NULL){
		strcpy(libro->titulo,titulo);
		retorno=0;
	}
	return retorno;
}

int Libros_getTitulo(eLibro* libro, char* titulo){
	int retorno;
	retorno=ERROR;
	if(libro!=NULL&&titulo!=NULL){
		strcpy(titulo,libro->titulo);
		retorno=0;
	}
	return retorno;
}

int Libros_setAutor(eLibro* libro, char* autor){
	int retorno;
	retorno=ERROR;
	if(libro!=NULL&&autor!=NULL){
		strcpy(libro->autor,autor);
		retorno=0;
	}
	return retorno;
}

int Libros_getAutor(eLibro* libro, char* autor){
	int retorno;
	retorno=ERROR;
	if(libro!=NULL&&autor!=NULL){
		strcpy(autor,libro->autor);
		retorno=0;
	}
	return retorno;
}

int Libros_setPrecio(eLibro* libro, float precio){
	int retorno;
	retorno=ERROR;
	if(libro!=NULL){
		libro->precio=precio;
		retorno=0;
	}
	return retorno;
}

int Libros_getPrecio(eLibro* libro, float* precio){
	int retorno;
	retorno=ERROR;
	if(libro!=NULL&&precio!=NULL){
		*precio=libro->precio;
		retorno=0;
	}
	return retorno;
}

int Libros_setIdEditorial(eLibro* libro, int idEditorial){
	int retorno;
	retorno=ERROR;
	if(libro!=NULL){
		libro->idEditorial=idEditorial;
		retorno=0;
	}
	return retorno;
}

int Libros_getIdEditorial(eLibro* libro, int* idEditorial){
	int retorno;
	retorno=ERROR;
	if(libro!=NULL&&idEditorial!=NULL){
		*idEditorial=libro->idEditorial;
		retorno=0;
	}
	return retorno;
}

int Libros_compararAutor(void* primero, void* segundo){
	int retorno;
	char autor1[LEN];
	char autor2[LEN];
	retorno=ERROR;{
		if(primero!=NULL&&segundo!=NULL){
			Libros_getAutor(primero,autor1);
			Libros_getAutor(segundo,autor2);
			retorno=strcmp(autor1,autor2);
		}
	}
	return retorno;
}
