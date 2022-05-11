/*
 ============================================================================
 Name        : TP_2.c
 Author      : Micaela
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validaciones.h"
#include "arrayPassenger.h"


#define CANT 10
int main(void)
{   setbuf(stdout,NULL);
	ePasajero pasajeros[CANT];//Pasajeros hasta 2000. ARRAY[2000]

	int opcion;
	int contadorDatos=0;
	int opcionInformar;



   inicializarArrayPasajeros(pasajeros, CANT);

    do{
    	getInt("\nMENU\n1. Alta\n2. Modificar\n3. Baja\n4. Informar\n5. Salir\n Opcion: ",&opcion,1,5);
    	switch(opcion)
    	{

			case 1:
                   if(altaPasajero(pasajeros,CANT)==0)
                   {
                	   contadorDatos++;
                   }
				break;

			case 2://MODIFICAR
					if( contadorDatos > 0)
					{

					  modificarPasajero(pasajeros, CANT);
					}
					else
					{
						printf("No existen datos cargados...");
					}
				break;

			case 3://BAJA
				if( contadorDatos > 0)
				{

					if(bajaPasajero(pasajeros, CANT)==0)
					{
						contadorDatos--;
					}
				}
				else
				{
					printf("No existen datos cargados...");
				}
				break;

			case 4://INFORMAR
				/*if(contadorDatos<0)
				{
					for(i=0;i<CANT;i++)
					{
						if(pasajeros[i].isEmpty==0)
						{
							mostrarUnPsajero(pasajeros[i]);
						}
					}
				}*/
				if(contadorDatos > 0)
				{
					do{
					   getInt("\n¿Que desea informar?\n1. Pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero.\n2. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio.\n3. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’\n Opcion: ",&opcionInformar,1,3);
						switch(opcionInformar)
						{

						case 1:
                           //Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero.

							break;
						case 2:
                           //Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio.
							break;
						case 3:
                           //Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’

							break;
						}
				     }while(opcionInformar != 4);
				}
				else
				{
					printf("No existen datos cargados...");
				}
				break;

			case 5://SALIR
				break;

    	}
    	printf("\n\n");
    } while(opcion != 5);


    return EXIT_SUCCESS;
}


