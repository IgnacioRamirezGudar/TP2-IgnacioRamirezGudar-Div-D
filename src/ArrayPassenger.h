/*
 * ArrayPassenger.h
 *
 *  Created on: 13 may. 2022
 *      Author: ignac
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

struct{
	int id;
	char name[51];
	char lastname[51];
	float price;
	char flycode[10];
	int typePassenger;
	char destino[51];
	int statusFlight;
	int isEmpty;
}typedef Passenger;

void saltoDeLinea();


int sendDataPassenger(Passenger Datos[],int tamañoDeLaLista, char nombreDeUsuario[], char apellidoDeUsuario[], float precioIngresado, int claseDelUsuario,
		char destinoDelUsuario[], int estadoDelVuelo);

int findPassengerById(Passenger Datos[],int tamañoArray, int id);

int initPassengers(Passenger Datos[],int tamañoDeLaLista);

int changedatauser(Passenger Datos[],int tamañoDeLaLista,int id, int opciones);

int removePassenger(Passenger Datos[],int tamañoDeLaLista, int id);

int sortPassenger(Passenger Datos[],int tamañoDeLaLista, int opciones);

#endif /* ARRAYPASSENGER_H_ */
