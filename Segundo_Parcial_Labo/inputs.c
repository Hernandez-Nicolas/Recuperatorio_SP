#include "inputs.h"

int inputs_entero(char cadena[],int inferior, int superior){
	int numero;
	int validacion;
	printf("%s",cadena);
	do{
		fflush(stdin);
		validacion=scanf("%d",&numero);
		while(validacion==0){
			printf("Solo pueden ingresarse numeros: ");
			fflush(stdin);
			validacion=scanf("%d",&numero);
		}
		if(numero<inferior||numero>superior){
			printf("El numero no esta dentro del rango, debe estar entre %d y %d\n",inferior,superior);
			printf("%s",cadena);
		}
	}while(numero<inferior||numero>superior);
	return numero;
}

long int inputs_enteroLargo(char cadena[],long int inferior, long int superior){
	long int numero;
	int validacion;
	printf("%s",cadena);
	do{
		fflush(stdin);
		validacion=scanf("%ld",&numero);
		while(validacion==0){
			printf("Solo pueden ingresarse numeros: ");
			fflush(stdin);
			validacion=scanf("%ld",&numero);
		}
		if(numero<inferior||numero>superior){
			printf("El numero no esta dentro del rango, debe estar entre %ld y %ld\n",inferior,superior);
			printf("%s",cadena);
		}
	}while(numero<inferior||numero>superior);
	return numero;
}

float inputs_flotante(char cadena[],float inferior, float superior){
	float numero;
	int validacion;
	printf("%s",cadena);
	do{
		fflush(stdin);
		validacion=scanf("%f",&numero);
		while(validacion==0){
			printf("Solo pueden ingresarse numeros: ");
			fflush(stdin);
			validacion=scanf("%f",&numero);
		}
		if(numero<inferior||numero>superior){
			printf("El numero no esta dentro del rango, debe estar entre %.2f y %.2f\n",inferior,superior);
			printf("%s",cadena);
		}
	}while(numero<inferior||numero>superior);
	return numero;
}

void inputs_cadena(char mensaje[],char cadena[],int largo){
	int confirmacion;
	printf("%s",mensaje);
	fflush(stdin);
	gets(cadena);
	confirmacion=strlen(cadena);
	while(confirmacion>largo-1||confirmacion==0){
		if(confirmacion==0){
			printf("No puede evitar este campo\n");
		}
		else{
			printf("Se sobre paso el maximo de caracteres, debe ingresar %d caracteres menos\n",confirmacion-largo-1);
		}
		fflush(stdin);
		gets(cadena);
		confirmacion=strlen(cadena);
	}
}

void inputs_nombre(char mensaje[],char cadena[],int largo){
	int bandera;
	int banderaCadena;
	int largoNombre;
	banderaCadena=0;
	inputs_cadena(mensaje,cadena,largo);
	do{
		largoNombre=strlen(cadena);
		for(int i=0;i<largoNombre;i++){
			if(isalpha(cadena[i])==0&&isspace(cadena[i])==0){
				banderaCadena=1;
			}
		}
		if(banderaCadena==0){
			strlwr(cadena);
			for(int i=0;i<largoNombre;i++){
				if(i==0||isspace(cadena[i-1])){
					cadena[i]=toupper(cadena[i]);
					bandera=1;
				}
			}
		}
		else{
			inputs_cadena("El nombre solo puede contener letras y espacios, ingrese un nombre valido\n",cadena,largo);
			banderaCadena=0;
			bandera=0;
		}
	}while(bandera==0);
}
