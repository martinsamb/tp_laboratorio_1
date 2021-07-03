/*
 * utn.c
 *
 *  Created on: 11 oct. 2020
 *      Author: marti
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"



/*********Prototipos*********/
static int myGets(char cadena[], int leng);
static int getString(char* array, int len);
static int getInt(int* pResultado);
static int esNumerica(char* cadena, int limite);
static int getFloat(float* pResultado);
static int esNumericaFloat(char* cadena, int limite);
static int getTexto(char* pResultado, int longitud);
static int esTexto(char* cadena,int longitud);
static int getNombre(char* pResultado, int longitud);
static int esNombre(char* cadena,int longitud);
static int getApellido(char* pResultado, int longitud);
static int esApellido(char* cadena,int longitud);
static int getCaracter(char* pResultado, int longitud);
static int esCaracter(char* cadena, int longitud);
static int getDni(char* pResultado, int longitud);
static int getCuit(char* pResultado, int longitud);
static int esDNI(char* cadena, int longitud);
static int esCUIT(char* cadena, int longitud);
static int getTelefono(char* pResultado, int longitud);
static int esTelefono(char* cadena,int longitud);
static int getCaracterSN(char* pResultado, int longitud);
static int esCaracterSN(char* cadena, int longitud);
static int esString(char string[], int leng);

/*********Funciones Estaticas*********/
/*********GET*********/

static int myGets(char cadena[], int leng)
{
	int ret=-1;
	char bufferString[4096]; //le pongo de mas por las dudas.


	if(cadena!=NULL && leng>0)
	{

		fflush(stdin);
		if(fgets(bufferString, sizeof(bufferString), stdin)!=NULL)
		{

			//si alguien apreto enter le pongo el \0
			if(bufferString[strnlen(bufferString, sizeof(bufferString))-1]=='\n')
			{
				bufferString[strnlen(bufferString, sizeof(bufferString))-1]='\0';
			}

			//copio la cadena aux en mi array
			if(strlen(bufferString)<=leng)
			{
				strncpy(cadena, bufferString, leng);
				ret=0;
			}
		}
	}
			return ret;
}


/*
 * \brief 	Lee de stdin hasta que encuentra un \n o hasta que haya copiado en cadena
 * 			un maximo de len-1 caracteres.
 * 	\param array puntero al array donde se copiara la cadena obtenida
 * 	\param len es un entero que define el tamaño de la cadena
 * 	\return retorna 0 en caso de Exito y -1 en caso de ERROR
 * */
static int getString(char* array, int len)
{
	int ret=-1;
	char bufferString[ARRAY_LEN_STRING];
	if(array!=NULL && len>0)
	{
		fflush(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin)!=NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString))<=len)
			{
				strncpy(array,bufferString,len);
				ret=0;
			}
		}
	}
	return ret;
}
/**
 * \brief Obtien un numero entero
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 **/
static int getInt(int* pResultado)
{
    int retorno=-1;
    char bufferString[ARRAY_LEN_INT];
    if( pResultado!=NULL &&
    	!getString(bufferString,sizeof(bufferString)) &&
    	esNumerica(bufferString,sizeof(bufferString)))
	{
		*pResultado = atoi(bufferString);
		retorno=0;

	}
    return retorno;
}
/**
 * \brief Obtiene un numero decimal
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 **/
static int getFloat(float* pResultado)
{
    int retorno=-1;
    char bufferString[ARRAY_LEN_INT];
    if( pResultado!=NULL &&
    	!getString(bufferString,sizeof(bufferString)) &&
		esNumericaFloat(bufferString,sizeof(bufferString)))
	{
		*pResultado = atof(bufferString);
		retorno=0;
	}
    return retorno;
}
/**
 * \brief Obtiene un texto
 * \param pResultado Puntero char al espacio de memoria donde se dejara el resultado de la funcion
 * \param longitud entrero que marca la longitud de la cadena a ingresar.
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR)
 **/
static int getTexto(char* pResultado, int longitud)
{
	int res = -1;
	char bufferString[ARRAY_LEN_STRING];
	if(pResultado!=NULL && longitud>0)
	{
		if( !getString(bufferString,sizeof(bufferString)) &&
		    esTexto(bufferString, sizeof(bufferString)))
		{
			strncpy(pResultado,bufferString,longitud);
			res = 0;
		}
	}
	return res;
}
/**
 * \brief Obtiene un nombre
 * \param pResultado Puntero char al espacio de memoria donde se dejara el resultado de la funcion
 * \param longitud entrero que marca la longitud de la cadena a ingresar.
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR)
 **/
