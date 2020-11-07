#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include <time.h>

/*
getString
utn_getName
utn_getNumero
utn_getNumeroConSigno
utn_getNumeroConDecimales
utn_getTelefono
utn_getDNI
utn_getCUIT
utn_getEmail
utn_getTexto
utn_getAlfanumerico
getNumeroAleatorio
utn_getDate
*/

/** \brief Solicita el ingreso de un string y valida su tamaño
* \param msg char* Mensaje a mostrar
* \param msgError char* Mensaje de error a mostrar
* \param min intTamaño minimo del string
* \param max intTamaño minimo del string Tamaño= elementos+1(\0)
* \param reintentos int* Puntero a la cantidad de reintentos para ingresar el string solicitado
* \param resultado char* Puntero a la variable donde se almacena el string ingresado
* \return int Return (-1) si Error [tamaño invalido o NULL pointer] - (0) si Ok
*/
int getString(char* msg, char* msgError, int min, int max, int* reintentos, char* resultado)
{
    int retorno=-1;
    char bufferStr[max+10];

    if(msg!=NULL && msgError!=NULL && min<=max && reintentos>=0 && resultado!=NULL)
    {
        do
        {
            printf("%s",msg);   //no poner salto de linea, se va a pasar en el mensaje por valor
            //fflush(stdin);
            fgets(bufferStr,sizeof(bufferStr),stdin);
            bufferStr[strlen(bufferStr)-1]='\0';

            if(strlen(bufferStr)>=min && strlen(bufferStr)<max)    // tamaño (max) =cantidad de elementos (strlen) + 1(\0)
            {
                strncpy(resultado,bufferStr,max);
                retorno=0;
                break;
            }
            printf("%s 1",msgError);
            (*reintentos)--;
        }
        while((*reintentos)>=0);
    }
    return retorno;
}
//------------------------------
/** \brief Solicita el ingreso de un string y valida su tamaño y su contenido (solo letras)
* \param msg char* Mensaje a mostrar al solicitar el string
* \param msgError char* Mensaje de error a mostrar
* \param min intTamaño minimo del string
* \param max intTamaño maximo del string Tamaño= elementos+1(\0)
* \param reintentos int* Puntero a la cantidad de reintentos para ingresar el string solicitado
* \param resultado char* Puntero a la variable donde se almacena el string ingresado
* \return int Return (-1) si Error [tamaño o contenido invalido o NULL pointer] - (0) si Ok
*/
int utn_getName(char* msg, char* msgError, int min, int max, int reintentos, char* resultado)
{
    int retorno=-1;
    char bufferStr[max];

    if(msg!=NULL && msgError!=NULL && min<=max && reintentos>=0 && resultado!=NULL)
    {
        do
        {
            if(!getString(msg,msgError,min,max,&reintentos,bufferStr)) //==0
            {
                if(isValidName(bufferStr)==1)
                {
                    strncpy(resultado,bufferStr,max);
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s 2",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}
int isValidName(char* stringRecibido)
{
    int retorno=1;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        //printf("%d",i);
        if(stringRecibido[i]<'A' || (stringRecibido[i]>'Z' && stringRecibido[i]<'a') || stringRecibido[i]>'z')// o ((stringRecibido[i]<'A' || (stringRecibido[i]>'Z') && (stringRecibido[i]<'a' || stringRecibido[i]>'z'))
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}

//-----------------------------------------
/** \brief Solicita el ingreso de un numero y valida su tamaño y su contenido (numero sin signo)
* \param msg char* Mensaje a mostrar al solicitar el string
* \param msgError char* Mensaje de error a mostrar
* \param minSize int Tamaño minimo del string
* \param maxSize int Tamaño maximo del string Tamaño= elementos+1(\0)
* \param reintentos int* Puntero a la cantidad de reintentos para ingresar el string solicitado
* \param input int* Puntero a la variable donde se almacena el string ingresado
* \return int Return (-1) si Error [tamaño o contenido invalido o NULL pointer] - (0) si Ok
*/

int utn_getUnsignedInt(char* msg,char* msgError,int minSize,int maxSize,int reintentos,int* input)
{
    int retorno=-1;
    char bufferStr[maxSize];

    if(msg!=NULL && msgError!=NULL && minSize<maxSize && reintentos>=0 && input!=NULL)
    {
        do
        {
            if(!getString(msg,msgError,minSize,maxSize,&reintentos,bufferStr)) //==0 sin errores !0
            {
                if(isValidNumber(bufferStr)==1)
                {
                    *input=atoi(bufferStr);     // unsigned long int strtoul(const char *str, char **end, int base)?
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s 2",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

int isValidNumber(char* stringRecibido)     //podrìa necesitar parametros para validar max y min
{
    int retorno=1;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if(stringRecibido[i]<'0' || stringRecibido[i]>'9')
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}
//-------------------------------------------------
/** \brief Solicita el ingreso de un numero y valida su tamaño y su contenido (numero con signo)
* \param msg char* Mensaje a mostrar al solicitar el string
* \param msgError char* Mensaje de error a mostrar
* \param minSize int Tamaño minimo del string
* \param maxSize int Tamaño maximo del string Tamaño= elementos+1(\0)
* \param reintentos int* Puntero a la cantidad de reintentos para ingresar el string solicitado
* \param input int* Puntero a la variable donde se almacena el string ingresado
* \return int Return (-1) si Error [tamaño o contenido invalido o NULL pointer] - (0) si Ok
*/
int utn_getSignedInt(char* msg, char* msgError, int minSize, int maxSize, int reintentos, int* input)
{
    int retorno=-1;
    char bufferStr[maxSize];

    if(msg!=NULL && msgError!=NULL && minSize<maxSize && reintentos>=0 && input!=NULL)
    {
        do
        {
            if(!getString(msg,msgError,minSize,maxSize,&reintentos,bufferStr)) //==0 sin errores !0
            {
                if(isValidSignedNumber(bufferStr)==1)
                {
                    *input=atoi(bufferStr); // atoi array to int
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s 2",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

int isValidSignedNumber(char* stringRecibido)
{
    int retorno=1;  // para las funciones isValid arranco con verdadero / error!=1
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if((stringRecibido[i]<'0' || stringRecibido[i]>'9') && (stringRecibido[0]!='+' && stringRecibido[0]!='-'))
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}
//*******************************************************
/** \brief Solicita el ingreso de un numero y valida su tamaño y su contenido (numero con decimales)
* \param msg char* Mensaje a mostrar al solicitar el string
* \param msgError char* Mensaje de error a mostrar
* \param minSize int Tamaño minimo del string
* \param maxSize int Tamaño maximo del string Tamaño= elementos+1(\0)
* \param reintentos int* Puntero a la cantidad de reintentos para ingresar el string solicitado
* \param input float* Puntero a la variable donde se almacena el string ingresado
* \return int Return (-1) si Error [tamaño o contenido invalido o NULL pointer] - (0) si Ok
*/
int utn_getFloat(char* msg, char* msgError, int minSize, int maxSize, int reintentos, float* input)
{
    int retorno=-1;
    char bufferStr[maxSize];

    if(msg!=NULL && msgError!=NULL && minSize<maxSize && reintentos>=0 && input!=NULL)
    {
        do
        {
            if(!getString(msg,msgError,minSize,maxSize,&reintentos,bufferStr)) //==0 sin errores !0
            {
                if(isValidFloatNumber(bufferStr)==1)
                {
                    *input=atof(bufferStr); // atof array to float
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s 2",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

int isValidFloatNumber(char* stringRecibido)
{
    int retorno=1;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if((stringRecibido[i]<'0' || stringRecibido[i]>'9') && (stringRecibido[i]!='.'))
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}
//*************************************************************
/** \brief Solicita el ingreso de un numero de telefono y valida su tamaño y su contenido (solo numeros, guiones o espacios)
* \param msg char* Mensaje a mostrar al solicitar el string
* \param msgError char* Mensaje de error a mostrar
* \param minSize int Tamaño minimo del string
* \param maxSize int Tamaño maximo del string Tamaño= elementos+1(\0)
* \param reintentos int* Puntero a la cantidad de reintentos para ingresar el string solicitado
* \param input char* Puntero a la variable donde se almacena el string ingresado
* \return int Return (-1) si Error [tamaño o contenido invalido o NULL pointer] - (0) si Ok
*/
int utn_getTelefono(char* msg, char* msgError, int minSize, int maxSize, int reintentos, char* input)
{
    int retorno=-1;
    char bufferStr[maxSize];

    if(msg!=NULL && msgError!=NULL && minSize<maxSize && reintentos>=0 && input!=NULL)
    {
        do
        {
            if(!getString(msg,msgError,minSize,maxSize,&reintentos,bufferStr)) //==0 sin errores !0
            {
                if(isValidTelephone(bufferStr)==1)
                {
                    strncpy(input,bufferStr,maxSize);
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s 2",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

int isValidTelephone(char* stringRecibido)
{
    int retorno=1;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if((stringRecibido[i]<'0' || stringRecibido[i]>'9') && (stringRecibido[i]!='-' || stringRecibido[i]!=' '))
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}
//***************************************
/** \brief Solicita el ingreso de un DNI y valida su tamaño y su contenido (solo numeros o puntos)
* \param msg char* Mensaje a mostrar al solicitar el string
* \param msgError char* Mensaje de error a mostrar
* \param reintentos int* Puntero a la cantidad de reintentos para ingresar el string solicitado
* \param input char* Puntero a la variable donde se almacena el string ingresado
* \return int Return (-1) si Error [tamaño o contenido invalido o NULL pointer] - (0) si Ok
*/
int utn_getDNI(char* msg, char* msgError, int reintentos, char* input)
{
    int maxSize=11; //con puntos
    int minSize=8;  // sin puntos
    int retorno=-1;
    char bufferStr[maxSize];

    if(msg!=NULL && msgError!=NULL && minSize<maxSize && reintentos>=0 && input!=NULL)
    {
        do
        {
            if(!getString(msg,msgError,minSize,maxSize,&reintentos,bufferStr)) //==0 sin errores !0
            {
                if(isValidDNI(bufferStr)==1)
                {
                    strncpy(input,bufferStr,maxSize);
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s 2",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

int isValidDNI(char* stringRecibido)
{
    int retorno=1;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if((stringRecibido[i]<'0' || stringRecibido[i]>'9') && (stringRecibido[i]!='.'))
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}

//***************************************
/** \brief Solicita el ingreso de un CUIT y valida su tamaño y su contenido (solo numeros y guiones)
* \param msg char* Mensaje a mostrar al solicitar el string
* \param msgError char* Mensaje de error a mostrar
* \param reintentos int* Puntero a la cantidad de reintentos para ingresar el string solicitado
* \param input char* Puntero a la variable donde se almacena el string ingresado
* \return int Return (-1) si Error [tamaño o contenido invalido o NULL pointer] - (0) si Ok
*/
int utn_getCUIT(char* msg, char* msgError, int reintentos, char* input)
{
    int maxSize=14; //con guiones 13 elementos
    int minSize=11;  // sin guiones
    int retorno=-1;
    char bufferStr[maxSize];

    if(msg!=NULL && msgError!=NULL && minSize<maxSize && reintentos>=0 && input!=NULL)
    {
        do
        {
            if(!getString(msg,msgError,minSize,maxSize,&reintentos,bufferStr)) //==0 sin errores !0
            {
                if(isValidCUIT(bufferStr)==1)
                {
                    strncpy(input,bufferStr,maxSize);
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s 2",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

int isValidCUIT(char* stringRecibido)
{
    int retorno=1;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    int i;
    int j;
    char buffer[14];
    strncpy(buffer,stringRecibido,14);

    for(i=0;buffer[i]!='\0';i++)
    {
        if((buffer[i]<'0' || buffer[i]>'9') && (buffer[i]!='-')) // chequeo que solo sean numeros o -
        {
            retorno=0;
            break;
        }

        if(buffer[i]=='-')  //elimino los -
        {
            for(j=i;buffer[j]!='\0';j++)
            {
                strncpy(&buffer[j],&buffer[j+1],1);
            }
        }
    }

    int digitos[10]={2,3,4,5,6,7,2,3,4,5};
    int acumulado = 0;
    int verificador;

    for(i=0;i < strlen(buffer-1); i++)
    {
        acumulado+=buffer[i]*digitos[i];
    }

    verificador=11-(acumulado%11);
	if(verificador == 11)
	{
		verificador = 0;
	}

	if(buffer[11]!=verificador)
    {
        retorno=0;
    }

    //if(stringRecibido[2]!='-' || stringRecibido[11]!='-' || stringRecibido[0]!='2' || stringRecibido[1]!='0' || stringRecibido[1]!='3' || stringRecibido[1]!='4' || stringRecibido[1]!='7')
    return retorno;
}

//*************************************************************
/** \brief Solicita el ingreso de una direccion de e-mail y valida su tamaño y su contenido
* \param msg char* Mensaje a mostrar al solicitar el string
* \param msgError char* Mensaje de error a mostrar
* \param minSize int Tamaño minimo del string
* \param maxSize int Tamaño maximo del string Tamaño= elementos+1(\0)
* \param reintentos int* Puntero a la cantidad de reintentos para ingresar el string solicitado
* \param input char* Puntero a la variable donde se almacena el string ingresado
* \return int Return (-1) si Error [tamaño o contenido invalido o NULL pointer] - (0) si Ok
*/
int utn_getEmail(char* msg, char* msgError, int minSize, int maxSize, int reintentos, char* input)
{
    int retorno=-1;
    char bufferStr[maxSize];

    if(msg!=NULL && msgError!=NULL && minSize<maxSize && reintentos>=0 && input!=NULL)
    {
        do
        {
            if(!getString(msg,msgError,minSize,maxSize,&reintentos,bufferStr)) //==0 sin errores !0
            {
                if(isValidEmail(bufferStr)==1)
                {
                    strncpy(input,bufferStr,maxSize);
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s 2",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

int isValidEmail(char* stringRecibido)
{
    int retorno=1;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if((stringRecibido[i]<'-' && stringRecibido[i]!='+') || (stringRecibido[i]>'9' && stringRecibido[i]<'@') ||
           (stringRecibido[i]>'Z' && stringRecibido[i]!='_' && stringRecibido[i]<'a')|| stringRecibido[i]>'z')
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}

//*************************************************************
/** \brief Solicita el ingreso de un string y valida su tamaño y su contenido (texto)
* \param msg char* Mensaje a mostrar al solicitar el string
* \param msgError char* Mensaje de error a mostrar
* \param minSize int Tamaño minimo del string
* \param maxSize int Tamaño maximo del string Tamaño= elementos+1(\0)
* \param reintentos int* Puntero a la cantidad de reintentos para ingresar el string solicitado
* \param input char* Puntero a la variable donde se almacena el string ingresado
* \return int Return (-1) si Error [tamaño o contenido invalido o NULL pointer] - (0) si Ok
*/
int utn_getTexto(char* msg, char* msgError, int minSize, int maxSize, int reintentos, char* input)
{
    int retorno=-1;
    char bufferStr[maxSize];

    if(msg!=NULL && msgError!=NULL && minSize<maxSize && reintentos>=0 && input!=NULL)
    {
        do
        {
            if(!getString(msg,msgError,minSize,maxSize,&reintentos,bufferStr)) //==0 sin errores !0
            {
                if(isValidTexto(bufferStr)==1)
                {
                    strncpy(input,bufferStr,maxSize);
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s 2",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

int isValidTexto(char* stringRecibido)
{
    int retorno=1;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if(stringRecibido[i]<' ' || stringRecibido[i]>'z')
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}

//*************************************************************
/** \brief Solicita el ingreso de un valor alfanumerico y valida su tamaño y su contenido (solo numeros y letras)
* \param msg char* Mensaje a mostrar al solicitar el string
* \param msgError char* Mensaje de error a mostrar
* \param minSize int Tamaño minimo del string
* \param maxSize int Tamaño maximo del string Tamaño= elementos+1(\0)
* \param reintentos int* Puntero a la cantidad de reintentos para ingresar el string solicitado
* \param input char* Puntero a la variable donde se almacena el string ingresado
* \return int Return (-1) si Error [tamaño o contenido invalido o NULL pointer] - (0) si Ok
*/
int utn_getAlfanumerico(char* msg, char* msgError, int minSize, int maxSize, int reintentos, char* input)
{
    int retorno=-1;
    char bufferStr[maxSize];

    if(msg!=NULL && msgError!=NULL && minSize<maxSize && reintentos>=0 && input!=NULL)
    {
        do
        {
            if(!getString(msg,msgError,minSize,maxSize,&reintentos,bufferStr)) //==0 sin errores !0
            {
                if(isValidAlphanumeric(bufferStr)==1)
                {
                    strncpy(input,bufferStr,maxSize);
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s 2",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

int isValidAlphanumeric(char* stringRecibido)
{
    int retorno=1;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if(stringRecibido[i]<'0' || (stringRecibido[i]>'9' && stringRecibido[i]<'A') || (stringRecibido[i]>'Z' && stringRecibido[i]<'a') || stringRecibido[i]>'z' )
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}

//------------------------------
/** \brief Solicita el ingreso de una letra y valida su tamaño y su contenido
* \param msg char* Mensaje a mostrar al solicitar el string
* \param msgError char* Mensaje de error a mostrar
* \param reintentos int* Puntero a la cantidad de reintentos para ingresar el string solicitado
* \param resultado char* Puntero a la variable donde se almacena el string ingresado
* \return int Return (-1) si Error [tamaño o contenido invalido o NULL pointer] - (0) si Ok
*/
int utn_getLetra(char* msg, char* msgError, int reintentos, char* resultado)
{
    int retorno=-1;
    char bufferChar;
    int min=1;
    int max=sizeof(char)+1;

    if(msg!=NULL && msgError!=NULL && min<=max && reintentos>=0 && resultado!=NULL)
    {
        do
        {
            if(!getString(msg,msgError,min,max,&reintentos,&bufferChar)) //==0
            {
                if(isValidLetra(bufferChar)==1)
                {
                    *resultado=bufferChar;
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s 2",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

int isValidLetra(char charRecibido)
{
    int retorno=1;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    if(charRecibido<'A' || (charRecibido>'Z' && charRecibido<'a') || charRecibido>'z')
        retorno=0;
    return retorno;
}

//***************************************************************************************************
/*
int utn_getNumeroAleatorio(  char* msg,char* msgError,int minSize,int maxSize,int min,int max,int reintentos,int* input)
{
    int retorno=-1;
    char bufferStr[maxSize];

    if(msg!=NULL && msgError!=NULL && minSize<maxSize && min<max && reintentos>=0 && input!=NULL)
    {
        do
        {
            if(!getString(msg,msgError,minSize,maxSize,&reintentos,bufferStr)) //==0 sin errores !0
            {
                if(isValidNumber(bufferStr)==1)
                {
                    *input=atoi(bufferStr);     // unsigned long int strtoul(const char *str, char **end, int base)?
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s 2",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}
*/
char getNumeroAleatorio(int desde , int hasta, int iniciar, int* resultado)
{
    if(iniciar)                                                                 //la primera vez que se llama la funcion inciar=1 para ejecutar strand
        srand (time(NULL));
    *resultado=desde + (rand() % (hasta + 1 - desde));      //rand()
    return 0;
}

//***************************************
/** \brief Solicita el ingreso de una fecha en formato dd/mm/yyyy y valida su tamaño y su contenido
* \param msg char* Mensaje a mostrar al solicitar el string
* \param msgError char* Mensaje de error a mostrar
* \param reintentos int* Puntero a la cantidad de reintentos para ingresar el string solicitado
* \param input char* Puntero a la variable donde se almacena el string ingresado
* \return int Return (-1) si Error [tamaño o contenido invalido o NULL pointer] - (0) si Ok
*/
int utn_getDate(char* msg, char* msgError, int reintentos, char* input)
{
    int maxSize=11;
    int minSize=10;
    int retorno=-1;
    char bufferStr[maxSize];

    if(msg!=NULL && msgError!=NULL && minSize<maxSize && reintentos>=0 && input!=NULL)
    {
        do
        {
            if(!getString(msg,msgError,minSize,maxSize,&reintentos,bufferStr)) //==0 sin errores !0
            {
                if(isValidDate(bufferStr)==1)
                {
                    strncpy(input,bufferStr,maxSize);
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s 2",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

int isValidDate(char* stringRecibido)
{
    int retorno=1;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    int i;
    char buffer[4];
    int contador=0;
    int day;
    int month;
    int year;

    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if((stringRecibido[i]<'0' || stringRecibido[i]>'9') && (stringRecibido[i]!='/')) // chequeo que solo sean numeros o /
        {
            retorno=0;
            break;
        }

        if(stringRecibido[i]=='/')
        {
            contador++;
        }
    }
    if(contador!=2)
        retorno=0;

    if(retorno==0)
        printf("\nError de formato ");
    else
    {
        for(i=0;i<2;i++)
            strcpy(&buffer[i],&stringRecibido[i]);

        day=atoi(buffer);

        for(i=3;i<5;i++)
            strcpy(&buffer[i-3],&stringRecibido[i]);

        month=atoi(buffer);

        for(i=6;i<10;i++)
            strcpy(&buffer[i-6],&stringRecibido[i]);

        year=atoi(buffer);

        if(day>31 || day<1 || month>12 || month<1 || year<1900 || year >2100)
            retorno=0;
        else if((month==4 || month==6 || month==9 || month==11) && day>30)
            retorno=0;
        else if(month==2 && day>29)
            retorno=0;
    }

    return retorno;
}

