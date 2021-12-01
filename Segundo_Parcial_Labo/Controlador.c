#include"Controlador.h"

int Controlador_leerEditoriales(char* nombreArchivo, eLinkedList* editoriales){
	FILE* archivo;
	int retorno;
	retorno=ERROR;
	if(editoriales!=NULL&&nombreArchivo!=NULL){
		archivo=fopen(nombreArchivo,"r");
		if(archivo!=NULL){
			retorno=Parser_editoriales(archivo,editoriales);
		}
		fclose(archivo);
	}
	return retorno;
}

int Controlador_leerLibros(char* nombreArchivo, eLinkedList* libro){
	FILE* archivo;
	int retorno;
	retorno=ERROR;
	if(libro!=NULL&&nombreArchivo!=NULL){
		archivo=fopen(nombreArchivo,"r");
		if(archivo!=NULL){
			retorno=Parser_libros(archivo,libro);
		}
		fclose(archivo);
	}
	return retorno;
}

int Controlador_maximoIdEditoriales(eLinkedList* lista){
	eEditorial* editorial;
	int id;
	int maximo;
	int pocicion;
	int retorno;
	maximo=0;
	retorno=ERROR;
	if(lista!=NULL){
		pocicion=Ll_len(lista);
		for(int i=0;i<pocicion;i++){
			editorial=(eEditorial*)Ll_get(lista,i);
			Editoriales_getIdEditorial(editorial,&id);
			if(id>maximo){
				maximo=id;
			}
		}
		retorno=maximo;
	}
	return retorno;
}

int Controlador_maximoIdLibros(eLinkedList* lista){
	eLibro* libro;
	int id;
	int maximo;
	int pocicion;
	int retorno;
	maximo=0;
	retorno=ERROR;
	if(lista!=NULL){
		pocicion=Ll_len(lista);
		for(int i=0;i<pocicion;i++){
			libro=(eLibro*)Ll_get(lista,i);
			Libros_getId(libro,&id);
			if(id>maximo){
				maximo=id;
			}
		}
		retorno=maximo;
	}
	return retorno;
}

int Controlador_altaEditorial(eLinkedList* listaEditoriales,int* idEditorial){
	eEditorial* newEditorial;
	int retorno;
	char nombre[LEN];
	retorno=ERROR;
	if(listaEditoriales!=NULL&&idEditorial>=0){
		(*idEditorial)=(*idEditorial)+1;
		newEditorial=Editoriales_newEditorial();
		Editoriales_setIdEditorial(newEditorial,*idEditorial);
		inputs_nombre("Ingrese el nombre del editorial: ",nombre,LEN);
		Editoriales_setNombre(newEditorial,nombre);
		Ll_add(listaEditoriales,(eEditorial*)newEditorial);
		retorno=0;
	}
	return retorno;
}

int Controlador_altaLibro(eLinkedList* libros, eLinkedList* editorial, int* idLibros){
	eLibro* newLibro;
	char titulo[LEN];
	char autor[LEN];
	float precio;
	int idEditorial;
	int retorno;
	retorno=ERROR;
	if(libros!=NULL&&editorial!=NULL){
		(*idLibros)=(*idLibros)+1;
		newLibro=Libros_newLibro();
		Libros_setId(newLibro,*idLibros);
		inputs_nombre("Ingrese el titulo: ",titulo,LEN);
		Libros_setTitulo(newLibro,titulo);
		inputs_nombre("ingrese el autor: ",autor,LEN);
		Libros_setAutor(newLibro,autor);
		precio=inputs_flotante("ingrese el precio: ",100,1000);
		Libros_setPrecio(newLibro,precio);
		Controlador_mostrarEditoriales(editorial);
		idEditorial=inputs_entero("Ingrese el id del editorial: ",1,Ll_len(editorial));
		Libros_setIdEditorial(newLibro,idEditorial);
		Ll_add(libros,(eLibro*)newLibro);
		retorno=0;
	}
	return retorno;
}

int Controlador_ordenar(eLinkedList* libros,int orden){
	int retorno;
	retorno=ERROR;
	if(libros!=NULL){
		retorno=Ll_sort(libros,Libros_compararAutor,orden);
	}
	return retorno;
}

int Controlador_mostrarEditoriales(eLinkedList* lista){
	eEditorial* editorial;
	int idEditorial;
	char nombre[LEN];
	int retorno;
	int pocicion;
	retorno=ERROR;
	pocicion=Ll_len(lista);
	if(lista!=NULL){
		printf("      Id	Nombre\n");
		for(int i=0;i<pocicion;i++){
			editorial=(eEditorial*)Ll_get(lista,i);
			Editoriales_getIdEditorial(editorial,&idEditorial);
			Editoriales_getNombre(editorial,nombre);
			printf("%4d %15s\n",idEditorial,nombre);
		}
		retorno=0;
	}
	return retorno;
}