static int getNombre(char* pResultado, int longitud)
{
    int retorno=-1;
    char buffer[ARRAY_LEN_NOMBRE];
    if(pResultado!=NULL && longitud>0)
    {
    	if(	!getString(buffer,sizeof(buffer)) &&
    		esNombre(buffer,sizeof(buffer)) &&
			strnlen(buffer,sizeof(buffer))<longitud)
    	{
    		strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
    }
    return retorno;
}
/**
 * \brief Obtiene un Apellido
 * \param pResultado Puntero char al espacio de memoria donde se dejara el resultado de la funcion
 * \param longitud entrero que marca la longitud de la cadena a ingresar.
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR)
 **/
static int getApellido(char* pResultado, int longitud)
{
    int retorno=-1;
    char buffer[ARRAY_LEN_APELLIDO];
    if(pResultado!=NULL && longitud>0)
    {
    	if(	!getString(buffer,sizeof(buffer)) &&
    		esApellido(buffer,sizeof(buffer)) &&
			strnlen(buffer,sizeof(buffer))<longitud)
    	{
    		strncpy(pResultado,buffer,longitud);
			retorno=0;
		}
    }
    return retorno;
}
/**
 * \brief Obtiene un Caracter
 * \param pResultado Puntero char al espacio de memoria donde se dejara el resultado de la funcion
 * \param longitud entrero que marca la longitud de la cadena a ingresar.
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR)
 **/
static int getCaracter(char* pResultado, int longitud)
{
	int retorno=-1;
    char buffer[LEN_CHAR];
	if(pResultado!=NULL && longitud>0)
	{
		if(	!getString(buffer,sizeof(buffer)) &&
			esCaracter(buffer,sizeof(buffer)) &&
			strnlen(buffer,sizeof(buffer))<longitud)
		{
			strncpy(pResultado,buffer,longitud);
			retorno=0;
		}
	}
	return retorno;
}
/**
 * \brief Obtiene un DNI
 * \param pResultado Puntero char al espacio de memoria donde se dejara el resultado de la funcion
 * \param longitud entrero que marca la longitud de la cadena a ingresar.
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR)
 **/
static int getDni(char* pResultado, int longitud)
{
	int res = -1;
	char bufferString[ARRAY_LEN_DNI];
	if( pResultado != NULL && longitud > 0 &&
	    !getString(bufferString, sizeof(bufferString)) &&
	    esDNI(bufferString, sizeof(bufferString)))
	{
		strncpy(pResultado, bufferString, longitud);
		res = 0;
	}
	return res;
}
/**
 * \brief Obtiene un CUIT
 * \param pResultado Puntero char al espacio de memoria donde se dejara el resultado de la funcion
 * \param longitud entrero que marca la longitud de la cadena a ingresar.
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR)
 **/
static int getCuit(char* pResultado, int longitud)
{
	int res = -1;
	char bufferString[ARRAY_LEN_CUIT];
	if( pResultado != NULL && longitud > 0 &&
	    !getString(bufferString, sizeof(bufferString)) &&
	    esCUIT(bufferString, sizeof(bufferString)))
	{
		strncpy(pResultado, bufferString, longitud);
		res = 0;
	}
	return res;
}
/**
 * \brief Obtiene un Telefono
 * \param pResultado Puntero char al espacio de memoria donde se dejara el resultado de la funcion
 * \param longitud entrero que marca la longitud de la cadena a ingresar.
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR)
 **/
static int getTelefono(char* pResultado, int longitud)
{
	int res = -1;
	char bufferString[ARRAY_LEN_TEL];
	if( pResultado != NULL && longitud > 0 &&
	    !getString(bufferString, sizeof(bufferString)) &&
	    esTelefono(bufferString,sizeof(bufferString)))
	{
		res = 0;
		strncpy(pResultado,bufferString,longitud);
	}
	return res;
}
/**
 * \brief Obtiene un Caracter que solo sea s o n, para validacion
 * \param pResultado Puntero char al espacio de memoria donde se dejara el resultado de la funcion
 * \param longitud entrero que marca la longitud de la cadena a ingresar.
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR)
 **/
static int getCaracterSN(char* pResultado, int longitud)
{
	int retorno=-1;
    char buffer[LEN_CHAR];
	if(pResultado!=NULL && longitud>0)
	{
		if(	!getString(buffer,sizeof(buffer)) &&
			esCaracterSN(buffer,sizeof(buffer)) &&
			strnlen(buffer,sizeof(buffer))<longitud)
		{
			strncpy(pResultado,buffer,longitud);
			retorno=0;
		}
	}
	return retorno;
}
/*********Estaticas Validaciones*********/

static int esString(char string[], int leng)
{
	int ret=-1;
	int i;
	if(string!=NULL && leng>0)
	{
		ret=1; //verdadero, es una palabra

		for(i=0; i<leng && string[i]!='\0'; i++)
		{

			if(string[i]>'z' || string[i]<'a' )
			{ //si esta fuera de rango,devuelvo 0
				ret=0;
				break;
			}
		}//cierro for
	}
	return ret;
}

/**
 * \brief Verifica si la cadena ingresada es numerica, admite solo enteros
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es numerica, 0 (falso) si no lo es y -1 en caso de error
 **/
static int esNumerica(char* cadena, int limite)
{
	int retorno=-1;
	int i;
	if(cadena!=NULL && limite>0)
	{
		retorno = 1;
		for(i=0;i<limite&&cadena[i]!='\0';i++)
		{
			if(i==0 && (cadena[i]=='+' || cadena[i]=='-'))
			{
				continue;
			}
			if(cadena[i]<'0' || cadena[i]>'9')
			{
				retorno = 0;
				printf("ERROR, Ingrese solo numeros enteros.\n");
				break;
			}
		}
	}
	return retorno;
}
/**
 * \brief Verifica si la cadena ingresada es numerica y admite comas
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es numerica, 0 (falso) si no lo es y -1 en caso de error
 **/
static int esNumericaFloat(char* cadena, int limite)
{
	int i=0;
	int retorno = -1;
	int contadorPuntos=0;

	if(cadena != NULL && strlen(cadena) > 0)
	{
		retorno = 1;
		for(i=0 ; cadena[i] != '\0'; i++)
		{
			if(i==0 && (cadena[i] == '-' || cadena[i] == '+'))
			{
				continue;
			}
			if(cadena[i] < '0' || cadena[i] > '9' )
			{
				if(cadena[i] == '.' && contadorPuntos == 0)
				{
					contadorPuntos++;
				}
				else
				{
					if(contadorPuntos>0)
					{
						retorno=0;
						printf("El numero no puede contener mas de una coma.\n");
						break;
					}
					retorno = 0;
					printf("ERROR, Ingrese solo numeros.\n");
					break;
				}
			}
		}
	}
	return retorno;
}
/**
 * \brief Verifica si la cadena ingresada es un texto valido
 * \param cadena char de caracteres a ser analizada
 * \param longitud entero que marca la longitud de la cadena ingresada.
 * \return Retorna 1 (verdadero) si la cadena es un texto valido, 0 (falso) si no lo es.
 **/
static int esTexto(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;
	if(cadena!=NULL && longitud>0)
	{
		for(i=0;cadena[i]!='\0' && i<longitud;i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ) &&
			   (cadena[i] < '0' || cadena[i] > '9') && (cadena[i] != ' ') &&
			   (cadena[i] != ',') && (cadena[i] != '.') &&
			   (cadena[i] != '+') && (cadena[i] != '-') &&
			   (cadena[i] != '?'))
			{
				retorno = 0;
				printf("Error de validacion, usted ingreso un caracter no permitido.\n");
				break;
			}
		}
	}
	return retorno;
}
/**
 * \brief Verifica si la cadena ingresada es un nombre valido
 * \param cadena char de caracteres a ser analizada
 * \param longitud entero que marca la longitud de la cadena ingresada.
 * \return Retorna 1 (verdadero) si la cadena es un nombre valido, 0 (falso) si no lo es.
 **/
