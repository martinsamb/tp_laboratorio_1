/*
 ============================================================================
 Name        : tp2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style

-No admite nombres compuestos.#
-No muestra nunca aquién se está modificando/dando de baja.
-Al modificar hay un print que pide modificar el id.
-Luego de modificar, dar de baja y de alta un nuevo empleado, se borran los restantes.
-El programa comienza a comportarse de forma extraña y termina rompiendo en tiempo de
 ejecución.
-En una segunda ejecución de las pruebas no dio de alta al
 último empleado, aunque se intentó varias veces.

 ============================================================================
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "ArrayEmployees.h"


#define QTY_ARRAY_TIPO 1000
#define SORT_UP 1
#define SORT_DOWN 0

int main()
{
	setbuf(stdout, NULL);
    int opcion;
    int opcionOrdenar;
    int contadorIdemployee=0;
    int flag=0;

    eVenta arrayEmployee[QTY_ARRAY_TIPO];
    initEmployees(arrayEmployee, QTY_ARRAY_TIPO);

    //*******************************************************************
    /*
    arrayEmployee[0].idUnico=0;
    arrayEmployee[0].isEmpty=0;
    arrayEmployee[0].sector=0;
    arrayEmployee[0].salary=0;
    strcpy(arrayEmployee[0].name,"CCCCC");
    strcpy(arrayEmployee[0].lastName,"CCCCC");
    contadorIdemployee++;

    arrayEmployee[1].idUnico=1;
    arrayEmployee[1].isEmpty=0;
    arrayEmployee[1].sector=0;
    arrayEmployee[1].salary=0;
    strcpy(arrayEmployee[1].name,"AAAAA");
    strcpy(arrayEmployee[1].lastName,"AAAAA");
    contadorIdemployee++;

    arrayEmployee[2].idUnico=0;
    arrayEmployee[2].isEmpty=0;
    arrayEmployee[2].sector=0;
    arrayEmployee[2].salary=20;
    strcpy(arrayEmployee[2].name,"BBBBB");
    strcpy(arrayEmployee[2].lastName,"BBBBBB");
    contadorIdemployee++;

    arrayEmployee[3].idUnico=0;
    arrayEmployee[3].isEmpty=0;
    arrayEmployee[3].sector=0;
    arrayEmployee[3].salary=10;
    strcpy(arrayEmployee[3].name,"BBBBB");
    strcpy(arrayEmployee[3].lastName,"BBBBBB");
    contadorIdemployee++;
	*/

    //********************************************************************

    do
    {
        menuPrincipal();
        //utn_getUnsignedInt("\nOpcion [1-5] ","\nError",1,sizeof(int),1,&opcion);
        utn_getNumero(&opcion,"\nOpcion [1-5] ","\nError",1,5,2);
        switch(opcion)
        {
            case 1: //Alta
            	if(addEmployees(arrayEmployee, QTY_ARRAY_TIPO, &contadorIdemployee)==0)
            	{
                   flag=1;
           	}
                break;

            case 2: //Modificar
                if(flag==0)
                {
                    printf("\nNo se han ingresado empleados aun");
                }
                else
                    modifyEmployees(arrayEmployee, QTY_ARRAY_TIPO);
                break;

            case 3: //Baja
                if(flag==0)
                {
                    printf("\nNo se han ingresado empleados aun");
                }
                else
                	removeEmployee(arrayEmployee, QTY_ARRAY_TIPO);
                break;

            case 4://Informe
                do
                {
                    menuInformes();
                    //utn_getUnsignedInt(" ","\nError",1,sizeof(int),1,&opcionOrdenar);
                    utn_getNumero(&opcionOrdenar,"\nOpcion [1-3] ","\Error",1,3,2);
                    switch(opcionOrdenar)
                    {
                        case 1:
                            if(flag==0)
							{
								printf("\nNo se han ingresado empleados aun");
							}
							else
							{
								sortEmployees(arrayEmployee,QTY_ARRAY_TIPO);
								printEmployees(arrayEmployee,QTY_ARRAY_TIPO);
							}
							break;

                        case 2:
                            if(flag==0)
							{
								printf("\nNo se han ingresado empleados aun");
							}
							else
								reportSalaryEmployee(arrayEmployee, QTY_ARRAY_TIPO);
							break;

                        case 3:
                            break;
                        default:
                            printf("\nOpcion no valida");

                    }
                }while(opcionOrdenar != 3);
                break;

            case 5://Salir
                break;
            default:
                printf("\nOpcion no valida");
        }
    }
    while(opcion!=5);
    return 0;
}
