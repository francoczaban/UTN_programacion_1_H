/*
 ============================================================================
 Name        : PrimerParcialCzabanFranco.c
 Author      : Trap
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "utn.h"
#include "Cliente.h"
#include "Publicaciones.h"

#define CANTIDAD_CLIENTES 100
#define CANTIDAD_PUBLICACIONES 1000

int main(void) {

	Cliente arrayClientes[CANTIDAD_CLIENTES];
	Publicaciones arrayPublicaciones[CANTIDAD_PUBLICACIONES];
	char rta;
	int idClientes = 0;
	int idPublicaciones = 0;
	int opcion;
	int opcionPuntoNueve;
	int opcionPuntoDiez;
	int auxiliarIndice;
	int auxiliarId;
	int auxiliarIdPublicacion;
	int auxiliarIndicePublicacion;
	int avisosActivos;
	int avisosPausados = 0;
	int contAvisos = 0;
	int maxAvisos;
	int cantRubro;
	int rubro;
	int rubroMax;
	int cantActivos;
    int maxActivos;
    int maxActivosRubro;

	if(cli_inicializarArray(arrayClientes, CANTIDAD_CLIENTES) == 0){
		printf("Array inicializado correctamente. \n\n");
	}
	if(pub_inicializarArray(arrayPublicaciones,CANTIDAD_PUBLICACIONES) == 0){
		printf("Array inicializado correctamente. \n\n");
	}

	do{
		if(!utn_getNumero(&opcion,
			"\n\n1.Cargar un Cliente"
			"\n2.Modificar un Cliente"
			"\n3.Eliminar un Cliente"
			"\n4.Publicar un aviso"
			"\n5.Pausar una publicacion"
			"\n6.Reanudar una publicacion"
			"\n7.Imprimir Clientes"
			"\n8.Imprimir publicaciones"
			"\n9.Informar Clientes"
			"\n10.Informar publicaciones"
			"\n11.Salir\n\n",
			"\nError opcion invalida", 1, 11, 2)){

				switch(opcion) {
					case 1:
						auxiliarIndice = cli_getEmptyIndex(arrayClientes, CANTIDAD_CLIENTES);
						if(auxiliarIndice >= 0){
							if(cli_altaArray(arrayClientes, CANTIDAD_CLIENTES, auxiliarIndice, &idClientes) == 0){
								printf("\nCarga realizada con exito\n");
							}
						} else {
							printf("\nNO HAY MAS LUGAR");
						}
						break;

					case 2:
						cli_imprimirArray(arrayClientes, CANTIDAD_CLIENTES);
						if(utn_getNumero(&auxiliarId, "\nIndique el ID del Cliente a modificar", "\nIDCliente invalido", 0, idClientes, 0) == 0){
							auxiliarIndice = cli_buscarId(arrayClientes, CANTIDAD_CLIENTES, auxiliarId);
							if(	auxiliarIndice >= 0 && cli_modificarArray(arrayClientes, CANTIDAD_CLIENTES, auxiliarIndice) == 0){
								printf("\nModificacion realizada con exito\n");
							}
						}
						break;

					case 3:
						cli_imprimirArray(arrayClientes,CANTIDAD_CLIENTES);
						if(utn_getNumero(&auxiliarId, "\nIndique el ID del Cliente a eliminar", "\nIDCliente invalido", 0, idClientes, 0) == 0){
							auxiliarIndice = cli_buscarId(arrayClientes, CANTIDAD_CLIENTES, auxiliarId);
							printf("\nEsta seguro que desea eliminar? (S - N)");
							scanf("%c",&rta);
							__fpurge(stdin);
							while(utn_getChar(rta,'S','N') != 0){
								printf("\nSeleccione una opcion correcta ( S - N)");
								scanf("%c",&rta);
								__fpurge(stdin);
							}
							if(	auxiliarIndice >= 0 && cli_bajaArray(arrayClientes, CANTIDAD_CLIENTES, auxiliarIndice) == 0){
								printf("\nBaja realizada con exito\n");
							}
						}
						break;
					case 4:
						auxiliarIndicePublicacion = pub_getEmptyIndex(arrayPublicaciones,CANTIDAD_PUBLICACIONES);
						if(auxiliarIndicePublicacion >= 0){
							cli_imprimirArray(arrayClientes,CANTIDAD_CLIENTES);
							if(	utn_getNumero(&auxiliarId,"\nId Cliente: ", "\nError", 0, 10000, 2) == 0 &&
								cli_buscarId(arrayClientes,CANTIDAD_CLIENTES,auxiliarId) != -1){
								pub_altaArray(arrayPublicaciones,CANTIDAD_PUBLICACIONES,auxiliarIndicePublicacion,&idPublicaciones,auxiliarId);
							} else {
								printf("\nId ingresado inexistente\n");
							}
						}
						break;

					case 5:
						auxiliarIndicePublicacion = pub_getEmptyIndex(arrayPublicaciones,CANTIDAD_PUBLICACIONES);
						if(auxiliarIndicePublicacion >= 0){
							pub_imprimirArray(arrayPublicaciones,CANTIDAD_PUBLICACIONES);
							if(	utn_getNumero(&auxiliarIdPublicacion,"\nId Publicacion: ", "\nError", 0, 10000, 2) == 0 &&
								pub_buscarId(arrayPublicaciones,CANTIDAD_PUBLICACIONES,auxiliarIdPublicacion) != -1){
								pub_modificarArray(arrayPublicaciones,CANTIDAD_PUBLICACIONES,auxiliarIdPublicacion,0);
							} else {
								printf("\n Id ingresado inexistente\n");
							}
						}
						break;

					case 6:
						auxiliarIndicePublicacion = pub_getEmptyIndex(arrayPublicaciones,CANTIDAD_PUBLICACIONES);
						if(auxiliarIndicePublicacion >= 0){
							pub_imprimirArray(arrayPublicaciones,CANTIDAD_PUBLICACIONES);
							if(	utn_getNumero(&auxiliarIdPublicacion,"\nId Publicacion: ", "\nError", 0, 10000, 2) == 0 &&
								pub_buscarId(arrayPublicaciones,CANTIDAD_PUBLICACIONES,auxiliarIdPublicacion) != -1){
								pub_modificarArray(arrayPublicaciones,CANTIDAD_PUBLICACIONES,auxiliarIdPublicacion,1);
							} else {
								printf("\n Id ingresado inexistente\n");
							}
						}
						break;

					case 7:
							for(int i = 0 ; i < CANTIDAD_CLIENTES ; i++){
								cli_imprimir(&arrayClientes[i]);
								if(arrayClientes[i].isEmpty == 0){
									info_clientesConPublicaciones(arrayClientes[i].id, arrayPublicaciones, CANTIDAD_PUBLICACIONES);
								}
							}
						break;

					case 8:
						for(int i = 0 ; i < CANTIDAD_PUBLICACIONES ; i++){
							if(arrayPublicaciones[i].isEmpty == 0){
								pub_imprimir(&arrayPublicaciones[i]);
								printf("\n- Cuit Cliente: %s",arrayClientes[arrayPublicaciones[i].idCliente].cuit);
							}
						}
						break;
					case 9:
						printf("\n1- Cliente con mas avisos Activos\n2- Cliente con mas avisos Pausados\n3- Cliente con mas avisos :");
						scanf("%d",&opcionPuntoNueve);
						switch (opcionPuntoNueve) {
							case 1:
								maxAvisos = -1;
								for(int i = 0 ; i < CANTIDAD_CLIENTES ; i++){
									cli_imprimir(&arrayClientes[i]);
									if(arrayClientes[i].isEmpty == 0){
										avisosActivos = 0;
										for(int j = 0 ; j < CANTIDAD_PUBLICACIONES ; j++){
											if(arrayClientes[i].id == arrayPublicaciones[j].idCliente && arrayPublicaciones[j].estado == 1){
												avisosActivos++;
											}
										}
										if(avisosActivos > maxAvisos){
											auxiliarId = arrayClientes[i].id;
											maxAvisos = avisosActivos;
										}
									}
								}
								printf("\nCLIENTE CON MAX AVISOS ACTIVOS");
								cli_imprimir(&arrayClientes[auxiliarId]);
								printf("\nCantidad de avisos: %d",maxAvisos);
								break;
							case 2:
								maxAvisos = -1;
								for(int i = 0 ; i < CANTIDAD_CLIENTES ; i++){
									cli_imprimir(&arrayClientes[i]);
									if(arrayClientes[i].isEmpty == 0){
									avisosPausados= 0;
									for(int j = 0 ; j < CANTIDAD_PUBLICACIONES ; j++){
										if (arrayPublicaciones[j].isEmpty == 0){
											if(arrayClientes[i].id == arrayPublicaciones[j].idCliente && arrayPublicaciones[j].estado == 0){
												avisosPausados++;
											}
										}
									}
										if(avisosPausados > maxAvisos){
											auxiliarId = arrayClientes[i].id;
											maxAvisos = avisosPausados;
										}
									}
								}
								printf("\nCLIENTE CON MAX AVISOS PAUSADOS");
								cli_imprimir(&arrayClientes[auxiliarId]);
								printf("\nCantidad de avisos: %d",maxAvisos);
								break;
							case 3:
								maxAvisos = -1;
								for(int i = 0 ; i < CANTIDAD_CLIENTES ; i++){
									cli_imprimir(&arrayClientes[i]);
									if(arrayClientes[i].isEmpty == 0){
									contAvisos= 0;
									for(int j = 0 ; j < CANTIDAD_PUBLICACIONES ; j++){
										if (arrayPublicaciones[j].isEmpty == 0){
											if(arrayClientes[i].id == arrayPublicaciones[j].idCliente){
												contAvisos++;
											}
										}
									}
										if(avisosPausados > maxAvisos){
											auxiliarId = arrayClientes[i].id;
											maxAvisos = contAvisos;
										}
									}
								}
								printf("\nCLIENTE CON MAX AVISOS");
								cli_imprimir(&arrayClientes[auxiliarId]);
								printf("\nCantidad de avisos: %d",maxAvisos);
								break;
						}
						break;

					case 10:
						printf("\n1- Cantidad de publicaciones por rubro\n2- Rubro con mas publicaciones Activas\n3- Rubro con menos publicaciones Activas :");
						scanf("%d",&opcionPuntoDiez);
						switch (opcionPuntoDiez) {
							case 1:
								cantRubro = 0;
								printf("\nPor favor ingrese un rubro: ");
								scanf("%d",&rubro);
								for (int i = 0 ; i < CANTIDAD_PUBLICACIONES ; i ++){
									if (arrayPublicaciones[i].isEmpty == 0){
										if (rubro == arrayPublicaciones[i].rubro){
											cantRubro++;
										}
									}
								}
								printf("\nCantidad de publicaciones del rubro %d: %d", rubro , cantRubro);
								break;

							case 2:
								maxActivos = -1;
								for (int i = 0 ; i < CANTIDAD_PUBLICACIONES ; i ++){
									if (arrayPublicaciones[i].isEmpty == 0){
										cantActivos = 0;
										for (int j = 0 ; j < CANTIDAD_PUBLICACIONES ; j ++){
											if (arrayPublicaciones[j].isEmpty == 0){
												if (arrayPublicaciones[i].rubro == arrayPublicaciones[j].rubro && arrayPublicaciones[j].estado == 1){
													cantActivos++;
													rubroMax = arrayPublicaciones[i].rubro;
												}
											}
										}
										if (cantActivos > maxActivos){
											maxActivos = cantActivos;
											maxActivosRubro = rubroMax;
										}
									}
								}
								printf("\nRubro con mas publicaciones Activas ID %d: Cantidad %d", maxActivosRubro , maxActivos);
								break;

							case 3:
								maxActivos = 10000;
								for (int i = 0 ; i < CANTIDAD_PUBLICACIONES ; i ++){
									if (arrayPublicaciones[i].isEmpty == 0){
										cantActivos = 0;
										for (int j = 0 ; j < CANTIDAD_PUBLICACIONES ; j ++){
											if (arrayPublicaciones[j].isEmpty == 0){
												if (arrayPublicaciones[i].rubro == arrayPublicaciones[j].rubro && arrayPublicaciones[j].estado == 1){
													cantActivos++;
													rubroMax = arrayPublicaciones[i].rubro;
												}
											}
										}
										if (cantActivos < maxActivos){
											maxActivos = cantActivos;
											maxActivosRubro = rubroMax;
										}
									}
								}
								printf("\nRubro con menos publicaciones Activas ID %d: Cantidad %d", maxActivosRubro , maxActivos);
								break;
						}
						break;
					case 11:
						break;
					}
		}
	}while(opcion != 11);

	return EXIT_SUCCESS;
}