static int esNombre(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;
	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if((cadena[i]<'A' || cadena[i]>'Z') && (cadena[i]<'a' || cadena[i]>'z'))
			{
				retorno = 0;
				printf("Error de validacion, usted ingreso un caracter no permitido.\n");
				break;
			}
		}
	}
	return retorno;
}
/**
 * \brief Verifica si la cadena ingresada es un apellido valido
 * \param cadena char de caracteres a ser analizada
 * \param longitud entero que marca la longitud de la cadena ingresada.
 * \return Retorna 1 (verdadero) si la cadena es un nombre valido, 0 (falso) si no lo es.
 **/
static int esApellido(char* cadena,int longitud)
{
	int i=0;
	int retorno=1;
	if(cadena!=NULL && longitud>0)
	{
		for(i=0;cadena[i]!='\0' && i<longitud;i++)
		{
			if((cadena[i]<'A' || cadena[i]>'Z') && (cadena[i]<'a' || cadena[i]>'z') &&
			   (cadena[i]!=' '))
			{
				retorno = 0;
				printf("Error de validacion, usted ingreso un caracter no permitido.\n");
				break;
			}
		}
	}
	return retorno;
}
/**
 * \brief Verifica si la cadena ingresada es un caracter valido
 * \param cadena char de caracteres a ser analizada
 * \param longitud entero que marca la longitud de la cadena ingresada.
 * \return Retorna 1 (verdadero) si la cadena es un nombre valido, 0 (falso) si no lo es.
 **/
