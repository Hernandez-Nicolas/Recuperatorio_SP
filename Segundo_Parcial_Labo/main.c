#include<stdio.h>
#include<stdlib.h>
#include"Controlador.h"
#include"inputs.h"


int main (){
	setbuf(stdout,NULL);
	eLinkedList* listaLibros;
	eLinkedList* listaEditoriales;
	eLinkedList* listaFiltrada;
	eLinkedList* listaDescontada;
	eLinkedList* listaPearson;
	eLinkedList* listaMayores;
	int editorialId;
	int cargaFlag;
	int libroId;
	int contadorMayores;
	float suma;
	int eleccion;
	int salida;
	int error;
	editorialId=0;
	libroId=0;
	salida=0;
	cargaFlag=0;
	listaLibros=Ll_newLinkedList();
	listaEditoriales=Ll_newLinkedList();
	do{
		printf("1) Cargar archivos\n2) Alta editorial\n3) Alta libro\n4) Mostrar datos de los libros\n"
				"5) Listado de libros editorial MINOTAURO\n6) Lista con descuentos\n7) Subir archivos\n"
				"8) Lista de libros mayores a $500\n9) Sumatoria de precios editorial PEARSON\n10) Salir\n");
		eleccion=inputs_entero("Ingrese su eleccion: ",1,10);
		switch(eleccion){
		case 1:
			if(cargaFlag!=2){
				error=Controlador_leerEditoriales("Editoriales.csv",listaEditoriales);
				if(error==ERROR){
					printf("OCURRIO UN ERROR AL ABRIR EL ARCHIVO DE EDITORIALES\n");
					error=0;
				}
				else{
					cargaFlag++;
					editorialId=Controlador_maximoIdEditoriales(listaEditoriales);
				}
				error=Controlador_leerLibros("Libros.csv",listaLibros);
				if(error==ERROR){
					printf("OCURRIO UN ERROR AL ABRIR EL ARCHIVO DE LIBROS\n");
					error=0;
				}
				else{
					cargaFlag++;
					libroId=Controlador_maximoIdLibros(listaLibros);
				}
			}
			break;
		case 2:
			error=Controlador_altaEditorial(listaEditoriales,&editorialId);
			editorialId=Controlador_maximoIdEditoriales(listaEditoriales);
			break;
		case 3:
			error=Controlador_altaLibro(listaLibros,listaEditoriales,&libroId);
			libroId=Controlador_maximoIdLibros(listaLibros);
			Controlador_ordenar(listaLibros,1);
			break;
		case 4:
			if((cargaFlag==2&&editorialId>0&&libroId>0)||(editorialId>0&&libroId>0)){
				error=Controlador_mostrarLibros(listaLibros,listaEditoriales);
			}
			break;
		case 5:
			if((cargaFlag==2&&editorialId>0&&libroId>0)||(editorialId>0&&libroId>0)){
				listaFiltrada=Controlador_listaFiltrado(listaLibros,Controlador_buscarMinotauro);
				error=Controlador_mostrarLibros(listaFiltrada,listaEditoriales);
				Controlador_guardarLibros("ListaFiltrada.csv",listaFiltrada);
			}
			break;
		case 6:
			if((cargaFlag==2&&editorialId>0&&libroId>0)||(editorialId>0&&libroId>0)){
			listaDescontada=Controlador_listaDescontada(listaLibros);
			error=Controlador_mostrarLibros(listaDescontada,listaEditoriales);
			Controlador_guardarLibros("Mapeado.csv",listaDescontada);
			}
			break;
		case 7:
			if((cargaFlag==2&&editorialId>0&&libroId>0)||(editorialId>0&&libroId>0)){
				Controlador_guardarLibros("Libros.csv",listaLibros);
				Controlador_guardarEditoriales("Editoriales.csv",listaEditoriales);
			}
			break;
		case 8:
			if((cargaFlag==2&&editorialId>0&&libroId>0)||(editorialId>0&&libroId>0)){
				listaMayores=Controlador_mayores(listaLibros,&contadorMayores);
				error=Controlador_mostrarLibros(listaMayores,listaEditoriales);
				printf("La cantidad de libros mayores a $500 es: %d\n",contadorMayores);
			}
			break;
		case 9:
			if((cargaFlag==2&&editorialId>0&&libroId>0)||(editorialId>0&&libroId>0)){
				listaPearson=Controlador_sumaPearson(listaLibros,&suma);
				error=Controlador_mostrarLibros(listaPearson,listaEditoriales);
				printf("La suma de precios de todos los libros pearson es: %.2f\n",suma);
			}
			break;
		default:
			salida=1;
			break;
		}
		if(error==ERROR){
			printf("\tOCURRIO UN ERROR");
		}
	}while(!salida);
	return EXIT_SUCCESS;
}