int Controlador_mostrarLibros(eLinkedList* lista, eLinkedList* editoriales){
	eLibro* libros;
	eEditorial* aux;
	int id;
	char titulo[LEN];
	char autor[LEN];
	float precio;
	int idEditorial;
	int idComparacion;
	char editorial[LEN];
	int pocicion;
	int retorno;
	retorno=ERROR;
	pocicion=Ll_len(lista);
	if(lista!=NULL&&editoriales!=NULL){
		printf("      Id	Titulo	Autor      Precio	Editorial\n");
		for(int i=0;i<pocicion;i++){
			libros=(eLibro*)Ll_get(lista,i);
			Libros_getId(libros,&id);
			Libros_getTitulo(libros,titulo);
			Libros_getAutor(libros,autor);
			Libros_getPrecio(libros,&precio);
			Libros_getIdEditorial(libros,&idEditorial);
			for(int j=0;j<editoriales->size;j++){
				aux=Ll_get(editoriales,j);
				Editoriales_getIdEditorial(aux,&idComparacion);
				if(idComparacion==idEditorial){
					Editoriales_getNombre(aux,editorial);
				}
			}
			printf("%4d %15s %15s %6.2f %15s\n",id,titulo,autor,precio,editorial);
		}
		retorno=0;
	}
	return retorno;
}

eLinkedList* Controlador_listaFiltrado(eLinkedList* lista, int (*pFunc)(void*)){
	eLinkedList* filtrada;
	filtrada=NULL;
	if(lista!=NULL&&pFunc!=NULL){
		filtrada=Ll_filter(lista,pFunc);
	}
	return filtrada;
}

int Controlador_buscarMinotauro(void* libros){
	int idEditoriales;
	int retorno;
	retorno=ERROR;
	if(libros!=NULL){
		Libros_getIdEditorial(libros,&idEditoriales);
		if(idEditoriales==4){
			retorno=1;
		}
		else{
			retorno=0;
		}
	}
	return retorno;
}

int Controlador_buscarPearson(void* libro){
	int idEditoriales;
	int retorno;
	retorno=ERROR;
	if(libro!=NULL){
		Libros_getIdEditorial(libro,&idEditoriales);
		if(idEditoriales==3){
			retorno=1;
		}
		else{
			retorno=0;
		}
	}
	return retorno;
}

int Controlador_buscarMayores(void* libro){
	float precio;
	int retorno;
	retorno=ERROR;
	if(libro!=NULL){
		Libros_getPrecio(libro,&precio);
		if(precio>500){
			retorno=1;
		}
		else{
			retorno=0;
		}
	}
	return retorno;
}

eLinkedList* Controlador_listaDescontada(eLinkedList* lista){
	eLinkedList* descontada;
	descontada=NULL;
	if(lista!=NULL){
		descontada=Ll_map(lista,Controlador_descontar);
	}
	return descontada;
}

int Controlador_descontar(void* libros){
	int idEditorial;
	float precio;
	float descuento;
	int retorno;
	retorno=ERROR;
	if(libros!=NULL){
		Libros_getIdEditorial(libros,&idEditorial);
		Libros_getPrecio(libros,&precio);
		if(idEditorial==1){
			if(precio>=300){
				descuento=precio*0.2;
				precio-=descuento;
				Libros_setPrecio(libros,precio);
			}
		}
		else{
			if(idEditorial==2){
				if(precio<=200){
					descuento=precio*0.1;
					precio-=descuento;
					Libros_setPrecio(libros,precio);
				}
			}
		}
	}
	return retorno;
}

eLinkedList* Controlador_mayores(eLinkedList* lista, int* contador){
	eLinkedList* retorno;
	retorno=NULL;
	if(lista!=NULL){
		retorno=Controlador_listaFiltrado(lista,Controlador_buscarMayores);
		*contador=Ll_count(lista,Controlador_buscarMayores);
	}
	return retorno;
}

eLinkedList* Controlador_sumaPearson(eLinkedList* lista, float* suma){
	eLinkedList* retorno;
	eLibro* aux;
	float precio;
	int len;
	retorno=NULL;
	if(lista!=NULL){
		*suma=0;
		retorno=Controlador_listaFiltrado(lista,Controlador_buscarPearson);
		len=Ll_len(retorno);
		for(int i=0;i<len;i++){
			aux=Ll_get(retorno,i);
			Libros_getPrecio(aux,&precio);
			*suma+=precio;
		}
	}
	return retorno;
}

int Controlador_guardarLibros(char* nombreArchivo, eLinkedList* libros){
	FILE* archivo;
	eLibro* libro;
	int id;
	char titulo[LEN];
	char autor[LEN];
	float precio;
	int idEditorial;
	int retorno;
	retorno=ERROR;
	if(libros!=NULL){
		archivo=fopen(nombreArchivo,"w");
		if(archivo!=NULL){
			for(int i=0;i<libros->size;i++){
				libro=(eLibro*)Ll_get(libros,i);
				Libros_getId(libro,&id);
				Libros_getTitulo(libro,titulo);
				Libros_getAutor(libro,autor);
				Libros_getPrecio(libro,&precio);
				Libros_getIdEditorial(libro,&idEditorial);
				fprintf(archivo,"%d,%s,%s,%f,%d\n",id,titulo,autor,precio,idEditorial);
			}
		}
		fclose(archivo);
		retorno=0;
	}
	return retorno;
}

int Controlador_guardarEditoriales(char* nombreArchivo, eLinkedList* editoriales){
	FILE* archivo;
	eEditorial* editorial;
	int id;
	char nombre[LEN];
	int retorno;
	retorno=ERROR;
	if(editoriales!=NULL){
		archivo=fopen(nombreArchivo,"w");
		if(archivo!=NULL){
			for(int i=0;i<editoriales->size;i++){
				editorial=(eEditorial*)Ll_get(editoriales,i);
				Editoriales_getIdEditorial(editorial,&id);
				Editoriales_getNombre(editorial,nombre);
				fprintf(archivo,"%d,%s\n",id,nombre);
			}
		}
		fclose(archivo);
		retorno=0;
	}
	return retorno;
}