static int esCaracter(char* cadena, int longitud)
{
	int i=0;
	int retorno=1;
	if(cadena!=NULL && longitud>0)
	{
		for(i=0;cadena[i]!='\0' && i<longitud; i++)
		{
			if((cadena[i]<'A' || cadena[i]>'Z' ) && (cadena[i]<'a' || cadena[i]>'z'))
			{
				retorno=0;
				printf("Error de validacion, solo puede ingresar un caracter.\n");
				break;
			}
		}
	}
	return retorno;
}
/**
 * \brief Verifica si la cadena ingresada es la letra S o N
 * \param cadena char de caracteres a ser analizada
 * \param longitud entero que marca la longitud de la cadena ingresada.
 * \return Retorna 1 (verdadero) si la cadena es un nombre valido, 0 (falso) si no lo es.
 **/
static int esCaracterSN(char* cadena, int longitud)
{
	int i=0;
	int retorno=1;
	if(cadena!=NULL && longitud>0)
	{
		for(i=0;cadena[i]!='\0' && i<longitud; i++)
		{
			if(cadena[i]!='S' && cadena[i]!='N' && cadena[i]!='s' && cadena[i]!='n')
			{
				retorno=0;
				printf("Error de validacion, solo puede ingresar S o N.\n");
				break;
			}
		}
	}
	return retorno;
}
/**
 * \brief Verifica si la cadena ingresada es un DNI valido
 * \param cadena char de caracteres a ser analizada
 * \param longitud entero que marca la longitud de la cadena ingresada.
 * \return Retorna 1 (verdadero) si la cadena es un nombre valido, 0 (falso) si no lo es.
 **/
static int esDNI(char* cadena, int longitud)
{
	int i=0;
	int retorno = 1;
	long lengthCadena = strlen(cadena);
	int contadorPuntos = 0;
	if(cadena != NULL && longitud > 0)
	{
		for(i=0;cadena[i]!='\0'; i++)
		{
			//Menos de 6 numeros->ERROR
			if(lengthCadena < 6)
			{
				retorno = 0;
				if((cadena[i] < '0' || cadena[i] > '9'))
				{
					printf("El DNI no puede contener letras\n");
					break;
				}
				else
				{
					printf("El DNI no puede tener menos de 6 numeros\n");
					break;
				}
			}
			//Contador de puntos
			if(cadena[i]=='.')
			{
				contadorPuntos++;
			}
			//Si comienza con un punto ERROR
			if(i==0 && cadena[i]=='.')
			{
				retorno = 0;
				printf("El DNI no puede empezar con un punto\n");
				break;
			}
			//Si contiene letras->ERROR
			if((cadena[i] < '0' || cadena[i] > '9') && (cadena[i] != '.'))
			{
				retorno = 0;
				printf("El DNI no puede contener letras\n");
				break;
			}
		}
	}
	if(contadorPuntos == 0)
	{
		retorno = 0;
		printf("El DNI debe contener puntos\n");
	}
	else if(contadorPuntos == 1)
	{
		retorno = 0;
		printf("El DNI debe contener mas de un punto\n");
	}
	else if(contadorPuntos > 2)
	{
		retorno = 0;
		printf("El DNI no puede contener mas de dos puntos\n");
	}
	return retorno;
}
/**
 * \brief Verifica si la cadena ingresada es un CUIT valido
 * \param cadena char de caracteres a ser analizada
 * \param longitud entero que marca la longitud de la cadena ingresada.
 * \return Retorna 1 (verdadero) si la cadena es un nombre valido, 0 (falso) si no lo es.
 **/
