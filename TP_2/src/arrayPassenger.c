/*
 * arrayPassenger.c
 *
 *  Created on: 24 abr. 2022
 *      Author: PC-INC
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validaciones.h"
#include "arrayPassenger.h"

#define LIBRE 1
#define OCUPADO 0
#define BAJA -1

static int idIncremental = 1005;
static int ePasajero_obtenerID();
static int ePasajero_obtenerID()
{
	return idIncremental++;
}


int inicializarArrayPasajeros(ePasajero* list, int len)
{  int retorno = -1;
   int i;
    if(list != NULL && len > 0)
    {
    	retorno =0;
    	for(i=0;i<len;i++)
    	{
            list[i].isEmpty = LIBRE;

    	}
    }
	return retorno;
}

ePasajero cargarDatos()
{
	ePasajero unPasajero;
	char nombre[51];
	char apellido[51];
	float precio;
	char codigoDeVuelo[10];
	int tipoDePasajero;


	getString("Ingrese un nombre: ",nombre,1,51);
	getString("Ingrese un apellido: ",apellido,1,51);

    getFloat("Ingrese el precio: ",&precio,0,999999);
	getString("Ingrese codigo de vuelo: ",codigoDeVuelo,1,10);

	getInt("Ingrese tipo de pasajero: ",&tipoDePasajero,0,99999);

	   strcpy(unPasajero.nombre,nombre);
	   strcpy(unPasajero.apellido,apellido);
	   unPasajero.precio=precio;
	   strcpy(unPasajero.codigoDeVuelo,codigoDeVuelo);
	   unPasajero.tipoDePasajero=tipoDePasajero;
	   unPasajero.isEmpty=0;
		return unPasajero;
}

int buscarLibre(ePasajero* list, int len)
{
	int i;
	int indice=-1;
	for(i=0;i<len;i++)
	{
		if(list[i].isEmpty == LIBRE)//libre
		{
			indice=i;
			break;
		}
	}
 return indice;
}


int agregarPasajero(ePasajero* list, int len, int id, char nombre[],char
apellido[],float precio,int tipoDePasajero, char codigoDeVuelo[],int isEmpty)
{
	int indice;
	int retorno =-1;


	indice = buscarLibre(list,len);

	if(indice != -1 && list != NULL)
	{
		strcpy(list[indice].nombre, nombre);
		strcpy(list[indice].apellido, apellido);
        list[indice].precio = precio;
        list[indice].tipoDePasajero = tipoDePasajero;
        strcpy(list[indice].codigoDeVuelo,codigoDeVuelo);

        list[indice].id = id;
        list[indice].isEmpty = isEmpty;

		retorno = 0;
	}
return retorno;
}

int altaPasajero(ePasajero* list, int len)
{
	ePasajero pasajeroAux;
	int id;
	int recibo = -1;

	if(list != NULL && len > 0)
	{
	pasajeroAux = cargarDatos();
	id = ePasajero_obtenerID();
	recibo = agregarPasajero(list,len,id,pasajeroAux.nombre,pasajeroAux.apellido,pasajeroAux.precio,pasajeroAux.tipoDePasajero,pasajeroAux.codigoDeVuelo,pasajeroAux.isEmpty);

		if(recibo  == 0)
		{
			printf("La carga fue exitosa...");
		}
		else
		{
			printf("No hay espacio... ");
		}

	}
	return recibo;
}


int encontrarPasajeroPorId(ePasajero* list, int len,int id)
{  int i;
   int indice = -1;

	if(list != NULL && len > 0)
	{
        for(i=0;i<len;i++)
        {
        	if(list[i].id == id && list[i].isEmpty == OCUPADO)
        	{
        		indice = i;
               break;
        	}
        }
	}
   return indice;
}

void imprimirUnPasajero(ePasajero unPasajero)
{
	printf("%s\t\t%s\t%.2f\t%s\t%d\t%d\n", unPasajero.nombre, unPasajero.apellido, unPasajero.precio,unPasajero.codigoDeVuelo,unPasajero.tipoDePasajero, unPasajero.id);
}

int imprimirArrayPasajeros(ePasajero* list, int largo)
{ int i=0;
    printf("Nombre\t\tApellido\tPrecio\tCodigo de vuelo\tTipo de Pasajero\tID\n");


    if( list != NULL && largo > 0)
    {
		for(i=0;i<largo;i++)
		{
			if(list[i].isEmpty == OCUPADO)
			{
				imprimirUnPasajero(list[i]);
			}
		}
    }
    return 0;
}


void modificarPasajero (ePasajero* list, int len)
{
	int datoEncontrado;
	int auxId;
	int opcionModificar;
	imprimirArrayPasajeros(list, len);
	getInt("\nIngrese numero de ID del pasajero a modificar: ",&auxId,0,999999);
	datoEncontrado = encontrarPasajeroPorId(list, len, auxId);

	if(datoEncontrado != -1 )
	{
		printf("\nSe encontro el dato: \n");

		imprimirUnPasajero(list[datoEncontrado]);


		do{
			getInt("\n¿Que desea modificar?\n1.Nombre\n2.Apellido \n3.Precio\n4.Codigo de vuelo\n5.Tipo de pasajero\n6.Salir\nOpcion: ",&opcionModificar,1,6);
				switch(opcionModificar)
				{

					case 1:
						getString("Ingrese nombre: ",list[datoEncontrado].nombre , 1, 51);
						break;
					case 2:
						getString("Ingrese apellido: ",list[datoEncontrado].apellido , 1, 51);
						break;
					case 3:
						getFloat("Ingrese precio: ",&list[datoEncontrado].precio , 1, 999999);
						break;
					case 4:
						getString("Ingrese codigo de vuelo: ",list[datoEncontrado].codigoDeVuelo , 1, 10);
						break;
					case 5:
						getInt("Ingrese tipo de pasajero: ",&list[datoEncontrado].tipoDePasajero , 1, 999999);
						break;
					case 6:
						printf("Saliendo de modificar.");
						break;
					default:
						printf("La opcion ingresada es incorrecta.");
						break;
				}

		}while(opcionModificar != 6);
	}
	else
	{
		printf("No se encontro el dato.");
	}
}

int eliminarPasajero(ePasajero* list, int len, int id, int posicion )// tendria que ser id
{
	int retorno = -1;
	char confirmar;

	if(list != NULL && len > 0)
	{
		printf("Dar de baja? [S|N]: ");
		fflush(stdin);
		scanf("%c",&confirmar);
		confirmar = toupper(confirmar);

		if(confirmar == 'S')
		{
			list[posicion].isEmpty= BAJA;
			printf("Se han borrado los datos...");
			retorno = 0;
		}
		else
		{
			printf("No se han borrado los datos...");
			retorno = 1;
		}
	}
	return retorno;
}


int bajaPasajero(ePasajero* list, int len)
{
	int retorno = -1;
	int datoEncontrado;
	int auxId;
	imprimirArrayPasajeros(list, len);
	getInt("\nIngrese numero de ID del pasajero a dar de baja: ",&auxId,0,999999);;
	datoEncontrado = encontrarPasajeroPorId(list,len, auxId);

	if(datoEncontrado != -1 )
	{
		printf("\nSe encontro el dato: \n");

		imprimirUnPasajero(list[datoEncontrado]);
		if(eliminarPasajero(list, len,auxId,datoEncontrado) == 0)
		{
			retorno = 0;
		}
	}
	else
	{
		printf("No se encontro el dato.");
	}
	return retorno;
}

int ordenarPasajerosPorNombre(ePasajero* list, int len, int order)
{
	int retorno = -1;
	int i;
	int j;
	ePasajero aux;

	if(list != NULL && len > 0)
	{
		if(order == 1)//UP
		{
            for(i=0;i<len-1;i++)
            {
            	for(j=0;j<len;j++)
            	{
            		if(strcmp(list[i].nombre,list[j].nombre)>0)
            		{
                          aux = list[i];
                          list[i] = list[j];
                          list[j] = aux;
            		}
            		else
            		{
            			if(strcmp(list[i].nombre,list[j].nombre)==0)
            			{
            				if(list[i].tipoDePasajero > list[j].tipoDePasajero)
            				{
            					aux = list[i];
            					list[i] = list[j];
            					list[j] = aux;
            				}

            			}
            		}
            	}
            }
		}
	}
return retorno;
}
