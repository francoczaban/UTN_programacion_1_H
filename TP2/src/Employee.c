#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Employee.h"
#include "utn.h"
#include "Menu.h"

/**
 * \brief Imprime los datos de un empleado
 * \param pElemento Puntero al producto que se busca imprimir
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int emp_imprimir(Employee* pElemento){
	int retorno=-1;
	if(pElemento != NULL && pElemento->isEmpty == 0){
		retorno=0;
		printf("\nID: %d - %s - %s - %.2f - %i",pElemento->id,pElemento->nombre,pElemento->apellido,pElemento->salario,pElemento->sector);
	}
	return retorno;
}

/**
 * \brief Imprime el array de empleados de forma encolumnada.
 * \param list Array de empleados a ser actualizado
 * \param len Limite del array de empleados
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int printEmployees(Employee* list, int len){
	int respuesta = -1;
	if(list != NULL && len > 0){
		respuesta = 0;
		for(int i = 0; i < len ; i++){
			emp_imprimir(&list[i]);
		}
	}
	return respuesta;
}

/**
 * \brief Para indicar que todas las posiciones del array están vacías, esta función pone la bandera
 * \(isEmpty) en TRUE en todas las posiciones del array
 * \param list Array de empleados a ser actualizado
 * \param len Limite del array de empleados
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int initEmployees(Employee* list, int len){
	int respuesta = -1;
	if(list != NULL && len > 0){
		respuesta = 0;
		for(int i = 0 ; i < len ; i++){
			list[i].isEmpty = 1;
		}
	}
	return respuesta;
}

/**
 * \brief Da de alta un empleado en una posicion del array
 * \param list Array de empleados a ser actualizado
 * \param limite Limite del array de empleados
 * \param indice Posicion a ser actualizada
 * \param id Identificador a ser asignado a la Employee
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int add_Employees(Employee* list, int len, int indice, int* id){
	int respuesta = -1;
	Employee bufferEmployee;

	if(list != NULL && len > 0 && indice < len && indice >= 0 && id != NULL){
		if(	utn_getNombre(bufferEmployee.nombre,NOMBRE_LEN,"\nIngrese Nombre: ","\nERROR Nombre demasiado extenso.\n",2) == 0 &&
			utn_getDescripcion(bufferEmployee.apellido,NOMBRE_LEN,"\nIngrese Apellido: ","\nERROR Apellido demasiado extenso.\n",2) == 0 &&
			utn_getNumeroFlotante(&bufferEmployee.salario,"\nIngrese Salario: ","\nERROR el salario no puede superar los $100.000\n",0,100000,2) == 0 &&
			utn_getNumero(&bufferEmployee.sector,"\nIngrese Sector: ","\nERROR El sector no puede superar el numero 1.000\n",0,1000,2)==0){
				respuesta = 0;
				bufferEmployee.id = *id;
				bufferEmployee.isEmpty = 0;
				list[indice] = bufferEmployee;
				(*id)++;
			}
		}
	return respuesta;
}

/**
 * \brief Actualiza los datos de un empleado en una posicion del array
 * \param array Array de empleados a ser actualizado
 * \param limite Limite del array de empleados
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int emp_modificarArray(Employee* array,int limite, int indice){
	int respuesta = -1;
	Employee bufferEmployee;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && array[indice].isEmpty == 0){
		if(	utn_getNombre(bufferEmployee.nombre,NOMBRE_LEN,"\nIngrese Nombre: ","\nERROR Nombre demasiado extenso.\n",2) == 0 &&
			utn_getDescripcion(bufferEmployee.apellido,NOMBRE_LEN,"\nIngrese Apellido: ","\nERROR Apellido demasiado extenso.\n",2) == 0 &&
			utn_getNumeroFlotante(&bufferEmployee.salario,"\nIngrese Salario: ","\nERROR El salario no puede superar los $100.000\n",0,100000,2) == 0 &&
			utn_getNumero(&bufferEmployee.sector,"\nIngrese Sector: ","\nERROR El sector no puede superar el numero 1.000\n",0,1000,2)==0){
				respuesta = 0;
				bufferEmployee.id = array[indice].id;
				bufferEmployee.isEmpty = 0;
				array[indice] = bufferEmployee;
			}
		}
	return respuesta;
}

/**
 * \brief Elimina de manera lógica (isEmpty Flag en 1) un empleado recibiendo como parámetro su Id.
 * \param list Array de empleados a ser actualizado
 * \param len Limite del array de empleados
 * \param id Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int removeEmployee(Employee* list,int len, int id){
	int respuesta = -1;
	if(list != NULL && len > 0 && id < len && id >= 0 && list[id].isEmpty == 0){
		list[id].isEmpty = 1;
		respuesta = 0;
	}
	return respuesta;
}


/** \brief Busca un empleado recibiendo como parámetro de búsqueda su Id.
* 	\param employee list Array de empleado
* 	\param int len Tamaño del array
* 	\param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* 	\return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int findEmployeeById(Employee list[], int len, int id){
	int respuesta = -1;
	if(list != NULL && len > 0 && id >= 0){
		respuesta = 0;
		for(int i = 0 ; i < len ; i++){
			if(list[i].id == id){
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}

/**
 * \brief Buscar primer posicion vacia
 * \param array Array de empleados
 * \param limite Limite del array de empleados
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */
int emp_getEmptyIndex(Employee* array,int limite){
	int respuesta = -1;
	if(array != NULL && limite > 0){
		respuesta = 0;
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
 * \brief Ordenar el array de empleados por apellido y sector de manera ascendente
 * o descendente
 * \param array Array de empleados
 * \param limite Limite del array de empleados
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */

int sortEmployees(Employee* list,int len, int order){
	Employee auxEmployee;
	int retorno = -1;

	if(order == 0){
		for(int i = 0 ; i < len ; i++){
			if(list[i].isEmpty == 0){
				for(int j = 0 ; j < len ; j++){
					if(strncmp(list[i].apellido, list[j].apellido, NOMBRE_LEN) > 0){
						auxEmployee = list[i];
						list[i] = list[j];
						list[j] = auxEmployee;
						retorno = 0;
					}
					if(strncmp(list[i].apellido, list[j].apellido, NOMBRE_LEN) == 0){
						if(list[i].sector < list[j].sector){
							auxEmployee = list[i];
							list[i] = list[j];
							list[j] = auxEmployee;
							retorno = 0;
						}
					}
				}
			}
		}
	} else {
		for(int i = 0 ; i < len ; i++){
			if(list[i].isEmpty == 0){
				for(int j = 0 ; j < len ; j++){
					if(strncmp(list[i].apellido, list[j].apellido, NOMBRE_LEN) < 0){
						auxEmployee = list[i];
						list[i] = list[j];
						list[j] = auxEmployee;
						retorno = 0;
					}
					if(strncmp(list[i].apellido, list[j].apellido, NOMBRE_LEN) == 0){
						if(list[i].sector > list[j].sector){
							auxEmployee = list[i];
							list[i] = list[j];
							list[j] = auxEmployee;
							retorno = 0;
						}
					}
				}
			}
		}
	}
	return retorno;
}



/**
 * \brief Calcula el total acumulado de Salarios y el promedio total
 * 	y lo imprime en pantalla.
 * \param array Array de empleados
 * \param limite Limite del array de empleados
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */
void emp_informarTotalyPromedio(Employee* array,int limite){
	float promedio;
	int contador = 0;
	int acumulador = 0;
	int contadorEmpleados = 0;

	if(array != NULL && limite > 0){
		for(int i = 0; i < limite; i++){
			if(array[i].isEmpty == 0){
				acumulador = acumulador + array[i].salario;
				contadorEmpleados++;
			}
		}

		promedio = acumulador / (float)contadorEmpleados;

		for(int j = 0; j < limite ; j++){
			if(array[j].isEmpty == 0){
				if(array[j].salario > promedio){
					contador++;
				}
			}
		}

		printf("\nTOTAL SALARIOS: %d",acumulador);
		printf("\nPROMEDIO SALARIOS: %f",promedio);
		printf("\nCANTIDAD DE EMPLEADOS QUE SUPERAN SALARIO PRIOMEDIO: %d",contador);
	}
}
