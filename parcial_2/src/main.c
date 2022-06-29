#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "validaciones.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int main()
{
	setbuf(stdout,NULL);
	int option;
	int flag=0;

     LinkedList* lista = ll_newLinkedList();
        do{
        	getInt("Menu:\
         \n1. Cargar los datos desde el archivo data.csv (modo texto).\
        \n2. Listar \
      \n3. Cargar \
        \n4. \
        \n5.\
        \n12. Salir\n\n",&option,1,12);

        	switch(option)
        	{
        	case 1:
        		if(flag==0)
        		{
        			controller_loadFromText("datos.csv",lista);
        			flag=1;
        		}
        		else
        		{
        			printf("Ya se ha cargado el archivo\n");
        		}

        		break;
        	case 2:
        		if(ll_len(lista))
        		{
        			controller_ListPassenger(lista);
        		}
        		else
        		{
        			printf("No se han ingresado empleados\n");
        		}
        		break;
        	case 3:
        		break;
        	case 4:
        		break;
        	case 5:
        		break;
        	case 12:
        		break;

        	}
        	system("pause");
        	system("cls");
        }while(option != 12);

        return 0;
}

