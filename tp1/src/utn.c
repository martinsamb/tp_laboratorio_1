/*
 * utn.c
 *
 *  Created on: 10 sep. 2020
 *      Author: martin
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

/**
 * Función que permite realizar la operación de sumar
 *
 * @param float numeroUno,primer operando recibido
 * @param float numeroDos,segundo operando recibido
 * @return float  resultado, resultado de la función suma
 */
float sumar(float numeroUno,float numeroDos)
{
	float resultado;
	resultado = numeroUno + numeroDos;
	return resultado;
}

/**
 * Función que permite realizar la operación de resta
 *
 * @param float numeroUno,primer operando recibido
 * @param float numeroDos,segundo operando recibido
 * @return float resultado, resultado de la función resta
 */
float restar(float numeroUno, float numeroDos)
{
	float resultado;
	resultado = numeroUno - numeroDos;
	return resultado;
}

/**
 * Función que permite realizar la operación de multiplicación
 *
 * @param float numeroUno,primer operando recibido
 * @param float numeroDos,segundo operando recibido
 * @return float resultado, resultado de la función multiplicación
 */
float multiplicar(float numeroUno, float numeroDos)
{
	float resultado;
	resultado = numeroUno * numeroDos;
	return resultado;
}

/**
 * Función que permite realizar la operación de división,
 * incluye la condición de error al dividir por cero
 *
 * @param float numeroUno,primer operando dividendo
 * @param float numeroDos,segundo operando divisor recibido
 * @return float resultado, resultado de la función división
 */
float dividir(float numeroUno, float numeroDos)
{
	if( numeroDos == 0)
	{
		printf("ERROR: NO SE PUEDE DIVIDIR POR CERO \n");
	}
	else
	{
		float resultado;
		return resultado = (float)numeroUno / numeroDos;

	}
	return 0;
}

/**
 * La función que permite obtener el factorial del primer operando,incluye error por número negativo
 * y resultado 1 del factorial del 0. Si el operando tiene decimales, opera unicamente la parte entera.
 *
 * @param int numeroUno a ser factorizado
 * @param int numeroDos a ser factorizado
 * @return int aux devuelve el resultado de la factorización.
 */


int long factorial(int a)
{
    int i, aux;
    aux = 1;
    for( i = 1; i <= a; i++)
    {
        aux *= i;
    }
    return aux;


}