static int esCUIT(char* cadena, int longitud)
{
	int i=0;
	int retorno = 1;
	long lengthCadena = strlen(cadena);
	int contadorGuiones = 0;
	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0'; i++)
		{
			//Contador de guiones
			if(cadena[i]=='-')
			{
				contadorGuiones++;
			}
			//Menos de 13 numeros->ERROR
			if(lengthCadena < 13)
			{
				retorno = 0;
				if((cadena[i] < '0' || cadena[i] > '9') && (cadena[i] != '-'))
				{
					printf("El CUIT no puede contener letras\n");
					break;
				}
				else
				{
					printf("El CUIT debe contener 11 numeros y dos guiones\n");
					break;
				}
			}
			//Si comienza con un guion ERROR
			if(i==0 && cadena[i]=='-')
			{
				retorno = 0;
				printf("El CUIT no puede empezar con un guion\n");
				break;
			}
			//Si contiene letras->ERROR
			if((cadena[i] < '0' || cadena[i] > '9') && (cadena[i] != '-'))
			{
				retorno = 0;
				printf("El CUIT no puede contener letras, espacios ni caracteres especiales\n");
				break;
			}
		}
	}
	if(contadorGuiones == 0)
	{
		retorno = 0;
		printf("Respete el formato [xx-xxxxxxxx-x]\n");
	}
	else if(contadorGuiones == 1)
	{
		retorno = 0;
		printf("Respete el formato [xx-xxxxxxxx-x]\n");
	}
	else if(contadorGuiones > 2)
	{
		retorno = 0;
		printf("El CUIT no puede contener mas de dos guiones\n");
	}
	return retorno;
}
/**
 * \brief Verifica si la cadena ingresada es un TELEFONO valido
 * \param cadena char de caracteres a ser analizada
 * \param longitud entero que marca la longitud de la cadena ingresada.
 * \return Retorna 1 (verdadero) si la cadena es un nombre valido, 0 (falso) si no lo es.
 **/
static int esTelefono(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;
	long lengthCadena = strlen(cadena);
	if(cadena!=NULL && longitud>0)
	{
		for(i=0;cadena[i]!='\0' && i<longitud; i++)
		{
			if(lengthCadena<=7)
			{
				retorno = 0;
				printf("El telefono no puede contener menos de 8 numeros\n");
				break;
			}
			if((cadena[i] < '0' || cadena[i] > '9') && (cadena[i] != ' ') &&
			   (cadena[i] != '-'))
			{
				retorno = 0;
				printf("Error de validacion, los telefonos solo contienen numeros, espacios y guiones medios.\n");
				break;
			}
		}
	}
	return retorno;
}
/*********GET*********/
/*
 * \brief Pide un numero al usuario dentro de un rango determinado
 * \param pResultado: puntero a int donde se guarda el valor del dato a mostrar enm el main, el numero.
 * \param pMensaje: puntero a char, donde se pasa el mensaje a mostrar.
 * \param pMensajeerror: puntero a mensaje de error que se le pasa en caso de error.
 * \param minimo y maximo: enteros donde se pasa el rango de numeros a tomar, el minimo aceptado y el maximo aceptado.
 * \param reintentos: entero, es la cantidad de reintentos que tendra el usuario en caso de error.
 * \return devuelve 0 en caso de Exito y -1 en caso de Error.
 * */
