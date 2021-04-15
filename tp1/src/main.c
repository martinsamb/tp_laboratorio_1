/*
 ============================================================================
 Name        : tp1.c
 Author      : Martín Sambrano
 Version     :Trabajo práctico Nro.1
 Copyright   : Your copyright notice
 Description : Calculadora
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main(void)
{
	setbuf(stdout, NULL);
	char seguir = 0;
	int opcion = 0;
	int flagUno = 0;
	int flagDos= 0;
	int flagResultado = 0;
	float numeroUno = 0;
	float numeroDos = 0;
	float factorialUno = 0;
	float factorialDos = 0;
	float suma=0;
	float resta=0;
	float multiplicacion=0;
	float division=0;

	do
	{
		printf("\n Trabajo Nro 1\n");
		if(flagUno == 0)
		{
			printf("\n1- Ingresar 1er numero \n");
		}
		else
		{
			printf("\n1-Ingresar 1er numero: A=%.2f\n",numeroUno);
		}
		if(flagDos == 0)
		{
			printf("\n2- Ingresar 2do. numero\n");
		}
		else
		{
			printf("\n2-Ingresar 2do. numero: B=%.2f\n",numeroDos);
		}
		printf("\n3-Calcular todas las operaciones\n");
		printf("\n4-Informar resultados\n");
		printf("\n5-Salir\n");

		printf("Ingrese la opcion 1 - 5\n");
		fflush(stdin);
		scanf("%d", &opcion);

		switch(opcion)
		{
			case 1:
				printf("\nIngrese un primer numero\n");
				fflush(stdin);
				scanf("%f", &numeroUno);
				flagUno = 1;
				break;

			case 2:
				printf("\nIngrese un segundo numero\n");
				fflush(stdin);
				scanf("%f", &numeroDos);
				flagDos = 1;
				break;

			case 3:
				if(flagUno == 1 && flagDos == 1)
				{
					suma = sumar(numeroUno, numeroDos);
					resta = restar(numeroUno, numeroDos);
					division = dividir(numeroUno, numeroDos);
					multiplicacion = multiplicar(numeroUno, numeroDos);
					factorialUno = factorial(numeroUno);
					factorialDos = factorial(numeroDos);
					flagResultado = 1;
					printf("\n Calculo exitoso\n");

				}
				else
				{
					printf("\nDebe ingresar ambos numeros\n");
				}

				break;

			case 4:
				if(flagUno == 0 && flagDos == 0 && flagResultado == 0)
				{
					printf("\nError, No puede mostrar calculos");
				}
				else
				{
					printf("El resultado de la suma es: %.2f\n", suma);
					printf("\nEl resultado de la resta es: %.2f\n", resta);
					printf("\nEl resultado de la multiplicacion es: %.2f\n", multiplicacion);
					if(numeroDos == 0)
					{
						printf("\nNo es posible dividir por 0\n");
					}
					else
					{
						printf("\nEl resultado de la division es: %.2f\n", division);
					}
					if(numeroUno < 0)
					{
						printf("Error: No existe un factorial de un numero negativo\n");
					}
					else
					{
						factorialUno = factorial(numeroUno);
						printf("\nEl factorial de %d es: %.2f\n", (int)numeroUno, factorialUno);
					}
					if(numeroDos < 0)
					{
						printf("Error: No existe un factorial de un numero negativo\n");
					}
					else
					{
						factorialDos = factorial(numeroDos);
						printf("\nEl factorial de %d es: %.2f\n", (int)numeroDos, factorialDos);
					}
				}
				break;

			case 5:
				seguir = 1;
				break;
			default:
				printf("\nNo ingreso un número 1-5 valido. Intente de nuevo\n");
				seguir = 0;
				break;
		}
	}
	while (seguir == 0);

	return EXIT_SUCCESS;
}

