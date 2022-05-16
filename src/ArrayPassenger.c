/*
 * ArrayPassenger.c
 *
 *  Created on: 13 may. 2022
 *      Author: ignac
 */


#include "ArrayPassenger.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


#define LONGITUD_DESEADA 6

static int valId = -1;

int generateId();

void saltoDeLinea(){
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}


int generateId(){
	valId++;

	return valId;
}

int rangoDelcodigo(int minimo, int maximo) {
    return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}

void generarFlyCode(int longitud, char *code){
    char letrasYnumeros[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
    for (int i = 0; i < longitud; i++){
        int codigoDeVueloAleatorio = rangoDelcodigo(0, (int) strlen(letrasYnumeros) - 1);
        code[i] = letrasYnumeros[codigoDeVueloAleatorio];
    }
}

int sendDataPassenger(Passenger Datos[],int tamañoDeLaLista, char nombreDeUsuario[], char apellidoDeUsuario[], float precioIngresado, int claseDelUsuario,
		char destinoDelUsuario[], int estadoDelVuelo){

	Passenger dataPasajero;

	int retorno = -1;
    char flycodigo[LONGITUD_DESEADA + 1] = "";

	if(dataPasajero.isEmpty == 1){
		printf("\n 	HELLO");
	} else{
		dataPasajero.id = generateId();
		strcpy(dataPasajero.name, nombreDeUsuario);
		strcpy(dataPasajero.lastname, apellidoDeUsuario);
		dataPasajero.price = precioIngresado;
		dataPasajero.typePassenger = claseDelUsuario;
		dataPasajero.isEmpty = 1;
		strcpy(dataPasajero.destino, destinoDelUsuario);
		dataPasajero.statusFlight = estadoDelVuelo;
		generarFlyCode(LONGITUD_DESEADA, flycodigo);
		strcpy(dataPasajero.flycode, flycodigo);
		Datos[dataPasajero.id] = dataPasajero;
	}

	return retorno;
}

int initPassengers(Passenger Datos[],int tamañoDeLaLista){

	for(int i = 0; i < tamañoDeLaLista; i++){
		if(Datos[i].isEmpty == 1){
			Datos[i].isEmpty = 1;
		}else{
			Datos[i].isEmpty = 0;
		}
	}

	return 0;
}

int findPassengerById(Passenger Datos[],int tamañoArray, int id){

		char statusFlight[51];
		char typePassenger[51];

		for(int i = 0; i < tamañoArray; i++){
			if(id == Datos[i].id){
				printf("\n<--------------------PASAJERO %s-------------------->",Datos[i].name);
				printf("\n\t\tID %d",Datos[i].id);
				printf("\n\t\tNOMBRE:  %s",Datos[i].name);
				printf("\n\t\tAPELLIDO:  %s",Datos[i].lastname);
				printf("\n\t\tPAGO:  %f",Datos[i].price);
				printf("\n\t\tDESTINO:  %s",Datos[i].destino);
				if(Datos[i].statusFlight == 1){
					strcpy(statusFlight, "EN VUELO");
				}else{
					if(Datos[i].statusFlight == 2){
						strcpy(statusFlight, "ATERRIZO");
					} else {
						if(Datos[i].statusFlight == 3){
							strcpy(statusFlight, "CANCELADO");
						}
					}
				}
				printf("\n\t\tESTADO DEL VUELO:  %s",statusFlight);
				if(Datos[i].typePassenger == 1){
					strcpy(typePassenger, "CLASE ALTA");
				}else{
					if(Datos[i].typePassenger == 2){
						strcpy(typePassenger, "CLASE ECONOMICA");
					} else {
						if(Datos[i].typePassenger == 3){
							strcpy(typePassenger, "CLASE BAJA");
						}
					}
				}
				printf("\n\t\tCLASE DEL PASAJERO:  %s",typePassenger);
				printf("\n\t\tCODIGO DEL VUELO:  %s",Datos[i].flycode);
			}
		}
	return 0;
}


int changedatauser(Passenger Datos[],int tamañoDeLaLista, int id, int opciones){

	char changename[51];
	char changlastname[51];
	int changetypePassenger;
	char flycodigo[LONGITUD_DESEADA + 1] = "";

			switch(opciones){
							case 1:
								for(int i = 0; i < tamañoDeLaLista; i++){
									if(id == Datos[i].id){
										printf("\nAnterior nombre: %s ", Datos[i].name);
										printf("\nNuevo nombre: ");
										fflush(stdin);
										gets(changename);
										strcpy(Datos[i].name,changename);
									}
								}
								break;
							case 2:
								for(int i = 0; i < tamañoDeLaLista; i++){
									if(id == Datos[i].id){
										printf("\nAnterior apellido: %s ", Datos[i].lastname);
										printf("\nNuevo apellido: ");
										fflush(stdin);
										gets(changlastname);
										strcpy(Datos[i].lastname,changlastname);
									}
								}
								break;
							case 3:
								for(int i = 0; i < tamañoDeLaLista; i++){
									if(id == Datos[i].id){
										printf("\nAnterio clase del pasajero: %d ", Datos[i].typePassenger);
										printf("\nNueva clase del pasajero: ");
										scanf("%d", &changetypePassenger);
										Datos[i].typePassenger = changetypePassenger;
									}
								}
								break;
							case 4:
								for(int i = 0; i < tamañoDeLaLista; i++){
									if(id == Datos[i].id){
										printf("\nAnterior codigo de vuelo: %s ", Datos[i].flycode);
										generarFlyCode(LONGITUD_DESEADA, flycodigo);
										printf("\nEl nuevo codigo de vuelo es: %s", flycodigo);
										strcpy(Datos[i].flycode, flycodigo);
									}
								}
								break;
						}
	return 0;
}

int removePassenger(Passenger Datos[],int tamañoDeLaLista, int id){

	for(int i = 0; i < tamañoDeLaLista; i++){
		if(id == Datos[i].id){
			Datos[id].isEmpty = 0;
			printf("\nUSUARIO ELIMINADO");
		}
	}

	return -1;
}

int sortPassenger(Passenger Datos[],int tamañoDeLaLista, int opciones){

	Passenger LastName;
	char statusFlight[51];
	char typePassenger[51];

	float promedioTotal;
	float topPromedio;
	int banderaPromedio = 1;

	switch(opciones){
		case 1:
			saltoDeLinea();
				for(int i = 0; i < tamañoDeLaLista - 1; i++){
					for(int x = i + 1; x < tamañoDeLaLista; x++){
						if(strcmp(Datos[i].lastname, Datos[x].lastname) > 0){
							LastName = Datos[i];
							Datos[i] = Datos[x];
							Datos[x] = LastName;
						}
						if(strcmp(Datos[i].lastname, Datos[x].lastname) == 0){
							if(Datos[i].typePassenger > Datos[x].typePassenger){
								LastName = Datos[i];
								Datos[i] = Datos[x];
								Datos[x] = LastName;
							}
						}
					}
				}
		 	printf("\n\t\t     LISTA DE PASAJEROS");
			printf("\n|-------------------------------------------------------------------------------------------------------------------------------------------------------|");
			printf("\n|ID|\tNOMBRE\t|\tAPELLIDO\t|\tPRECIO\t\t|\tCODIGO DE VUELO\t|\tTIPO DE PASAJERO\t|\tESTADO DEL VUELO\t|");
			printf("\n|=======================================================================================================================================================|");
			for(int i = 0; i < tamañoDeLaLista; i++){
				if(Datos[i].isEmpty == 1){
					if(Datos[i].statusFlight == 1){
						strcpy(statusFlight, "EN VUELO");
					}else{
						if(Datos[i].statusFlight == 2){
							strcpy(statusFlight, "ATERRIZO");
						} else {
							if(Datos[i].statusFlight == 3){
								strcpy(statusFlight, "CANCELADO");
							}
						}
					}
					if(Datos[i].typePassenger == 1){
						strcpy(typePassenger, "CLASE ALTA");
					}else{
						if(Datos[i].typePassenger == 2){
							strcpy(typePassenger, "CLASE ECONOMICA");
						} else {
							if(Datos[i].typePassenger == 3){
								strcpy(typePassenger, "CLASE BAJA");
							}
						}
					}
					printf("\n|%d |\t%s\t|\t%s\t\t|\t%2.f\t\t|\t%s\t\t|\t%s\t\t|\t\t%s\t|", Datos[i].id, Datos[i].name,Datos[i].lastname,Datos[i].price,Datos[i].flycode,typePassenger,statusFlight);
					printf("\n|-------------------------------------------------------------------------------------------------------------------------------------------------------|");
				}
			}
			saltoDeLinea();
			break;
		case 2:
			saltoDeLinea();
			for(int i = 0; i < tamañoDeLaLista; i++){
				promedioTotal = (promedioTotal + Datos[i].price);
			}
			printf("\n\t\t El promedio total es: %2.f", promedioTotal);
			for(int i = 0; i < tamañoDeLaLista; i++){
				if(topPromedio < Datos[i].price || banderaPromedio == 1){
					topPromedio = Datos[i].price;
					banderaPromedio = 0;
				}
			}
			printf("\n\t\t El pasajero que supera el precio promedio : %2.f", topPromedio);
			saltoDeLinea();
			break;
		case 3:
			saltoDeLinea();
			for(int i = 0; i < tamañoDeLaLista; i++){
				if(Datos[i].statusFlight == 2){
						strcpy(statusFlight, "ATERRIZO");
						if(Datos[i].typePassenger == 1){
							strcpy(typePassenger, "CLASE ALTA");
						}else{
							if(Datos[i].typePassenger == 2){
								strcpy(typePassenger, "CLASE ECONOMICA");
							} else {
								if(Datos[i].typePassenger == 3){
									strcpy(typePassenger, "CLASE BAJA");
								}
							}
						}
					 	printf("\n\t\t     LISTA DE PASAJEROS");
						printf("\n|-------------------------------------------------------------------------------------------------------------------------------------------------------|");
						printf("\n|ID|\tNOMBRE\t|\tAPELLIDO\t|\tPRECIO\t\t|\tCODIGO DE VUELO\t|\tTIPO DE PASAJERO\t|\tESTADO DEL VUELO\t|");
						printf("\n|=======================================================================================================================================================|");
						printf("\n|%d |\t%s\t|\t%s\t|\t%2.f\t|\t%s\t|\t%s\t|\t%s\t|", Datos[i].id, Datos[i].name,Datos[i].lastname,Datos[i].price,Datos[i].flycode,typePassenger,statusFlight);
						printf("\n|-------------------------------------------------------------------------------------------------------------------------------------------------------|");
				} else {
					printf("\n\t\t    NO SE A ENCONTRADO PASAJEROS");
				}
			}
			saltoDeLinea();
			break;
	}

	return 0;
}