int utn_getNumero(int* pResultado, char* pMensaje, char* pMensajeError, int minimo, int maximo, int reintentos)
{
	int ret = -1;
	int bufferInt;
	int i;
	for(i=0;i<=reintentos;i++){
		if(pResultado!=NULL && pMensaje!=NULL && pMensajeError!=NULL && minimo<=maximo && reintentos>0)
		{
			printf("%s", pMensaje);
			if(!getInt(&bufferInt))
			{
				if(bufferInt>=minimo && bufferInt<=maximo)
				{
					*pResultado = bufferInt;
					ret = 0;
					break;
				}
				else
				{
					printf("%s - Fuera de rango\n", pMensajeError);
				}
			}
		}
	}
	return ret;
}
/*
 * \brief Pide un numero decimal al usuario dentro de un rango determinado
 * \param pResultado: puntero a float donde se guarda el valor del dato a mostrar en el main, el numero.
 * \param pMensaje: puntero a char, donde se pasa el mensaje a mostrar.
 * \param pMensajeError: puntero a mensaje de error que se le pasa en caso de error.
 * \param minimo y maximo: floats donde se pasa el rango de numeros a tomar, el minimo aceptado y el maximo aceptado.
 * \param reintentos: entero, es la cantidad de reintentos que tendra el usuario en caso de error.
 * \return devuelve 0 en caso de Exito y -1 en caso de Error.
 * */
int utn_getNumeroFlotante(float* pResultado, char* pMensaje, char* pMensajeError, int minimo, float maximo, float reintentos)
{
	int ret = -1;
	float bufferFloat;
	int i;
	for(i=0;i<=reintentos;i++){
		if(pResultado!=NULL && pMensaje!=NULL && pMensajeError!=NULL && minimo<=maximo && reintentos>0)
		{
			printf("%s", pMensaje);
			if(!getFloat(&bufferFloat))
			{
				if(bufferFloat>=minimo && bufferFloat<=maximo)
				{
					*pResultado = bufferFloat;
					ret = 0;
					break;
				}
				else
				{
					printf("%s - Fuera de rango\n", pMensajeError);
				}
			}
		}
	}
	return ret;
}
/*
 * \brief Pide un texto al usuario.
 * \param pResultado: puntero a char donde se guarda el dato a mostrar en el main.
 * \param longitud entero que marca la longitud de la cadena a ingresar.
 * \param pMensaje: puntero a char, donde se pasa el mensaje a mostrar.
 * \param pMensajeError: puntero a mensaje de error que se le pasa en caso de error.
 * \param reintentos: entero, es la cantidad de reintentos que tendra el usuario en caso de error.
 * \return devuelve 0 en caso de Exito y -1 en caso de Error.
 * */
int utn_getTexto(char* pResultado, int longitud,char* pMensaje, char* pMensajeError, int reintentos)
{
	char bufferString[ARRAY_LEN_STRING];
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",pMensaje);
		if( !getTexto(bufferString,sizeof(bufferString)) &&
			strnlen(bufferString,sizeof(bufferString))<longitud)
		{
			strncpy(pResultado,bufferString,longitud);
			retorno=0;
			break;
		}
		else
		{
			printf("%s",pMensajeError);
		}
	}
	return retorno;
}
/*
 * \brief Pide un Nombre al usuario.
 * \param pResultado: puntero a char donde se guarda el valor a mostrar en el main.
 * \param longitud entero que marca la longitud de la cadena a ingresar.
 * \param pMensaje: puntero a char, donde se pasa el mensaje a mostrar.
 * \param pMensajeError: puntero a mensaje de error que se le pasa en caso de error.
 * \param reintentos: entero, es la cantidad de reintentos que tendra el usuario en caso de error.
 * \return devuelve 0 en caso de Exito y -1 en caso de Error.
 * */
int utn_getNombre(char* pResultado, int longitud,char* pMensaje, char* pMensajeError, int reintentos)
{
	char bufferString[ARRAY_LEN_NOMBRE];
	int retorno=-1;
	int i=0;
	if(pResultado!=NULL && longitud>0 && pMensaje!=NULL && pMensajeError!=NULL && reintentos>0)
	{
		for(i=0;i<=reintentos;i++)
		{
			printf("%s",pMensaje);
			if(	!getNombre(bufferString,sizeof(bufferString)) &&
				strnlen(bufferString,sizeof(bufferString))<longitud)
			{
				strncpy(pResultado,bufferString,longitud);
				retorno=0;
				break;
			}
			printf("%s",pMensajeError);
		}
	}
	return retorno;
}
/*
 * \brief Pide un Apellido al usuario.
 * \param pResultado: puntero a char donde se guarda el valor a mostrar en el main.
 * \param longitud entero que marca la longitud de la cadena a ingresar.
 * \param pMensaje: puntero a char, donde se pasa el mensaje a mostrar.
 * \param pMensajeError: puntero a mensaje de error que se le pasa en caso de error.
 * \param reintentos: entero, es la cantidad de reintentos que tendra el usuario en caso de error.
 * \return devuelve 0 en caso de Exito y -1 en caso de Error.
 * */
