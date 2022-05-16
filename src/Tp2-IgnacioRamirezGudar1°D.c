/*
 ============================================================================
 Name        : Tp2-IgnacioRamirezGudar1�D.c
 Author      : Ignacio Ramirez Gudar div D
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "ArrayPassenger.h"

#define TAMARRAYPASAJEROS 3


int addPassengers(Passenger DatosGenerales[], int arrayPasajeros);
int changeDataPassenger(Passenger DatosGenerales[], int arrayPasajeros);
int delatePassenger(Passenger DatosGenerales[], int arrayPasajeros);
int listPassenger(Passenger DatosGenerales[], int arrayPasajeros);

int main(void) {
	setbuf(stdout, NULL);

	Passenger DatosGenerales[TAMARRAYPASAJEROS];

	initPassengers(DatosGenerales,TAMARRAYPASAJEROS);

	char opciones;

	do{
		printf("\n\t    SISTEMA DE REGISTRO AEROLINEAS"
				"\n<-------------------------------------------------------->"
				"\n\t\t 1)Ingresar usuario"
				"\n\t\t 2)Modificar usuario"
				"\n\t\t 3)Eliminar usuario"
				"\n\t\t 4)Informar"
				"\n\t\t 5)Cargar Datos forzados"
				"\n\t\t 6)Salir"
				"\n<-------------------------------------------------------->"
				"\nEliga una opcion: ");
				scanf("%s", &opciones);
				switch(opciones){
					case '1':
						addPassengers(DatosGenerales, TAMARRAYPASAJEROS);
						saltoDeLinea();
						break;
					case '2':
						changeDataPassenger(DatosGenerales, TAMARRAYPASAJEROS);
						saltoDeLinea();
						break;
					case '3':
						delatePassenger(DatosGenerales, TAMARRAYPASAJEROS);
						saltoDeLinea();
						break;
					case '4':
						listPassenger(DatosGenerales, TAMARRAYPASAJEROS);
						break;
					case '5':
						break;
					case '6':
						saltoDeLinea();
						printf("\nSALIO DEL PROGRAMA");
						return 0;
						break;
				}
				if(opciones > '6' ){
					printf("\nERROR AL INGRESAR UNA OPCIONES, INTRODUSCA UNA OPCION VALIDA");
					saltoDeLinea();
				}

	}while(opciones != '6');
	return 0;
}

int addPassengers(Passenger DatosGenerales[], int arrayPasajeros){

	Passenger unPasajero;

	int SeguirIngresando = 1;
	char Seguir[51];

	while(SeguirIngresando == 1){
		saltoDeLinea();
		printf("\n\t\t     AÑADIR PASAJERO");
		printf("\n<-------------------------------------------------------->");
		printf("\n¿Nombre del usuario?");
		fflush(stdin);
		gets(unPasajero.name);
		printf("\n¿Apellido del usuario?");
		fflush(stdin);
		gets(unPasajero.lastname);
		printf("\n¿Precio del usuario?");
		scanf("%f", &unPasajero.price);
		printf("\n¿Cual es su destino?");
		fflush(stdin);
		gets(unPasajero.destino);
		printf("\n|\t1) EN VUELO\t|\t2) ATERRIZO \t|\t3) CANCELADO\t|");
		printf("\n¿Estado del vuelo?");
		scanf("%d", &unPasajero.statusFlight);
		printf("\n|\t1) CLASE ALTA\t|\t2) CLASE ECONOMICA \t|\t3) CLASE BAJA\t|");
		printf("\n¿Tipo de clase del usuario?");
		scanf("%d", &unPasajero.typePassenger);
		sendDataPassenger(DatosGenerales,arrayPasajeros, unPasajero.name, unPasajero.lastname, unPasajero.price, unPasajero.typePassenger,
							unPasajero.destino, unPasajero.statusFlight);
		printf("\n<-------------------------------------------------------->");
		printf("\n¿Quiere seguir ingresando pasajeros?");
		fflush(stdin);
		gets(Seguir);
		if(strcmp(Seguir, "no") == 0){
			SeguirIngresando = 0;
		}
		saltoDeLinea();
	}
	return 0;
}


int changeDataPassenger(Passenger DatosGenerales[], int arrayPasajeros){

	int id;
	int opciones;
					printf("\n\t\t     MODIFICAR USUARIO");
						printf("\n||--------------------------------------------------------||");
						printf("\nIngrese id del usuario que desea modificar: ");
						scanf("%d", &id);
						findPassengerById(DatosGenerales, arrayPasajeros,id);
						printf("\n||--------------------------------------------------------||");
						printf("\n\t    OPCIONES DE MODIFICACION"
								"\n<-------------------------------------------------------->"
								"\n\t\t 1- Modificar nombre del pasajero"
								"\n\t\t 2- Modificar apellido del pasajero"
								"\n\t\t 3- Modificar la clase del pasajero"
								"\n\t\t 4- Modificar el codigo de vuelo"
								"\n\t\t 5- CANCELAR"
								"\n<-------------------------------------------------------->"
								"\nEliga una opcion: ");
						scanf("%d", &opciones);
						changedatauser(DatosGenerales, arrayPasajeros,id, opciones);

	return 0;
}

int delatePassenger(Passenger DatosGenerales[], int arrayPasajeros){

	int id;

		if(DatosGenerales->isEmpty == 1){
		 	printf("\n\t\t     ELIMINAR USUARIO");
			printf("\n||--------------------------------------------------------||");
			printf("\nIngrese id del usuario que desea eliminar: ");
			scanf("%d", &id);
			removePassenger(DatosGenerales, arrayPasajeros,id);
		} else {
			printf("\n\t\t PRIMERO DEBE INGRESAR UN PASAJERO");
		}

	return -1;
}

int listPassenger(Passenger DatosGenerales[], int arrayPasajeros){

		int opciones;
		if(DatosGenerales->isEmpty == 1){
			do{
				printf("\n||--------------------------------------------------------||");
				printf("\n\t    MOSTRAR LISTA"
						"\n<-------------------------------------------------------->"
						"\n1- Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero."
						"\n2- Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio."
						"\n3- Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’"
						"\n5- CANCELAR"
						"\n<-------------------------------------------------------->"
						"\nEliga una opcion: ");
				scanf("%d", &opciones);
				sortPassenger(DatosGenerales,arrayPasajeros, opciones);
			}while(opciones != 5);
		} else {
			printf("\n\t\t PRIMERO DEBE INGRESAR UN PASAJERO");
		}
		saltoDeLinea();

	return 0;
}

