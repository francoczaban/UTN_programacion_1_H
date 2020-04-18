#include "funciones.h"

#include <stdio.h>
#include <stdlib.h>

int validarOpcion(int opcion){
	while(opcion < 1 || opcion > 5){
		printf("\nOpción incorrecta, por favor reingrese: ");
		scanf("%d",&opcion);
	}
	return opcion;
}

int pedirNumero(){
	int numero;
	printf("\nPor favor ingrese un numero: ");
	scanf("%d",&numero);
	return numero;
}

int sumar(int num1, int num2){
	return num1+num2;
}

int restar(int num1, int num2){
	return num1-num2;
}

float dividir(int num1, int num2){
	float rta;
	while(num2 == 0){
		printf("\n el dividendo no puede ser 0, por favor reingrese: ");
		scanf("%d",&num2);
	}
	rta = (float)num1/num2;
	return rta;
}

int multiplicar(int num1, int num2){
	return (num1*num2);
}
int factorial(int num){
	int rta = 0;
	int acum;
	for(int i = num ; i > 1 ; i--){
		acum = num*(num-1);
		rta = acum + rta;
		num--;
	}
	return rta;
}

void imprimirResultados(int rtaSum, int rtaRes, float rtaDiv, int rtaMul, int rtaFacA, int rtaFacB){
	printf("\nResultado A + B = %d"
		   "\nResultado A - B = %d"
		   "\nResultado A / B = %.2f"
		   "\nResultado A * B = %d"
		   "\nResultado A! = %d"
		   "\nResultado B! = %d",rtaSum,rtaRes,rtaDiv,rtaMul,rtaFacA, rtaFacB);
}