int utn_getApellido(char* pResultado, int longitud,char* pMensaje, char* pMensajeError, int reintentos)
{
	char bufferString[ARRAY_LEN_APELLIDO];
	int retorno=-1;
	int i=0;
	if(pResultado!=NULL && pMensaje!=NULL && pMensajeError!=NULL && reintentos>0)
	{
		for(i=0;i<=reintentos;i++)
		{
			printf("%s", pMensaje);
			if( !getApellido(bufferString,sizeof(bufferString)) &&
				strnlen(bufferString,sizeof(bufferString))<longitud)
			{
				strncpy(pResultado,bufferString,longitud);
				retorno=0;
				break;
			}
			printf("%s",pMensajeError);
		}
	}
	return retorno;
}
/*
 * \brief Pide un Caracter al usuario.
 * \param pResultado: puntero a char donde se guarda el valor a mostrar en el main.
 * \param longitud entero que marca la longitud de la cadena a ingresar.
 * \param pMensaje: puntero a char, donde se pasa el mensaje a mostrar.
 * \param pMensajeError: puntero a mensaje de error que se le pasa en caso de error.
 * \param reintentos: entero, es la cantidad de reintentos que tendra el usuario en caso de error.
 * \return devuelve 0 en caso de Exito y -1 en caso de Error.
 * */
int utn_getCaracter(char* pResultado, int longitud,char* pMensaje, char* pMensajeError, int reintentos)
{
	char bufferString[LEN_CHAR];
	int retorno=-1;
	int i=0;
	if(pResultado!=NULL && pMensaje!=NULL && pMensajeError!=NULL && reintentos>0)
	{
		for(i=0;i<=reintentos;i++)
		{
			printf("%s",pMensaje);
			if( !getCaracter(bufferString,sizeof(bufferString)) &&
				strnlen(bufferString,sizeof(bufferString))<longitud )
			{
				strncpy(pResultado,bufferString,longitud);
				retorno = 0;
				break;
			}
			printf("%s",pMensajeError);
		}
	}
	return retorno;
}
/*
 * \brief Pide un DNI al usuario.
 * \param pResultado: puntero a char donde se guarda el valor a mostrar en el main.
 * \param longitud entero que marca la longitud de la cadena a ingresar.
 * \param pMensaje: puntero a char, donde se pasa el mensaje a mostrar.
 * \param pMensajeError: puntero a mensaje de error que se le pasa en caso de error.
 * \param reintentos: entero, es la cantidad de reintentos que tendra el usuario en caso de error.
 * \return devuelve 0 en caso de Exito y -1 en caso de Error.
 * */
int utn_getDni(char* pResultado, int longitud,char* pMensaje, char* pMensajeError, int reintentos)
{
	int retorno = -1;
	char bufferString[ARRAY_LEN_DNI];
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",pMensaje);
		if(!getDni( bufferString,sizeof(bufferString)) &&
				    strnlen(bufferString,sizeof(bufferString))<longitud)
		{
			strncpy(pResultado,bufferString,longitud);
			retorno = 0;
			break;
		}
		printf("%s",pMensajeError);
	}
	return retorno;
}
/*
 * \brief Pide un CUIL al usuario.
 * \param pResultado: puntero a char donde se guarda el valor a mostrar en el main.
 * \param longitud entero que marca la longitud de la cadena a ingresar.
 * \param pMensaje: puntero a char, donde se pasa el mensaje a mostrar.
 * \param pMensajeError: puntero a mensaje de error que se le pasa en caso de error.
 * \param reintentos: entero, es la cantidad de reintentos que tendra el usuario en caso de error.
 * \return devuelve 0 en caso de Exito y -1 en caso de Error.
 * */
