/*
 * arrayPassenger.h
 *
 *  Created on: 24 abr. 2022
 *      Author: PC-INC
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

typedef struct
{
	int id;
	char nombre[51];//nombre
	char apellido[51];//apellido
	float precio;
	char codigoDeVuelo[10];//codigo de vuelo
	int tipoDePasajero;//adultos menores
	int estadoDeVuelo;//activo demorado cancelado
	int isEmpty; //(esta vacio)

}ePasajero;


/**
 * @brief busca un indice libre del array y retorna el indice si lo encontro o -1 si no encontro.
 *
 * @param list array ePasajero
 * @param len largo del array
 * @return
 */
int buscarLibre(ePasajero* list, int len);

/**
 * @brief cargar un pasajero
 *
 * @return devulve un pasajero
 */
ePasajero cargarPasajeros(void);


/**
 * @brief controla el alta de pasajeros
 *
 * @param list array de ePasajero
 * @param len  largo
 * @param id   id
 * @return
 */
int altaPasajero(ePasajero* list, int len);
/**
 * @brief Para indicar que todas las posiciones en la matriz están vacías,
esta función pone la bandera (isEmpty) en VERDADERO en todos
posición de la matriz(array).
 *
 * @param list Puntero a una matriz de pasajeros
 * @param len int de longitud de la matriz
 * @return int Devuelve (-1) si hay error [longitud no válida o puntero NULL] - (0) si está bien
 */
int inicializarArrayPasajeros(ePasajero* list, int len); // MAIN initPassengers(arrayPassengers, ELEMENTS);


/**
 * @brief agregar en una lista existente de pasajeros los valores recibidos como parámetros
  en la primera posición vacía
 *
 * @param list lista de pasajeros
 * @param len int longitud
 * @param id int
 * @param nombre char
 * @param apellido char
 * @param precio int
 * @param tipoDePasajero int
 * @param codigoDeVuelo char
 * @return int Devuelve (-1) si hay error [Longitud no válida o puntero NULL o sin
espacio libre] - (0) si está bien
 */
int agregarPasajero(ePasajero* list, int len, int id, char nombre[],char
apellido[],float precio,int tipoDePasajero, char codigoDeVuelo[],int isEmpty); //addPassenger(arrayPassenger,ELEMENTS,id,name,lastName,price,typePassenger,flycode);






/**
 * @brief Devuelve/Retorna la posición del índice en la matriz.
 *
 * @param list Passenger*
 * @param len entero
 * @param id  entero
 * @return Posición del índice de pasajeros de regreso o (-1) si [Longitud o
Puntero NULL recibido o pasajero no encontrado]
 */
int encontrarPasajeroPorId(ePasajero* list, int len,int id);



/**
 * @brief Eliminar una pasajera por Id (poner isEmpty Flag en 1)
 *
 *
 * @param list array
 * @param len int
 * @param id  int
 * @return Devuelve (-1) si hay un error [Longitud no válida o puntero NULL o si no se puede
encontrar un pasajero] - (0) si está bien.
 */
int eliminarPasajero(ePasajero* list, int len, int id, int posicion);




/**
 * @brief Ordenar el array de pasajeros por apellido y tipo de pasajero de manera ascendente o
descendente.
 *
 * @param list array
 * @param len int longitud
 * @param order [1] indicate UP - [0] indicate DOWN
 * @return int Devuelve (-1) si hay error [longitud no válida o puntero NULL] - (0) si está bien
 */
int ordenarPasajerosPorNombre(ePasajero* list, int len, int order);


/**
 * @brief imprime el contenido del array de pasajeros.
 *
 * @param list
 * @param largo
 * @return int
 */
int imprimirArrayPasajeros(ePasajero* list, int largo);

/**
 * @brief imprime un pasajero
 *
 * @param unPasajero
 */
void imprimirUnPasajero(ePasajero unPasajero);


/**
 * @brief Ordenar los elementos en la matriz de pasajeros, el orden de los argumentos
indicar orden ARRIBA o ABAJO.
 *
 * @param list array
 * @param len
 * @param order int [1] indica ARRIBA - [0] indica ABAJO
 * @return Devuelve (-1) si hay un error [longitud no válida o puntero NULL] - (0) si está bien
 */
int ordenarPasajerosPorCodigo(ePasajero* list, int len, int order);

/**
 * @brief controla la modificacion de pasajeros
 *
 * @param list array
 * @param len longitud
 */
void modificarPasajero (ePasajero* list, int len);



int bajaPasajero(ePasajero* list, int len);


void hardcodearPasajeros (ePasajero* list);
#endif /* ARRAYPASSENGER_H_ */
