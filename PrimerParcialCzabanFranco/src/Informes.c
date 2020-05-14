#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cliente.h"
#include "Publicaciones.h"
#include "utn.h"
#include "Informes.h"
static const char ESTADOS[2][8]={"PAUSADO","ACTIVO"};

int info_imprimirPublicacionesById(Publicaciones* arrayPublicaciones, int limitePublicaciones, Cliente* arrayClientes, int limiteClientes, int* auxiliarIdPublicacion){
	int retorno = -1;
	int indiceArrayCliente;
	int idCliente;
	if(arrayPublicaciones != NULL && limitePublicaciones > 0 && arrayClientes != NULL && limiteClientes > 0 && auxiliarIdPublicacion != NULL){
		for(int i = 0 ; i < limitePublicaciones ; i++){
			if(arrayPublicaciones[i].isEmpty == 0){
				retorno = 0;
				idCliente = arrayClientes[i].id;
				indiceArrayCliente = cli_buscarId(arrayClientes,limiteClientes,idCliente);
//				printf("\n- IdPublicacion: %d \n- IdCliente: %d \n- Texto: %s \n- Estado: %s \n- Rubro: %d",arrayPublicaciones[i].idPub,arrayPublicaciones[i].idCliente,arrayPublicaciones[i].texto,ESTADOS[arrayPublicaciones[i].estado],arrayPublicaciones[i].rubro);
				printf(" \n- %s \n- %s \n- %s",arrayClientes[indiceArrayCliente].nombre,arrayClientes[indiceArrayCliente].apellido,arrayClientes[indiceArrayCliente].cuit);
			}
		}
	}
	return retorno;
}

void info_clientesConPublicaciones(int idCliente, Publicaciones* arrayPublicaciones, int limite){
	int cont = 0;
	for(int i = 0 ; i < limite ; i++){
		if(arrayPublicaciones[i].isEmpty == 0){
			if(idCliente == arrayPublicaciones[i].idCliente){
				cont++;
			}
		}
	}
	printf("\nCantidad de Publicaciones del IDCliente %d : %d",idCliente, cont);
}




