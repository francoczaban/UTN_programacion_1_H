/*
 ============================================================================
 Name        : TP2.c
 Author      : Trap
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"
#include "utn.h"
#include "Menu.h"

#define CANT_EMPLEADOS 1000

int main(void) {

	Employee arrayEmployees[CANT_EMPLEADOS];
	int idEmployees=0;
	int auxiliarIndice;
	int auxiliarId;
	int orderEmployee;
	int flagOrder;

	if(initEmployees(arrayEmployees,CANT_EMPLEADOS) == 0){
		printf("INICIALIZACION CON EXITO\n");
	}

	do{
		switch(menuPrincipal()){
			case 1:
				auxiliarIndice = emp_getEmptyIndex(arrayEmployees, CANT_EMPLEADOS);
				if(auxiliarIndice >= 0){
					if(add_Employees(arrayEmployees, CANT_EMPLEADOS, auxiliarIndice, &idEmployees) == 0){
						printf("\nCarga realizada con exito\n");
					}
				} else {
					printf("\nERROR NO HAY MAS LUGAR");
				}
			break;
			case 2:
				printEmployees(arrayEmployees, CANT_EMPLEADOS);
				if(utn_getNumero(&auxiliarId, "\nIndique el ID del cliente a modificar: ", "\nID invalido", 0 , idEmployees, 0) == 0){
					auxiliarIndice = findEmployeeById(arrayEmployees, CANT_EMPLEADOS, auxiliarId);
					if(	auxiliarIndice >= 0 && emp_modificarArray(arrayEmployees,CANT_EMPLEADOS,auxiliarIndice) == 0){
						printf("\nModificacion realizada con exito\n");
					}
				}
			break;
			case 3:
				printEmployees(arrayEmployees, CANT_EMPLEADOS);
				if(utn_getNumero(&auxiliarId, "\nIndique el ID del cliente a eliminar", "\nID invalido", 0, idEmployees, 0) == 0){
					auxiliarIndice = findEmployeeById(arrayEmployees, CANT_EMPLEADOS, auxiliarId);
					if(	auxiliarIndice >= 0 && removeEmployee(arrayEmployees,CANT_EMPLEADOS,auxiliarIndice) == 0){
						printf("\nBaja realizada con exito\n");
					}
				}
			break;
			case 4:
				switch(subMenu()){
				case 1:
					printf("\nDesea ordenar Empleados de manera ascendente[1] o descendente[0]?\n");
					scanf("%d",&orderEmployee);
					while(orderEmployee != 1 || orderEmployee != 0){
						printf("\nERROR ingrese una opcion correcta: ");
						scanf("%d",&orderEmployee);
					}
					flagOrder = sortEmployees(arrayEmployees, CANT_EMPLEADOS,orderEmployee);
					if(flagOrder >= 0){
						printf("\nSe ordeno con exito\n");
						printEmployees(arrayEmployees, CANT_EMPLEADOS);
					}
				break;
				case 2:
					emp_informarTotalyPromedio(arrayEmployees, CANT_EMPLEADOS);
				break;
			case 5:
				return 0;
			break;
			}
		}
	}while(auxiliarIndice != 5);

	return EXIT_SUCCESS;
}
