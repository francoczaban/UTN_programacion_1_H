#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Cliente.h"
#include "utn.h"

/**
 * \brief Inicializa el array
 * \param array Array de clientes a ser actualizado
 * \param limite Limite del array de clientes
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int cli_inicializarArray(Cliente* array, int limite){
	int respuesta = -1;
	if(array != NULL && limite > 0){
		respuesta = 0;
		for(int i = 0 ; i < limite ; i++){
			array[i].isEmpty = 1;
		}
	}
	return respuesta;
}

int cli_imprimir(Cliente* pElemento){
	int retorno = -1;
	if(pElemento != NULL && pElemento->isEmpty == 0){
		retorno = 0;
		printf("\nID: %d - %s - %s - %s", pElemento->id, pElemento->nombre, pElemento->apellido, pElemento->cuit);
	}
	return retorno;
}

/**
 * \brief Imprime el array de clientes
 * \param array Array de clientes a ser actualizado
 * \param limite Limite del array de clientes
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int cli_imprimirArray(Cliente* array, int limite){
	int respuesta = -1;
	if(array != NULL && limite > 0){
		respuesta = 0;
		for(int i = 0 ; i < limite ; i++){
			cli_imprimir(&array[i]);
		}
	}
	return respuesta;
}

void cli_imprimirClientes(int idCliente, int limite){
	int cont = 0;
	if(idCliente != NULL){
		for(int i = 0 ; i < limite ; i++){

		}
	}
}



/**
 * \brief Da de alta una pantalla en una posicion del array
 * \param array Array de pantallas a ser actualizado
 * \param limite Limite del array de pantallas
 * \param indice Posicion a ser actualizada
 * \param id Identificador a ser asignado a la pantalla
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int cli_altaArray(Cliente* array, int limite, int indice, int* id){
	int respuesta = -1;
	Cliente bufferCliente;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && id != NULL){
		if(	utn_getNombre(bufferCliente.nombre, NOMBRE_LEN, "\nNombre:\n","\nERROR\n", 2) == 0 &&
			utn_getNombre(bufferCliente.apellido, NOMBRE_LEN, "\nApellido:\n", "\nERROR\n", 2) == 0 &&
			utn_getDni(bufferCliente.cuit, CUIT_LEN, "\nCuit:\n", "\nERROR",2) == 0){
				respuesta = 0;
				bufferCliente.id = *id;
				bufferCliente.isEmpty = 0;
				array[indice] = bufferCliente;
				(*id)++;
			}
	}
	return respuesta;
}

/**
 * \brief Actualiza los datos de un cliente en una posicion del array
 * \param array Array de clientes a ser actualizado
 * \param limite Limite del array de clientes
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int cli_modificarArray(Cliente* array, int limite, int indice){
	int respuesta = -1;
	Cliente bufferCliente;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && array[indice].isEmpty == 0){
		if(	utn_getNombre(bufferCliente.nombre, NOMBRE_LEN, "\nNombre:\n", "\nERROR\n", 2) == 0 &&
			utn_getNombre(bufferCliente.apellido, NOMBRE_LEN, "\nDireccion:\n", "\nERROR\n", 2) == 0 &&
			utn_getDni(bufferCliente.cuit, CUIT_LEN, "\nCuit?\n", "\nERROR\n", 2) == 0){
				respuesta = 0;
				bufferCliente.id = array[indice].id;
				bufferCliente.isEmpty = 0;
				array[indice] = bufferCliente;
			}
	}
	return respuesta;
}

/**
 * \brief Actualiza una posicion del array
 * \param array Array de clientes a ser actualizado
 * \param limite Limite del array de clientes
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int cli_bajaArray(Cliente* array, int limite, int indice){
	int respuesta = -1;
	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && array[indice].isEmpty == 0){
		array[indice].isEmpty = 1;
		respuesta = 0;
	}
	return respuesta;
}


/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array cliente Array de cliente
* \param limite int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int cli_buscarId(Cliente array[], int limite, int valorBuscado){
	int respuesta = -1;
	if(array != NULL && limite > 0 && valorBuscado >= 0){
		for(int i = 0 ; i < limite ; i++){
			if(array[i].id == valorBuscado){
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}

/**
 * \brief Buscar primer posicion vacia
 * \param array Array de clientes
 * \param limite Limite del array de clientes
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */
int cli_getEmptyIndex(Cliente* array,int limite){
	int respuesta = -1;
	if(array != NULL && limite > 0){
		for(int i = 0 ; i < limite ; i++){
			if(array[i].isEmpty == 1){
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}

/**
 * \brief Ordenar el array de clientes por nombre
 * \param array Array de clientes
 * \param limite Limite del array de clientes
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */
int cli_ordenarPorNombre(Cliente* array,int limite){
	int respuesta = -1;
	int flagSwap;
	Cliente buffer;
	if(array != NULL && limite > 0){
		do{
			flagSwap = 0;
			for(int i = 0 ; i < limite-1 ; i++){
				if(array[i].isEmpty || array[i+1].isEmpty){
					continue;
				}
				if(strncmp(array[i].nombre,array[i+1].nombre,NOMBRE_LEN) > 0){
					flagSwap = 1;
					buffer = array[i];
					array[i] = array[i+1];
					array[i+1]=buffer;
				}
			}
			limite--;
		}while(flagSwap);
	}
	return respuesta;
}












