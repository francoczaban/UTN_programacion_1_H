/*
 ============================================================================
 Name        : trabajoPracticoN1.c
 Author      : Czaban Franco
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : Trabajo Practico Calculadora in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "funciones.h"

int main(void){

	int num1 = 0;
	int num2 = 0;
	int opcion, resultadoSuma, resultadoResta, resultadoMultiplicacion,resultadoFactorialA, resultadoFactorialB;
	float resultadoDivision;

	do{
		printf("\nCalculadora\n"
		"1-Ingrese el primer numero (A = %d)\n"
		"2-Ingrese el segundo numero (B = %d)\n"
		"3-Calcular todas las operacioes\n"
		"\ta) Calcular la suma\n"
		"\tb) Calcular la resta\n"
		"\tc) Calcular la division\n"
		"\td) Calcular la multiplicacion\n"
		"\te) Calcular el factorial de ambos numeros ingresados\n"
		"4-Informar resultados\n"
		"5-Salir\n",num1,num2);
		scanf("%d",&opcion);

		opcion = validarOpcion(opcion);

		switch (opcion) {
			case 1: num1 = pedirNumero();
				break;
			case 2: num2 = pedirNumero();
				break;
			case 3: resultadoSuma = sumar(num1, num2);
					resultadoResta = restar(num1, num2);
					resultadoDivision = dividir(num1, num2);
					resultadoMultiplicacion = multiplicar(num1, num2);
					resultadoFactorialA = factorial(num1);
					resultadoFactorialB = factorial(num2);
				break;
			case 4:
					imprimirResultados(resultadoSuma, resultadoResta, resultadoDivision,resultadoMultiplicacion,resultadoFactorialA, resultadoFactorialB);
				break;
			case 5:
				break;

		}

	}while(opcion != 5);

	return EXIT_SUCCESS;
}
