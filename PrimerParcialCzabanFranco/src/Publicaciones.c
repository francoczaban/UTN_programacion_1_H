#include "Publicaciones.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const char ESTADOS[2][8] = {"PAUSADO","ACTIVO"};

#include "utn.h"

/**
 * \brief Imprime los datos de un contratacion
 * \param pElemento Puntero al producto que se busca imprimir
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int pub_imprimir(Publicaciones* pElemento){
	int retorno = -1;
	if(pElemento != NULL && pElemento->isEmpty == 0){
		retorno = 0;
		printf("\nPublicacionId: %d \n- Texto: %s \n- ClienteId: %d \n- Rubro: %d \n- Estado: %s",pElemento->idPub,pElemento->texto,pElemento->idCliente,pElemento->rubro,ESTADOS[pElemento->estado]);
	}
	return retorno;
}

/**
 * \brief Imprime el array de contrataciones
 * \param array Array de contrataciones a ser actualizado
 * \param limite Limite del array de contrataciones
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int pub_imprimirArray(Publicaciones* array, int limite){
	int respuesta = -1;
	if(array != NULL && limite > 0){
		respuesta = 0;
		for(int i = 0 ; i < limite ; i++){
			pub_imprimir(&array[i]);
		}
	}
	return respuesta;
}

/**
 * \brief Inicializa el array
 * \param array Array de contrataciones a ser actualizado
 * \param limite Limite del array de contrataciones
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int pub_inicializarArray(Publicaciones* array, int limite){
	int respuesta = -1;
	if(array != NULL && limite > 0){
		respuesta = 0;
		for(int i = 0 ; i < limite ; i++){
			array[i].isEmpty = 1;
		}
	}
	return respuesta;
}

/**
 * \brief Da de alta un contratacion en una posicion del array
 * \param array Array de contrataciones a ser actualizado
 * \param limite Limite del array de contrataciones
 * \param indice Posicion a ser actualizada
 * \param id Identificador a ser asignado al contratacion
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int pub_altaArray(Publicaciones* array,int limite, int indice, int* idPublicacion, int idCliente){
	int respuesta = -1;
	Publicaciones bufferPublicacion;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && idPublicacion != NULL){
		if(	!utn_getNumero(&bufferPublicacion.rubro,"\n Rubro: ", "\nError",1,100,2) &&
			!utn_getDescripcion(bufferPublicacion.texto,TEXTO_LEN,"\nTexto: ", "\nError",2)){
				respuesta = 0;
				bufferPublicacion.estado = 1;
				bufferPublicacion.idCliente = idCliente;
				bufferPublicacion.idPub = *idPublicacion;
				bufferPublicacion.isEmpty = 0;
				array[indice] = bufferPublicacion;
				(*idPublicacion)++;
				pub_imprimir(&bufferPublicacion);
			}
		}
	return respuesta;
}

/**
 * \brief Da de alta un contratacion en una posicion del array de manera forzada
 * \param array Array de contrataciones a ser actualizado
 * \param limite Limite del array de contrataciones
 * \param indice Posicion a ser actualizada
 * \param id Identificador a ser asignado al contratacion
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int pub_altaForzadaArray(Publicaciones* array, int limite, int indice, int* idPub, int* idCliente, char* texto, int* rubro, int* estado){
	int respuesta = -1;
	Publicaciones bufferPublicacion;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && idPub != NULL)
	{
		strncpy(bufferPublicacion.texto,texto,TEXTO_LEN);
		bufferPublicacion.estado = estado;
		bufferPublicacion.rubro = rubro;
		bufferPublicacion.idCliente = idCliente;
		respuesta = 0;
		bufferPublicacion.idPub = *idPub;
		bufferPublicacion.isEmpty = 0;
		array[indice] = bufferPublicacion;
		(*idPub)++;

	}
	return respuesta;
}


/**
 * \brief Actualiza los datos de un contratacion en una posicion del array
 * \param array Array de contrataciones a ser actualizado
 * \param limite Limite del array de contrataciones
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int pub_modificarArray(Publicaciones* array, int limite, int indice, int pausa){
	int respuesta = -1;
	int estado;
	char rta;
	if(array != NULL && limite > 0 && indice < limite && indice >= 0){
		estado = array[indice].estado;
		switch (pausa) {
			case 0:
				if(estado == 0){
					printf("\nLa publicacion ya esta PAUSADA\n");
				} else {
					printf("\nEsta seguro que desea pausar la publicacion?: (S / N)\n");
					scanf("%c",&rta);
					__fpurge(stdin);
					while(utn_getChar(rta,'S','N') != 0){
						printf("\nSeleccione una opcion correcta ( S / N) ");
						scanf("%c",&rta);
						__fpurge(stdin);
						rta = toupper(rta);
					}
					if(rta == 'S' || rta == 's'){
						array[indice].estado = 0;
					}
					printf("\nPublicacion PAUSADA\n");
				}
				break;
			case 1:
				if(estado == 1){
					printf("\nLa publicacion ya se encuentra activa\n");
				} else {
					printf("\nEsta seguro que desea reanudar la publicacion?: (S / N)\n");
					scanf("%c",&rta);
					__fpurge(stdin);
					while(utn_getChar(rta,'S','N') != 0){
						printf("\nSeleccione una opcion correcta ( S / N) ");
						scanf("%c",&rta);
						__fpurge(stdin);
						rta = toupper(rta);
					}
					if(toupper(rta) == 'S'){
						array[indice].estado = 1;
					}
					printf("\nPublicacion ACTIVADA\n");
				}
				break;
		}
	}
	return respuesta;
}



/**
 * \brief Actualiza una posicion del array
 * \param array Array de publicaciones a ser actualizado
 * \param limite Limite del array de publicaciones
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int pub_bajaArray(Publicaciones* array,int limite, int indice)
{
	int respuesta = -1;
	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && array[indice].isEmpty == 0)
	{
		array[indice].isEmpty = 1;
		respuesta = 0;
	}
	return respuesta;
}


/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array publicacion Array de publicacion
* \param limite int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int pub_buscarId(Publicaciones array[], int limite, int valorBuscado)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0 && valorBuscado >= 0)
	{
		for(i=0;i<limite;i++)
		{
			if(array[i].idPub == valorBuscado)
			{
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}

/**
 * \brief Buscar primer posicion vacia
 * \param array Array de publicaciones
 * \param limite Limite del array de publicaciones
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */
int pub_getEmptyIndex(Publicaciones* array, int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			if(array[i].isEmpty == 1)
			{
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}