int utn_getCuil(char* pResultado, int longitud,char* pMensaje, char* pMensajeError, int reintentos)
{
	int retorno = -1;
	char bufferString[ARRAY_LEN_CUIT];
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",pMensaje);
		if(!getCuit( bufferString,sizeof(bufferString)) &&
				     strnlen(bufferString,sizeof(bufferString))<longitud)
		{
			strncpy(pResultado,bufferString,longitud);
			retorno = 0;
			break;
		}
		printf("%s",pMensajeError);
	}
	return retorno;
}
/*
 * \brief Pide un Telefono al usuario.
 * \param pResultado: puntero a char donde se guarda el valor a mostrar en el main.
 * \param longitud entero que marca la longitud de la cadena a ingresar.
 * \param pMensaje: puntero a char, donde se pasa el mensaje a mostrar.
 * \param pMensajeError: puntero a mensaje de error que se le pasa en caso de error.
 * \param reintentos: entero, es la cantidad de reintentos que tendra el usuario en caso de error.
 * \return devuelve 0 en caso de Exito y -1 en caso de Error.
 * */
int utn_getTelefono(char* pResultado, int longitud,char* pMensaje, char* pMensajeError, int reintentos)
{
	int retorno = -1;
	char bufferString[ARRAY_LEN_TEL];
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",pMensaje);
		if(!getTelefono( bufferString,sizeof(bufferString)) &&
				         strnlen(bufferString,sizeof(bufferString))<longitud)
		{
			strncpy(pResultado,bufferString,longitud);
			retorno = 0;
			break;
		}
		printf("%s",pMensajeError);
	}
	return retorno;
}
/*
 * \brief Pide un Caracter solo S o N al usuario.
 * \param pResultado: puntero a char donde se guarda el valor a mostrar en el main.
 * \param longitud entero que marca la longitud de la cadena a ingresar.
 * \param pMensaje: puntero a char, donde se pasa el mensaje a mostrar.
 * \param pMensajeError: puntero a mensaje de error que se le pasa en caso de error.
 * \param reintentos: entero, es la cantidad de reintentos que tendra el usuario en caso de error.
 * \return devuelve 0 en caso de Exito y -1 en caso de Error.
 * */
int utn_getCaracterSN(char* pResultado, int longitud,char* pMensaje, char* pMensajeError, int reintentos)
{
	char bufferString[LEN_CHAR];
	int retorno=-1;
	int i=0;
	if(pResultado!=NULL && pMensaje!=NULL && pMensajeError!=NULL && reintentos>0)
	{
		for(i=0;i<=reintentos;i++)
		{
			printf("%s",pMensaje);
			if( !getCaracterSN(bufferString,sizeof(bufferString)) &&
				strnlen(bufferString,sizeof(bufferString))<longitud )
			{
				strncpy(pResultado,bufferString,longitud);
				retorno = 0;
				break;
			}
			printf("%s",pMensajeError);
		}
	}
	return retorno;
}

//**********************************************************************************************************/

int utn_getString(char *pResultado, int len, char* mensaje, char* mensajeError, int reintentos)
{

	 int ret=-1;
	 char bufferString[4000];


	 if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && len>0)
	 {
	 while(reintentos>=0)
	 {
		 reintentos--;
		 printf("%s", mensaje);

		 if(myGets(bufferString, sizeof(bufferString))==0 &&esString(bufferString, sizeof(bufferString)))
		 {

			 strncpy(pResultado, bufferString, len);
			 ret=0;
			 break;
		 }

		 else
		 {
			 fflush(stdin);
			 printf("%s", mensajeError);
		 }
	 }//cierro while
	 };//cierro la validacion de los punteros.
	 return ret;
}

//****************************************************************************************************************/

int utn_getCadena(char *pResultado, char *mensaje, char *mensajeError,float minimo, float maximo, int reintentos)
{

	int retorno = -1;
	char bufferCadena[101];

	do {

		printf("%s", mensaje);
		fflush(stdin);
		gets(bufferCadena);

		if (strlen(bufferCadena) >= minimo && strlen(bufferCadena) < maximo)
		{
			strcpy(pResultado, bufferCadena); //pResultado no hace falta ponerle el * porque como es cadena ya es puntero
			retorno = 0;
			break;
		}

		printf("%s", mensajeError);
		reintentos--;

	} while (reintentos <= 0);

	return retorno;
}
