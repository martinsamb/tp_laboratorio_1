
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "ArrayEmployees.h"
//#include "sth"

#define  CANT_DIG_MIN   1
#define  CANT_DIG_MAX   10


/** \brief To indicate that all position in the array are empty.
* this function  put the tle flag(isEmpty) in TRUE in all position of the array.
* \param list employee Array of employee
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initEmployees(eVenta* list, int len)
{
    int retorno=-1;
    if(list!= NULL && len>0)
    {
        for(;len>0;len--)
        {
            list[len-1].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Buscar
//Int
/** \brief Find the first empty place in an array
* \param list Employee
* \param len int
* \param id int pointer
* \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
*
*/
int findEmptyEmployee(eVenta* list, int len, int* id)
{
    int retorno=-1;
    int i;
    if(list!= NULL && len>=0 && id!=NULL)
    {
        for(i=0;i<len;i++)
        {
            if(list[i].isEmpty==1)
            {
                retorno=0;
                *id=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief find an Employee by Id en returns the index position in array
* \param list Employee
* \param len int
* \param position int value search
* \param id int Pointer
* \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
*
*/

int findEmployeeById(eVenta* list,int len, int position, int* id)
{
    int retorno = -1;
    int i;
    if(list != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
        	if(list[i].isEmpty==1)
        		continue;
        	else if(list[i].idUnico == position)
            {
                retorno = 0;
                *id=i;
                break;
            }
        }
    }
    return retorno;
}

//*****************************************
//Alta
/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
* \param list employee
* \param len int
* \param id int* Pointer to the ID to be assigned to the new element
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) id Ok.
*
*/
int addEmployees(eVenta* list, int len, int* id)
{
    int retorno=-1;
    int pos;
    if(list!=NULL && len>0 && id!=NULL)
    {
        //if(employee_buscarEmpty(list,len,&posicion)==-1)
        //if(findEmptyEmployee(list,len,&id)==-1)
    	if(findEmptyEmployee(list, len, &pos) == -1)
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
        	if(utn_getName("\nNombre: ","\nError",1, TEXT_SIZE, 1, list[pos].name) == 0 &&
        	   utn_getName("\nApellido: ","\nError",1, TEXT_SIZE, 1, list[pos].lastName) == 0 &&
			   utn_getFloat("\nSalario: ","\nError", 1, 10000, 2,&list[pos].salary) == 0 &&
			   utn_getUnsignedInt("\nSector: ", "\nError",1,sizeof(int),1,&list[pos].sector) == 0)
        	{
				(*id)++;
				list[pos].idUnico=*id;
				list[pos].isEmpty=0;
				printf("\nId: %d\nNombre: %s\nApellido: %s\n Salario: %.2f\nSector: %d",
						list[pos].idUnico,list[pos].name,list[pos].lastName,list[pos].salary,list[pos].sector);
				retorno=0;
        	}
        }
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Remove a Employee by Id(put isEmpty Flag in 1)
* \param list Employee*
* \param len int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can´t find a employee] - (0) if Ok.
*
*/
int removeEmployee(eVenta* list, int len)
{
    int retorno=-1;
    int pos;
    int id;
    if(list!=NULL && len>0)
    {
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,&id);
        if(findEmployeeById(list,len,id,&pos)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            list[pos].isEmpty=1;
            list[pos].idUnico=0;
            list[pos].sector=0;
            list[pos].salary=0;
            strcpy(list[pos].name,"");
            strcpy(list[pos].lastName,"");
            list[pos].salary=0;
            list[pos].sector=0;
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param array employee Array de employee
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int modifyEmployees(eVenta* list, int len)
{
    int retorno=-1;
    int pos;
    int id;
    char opcion;
    if(list!=NULL && len>0)
    {
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,&id);
        if(findEmployeeById(list,len,id,&pos)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            do
            {   //copiar printf de alta
                printf("\nID: %d\nNombre: %s\nApellido: %s\n Salario: %.2f\nSector: %d",
                    list[pos].idUnico,list[pos].name,list[pos].lastName,list[pos].salary,list[pos].sector);
                utn_getLetra("\n\nModificar ID: \n\nA-Nombre \nB-Apellido \nC-Salario \nD-Sector \nS-Salir\n","\nError",1,&opcion);
                switch(opcion)
                {
                    case 'A':
                    	utn_getName("\nNombre: ","\nError",1,TEXT_SIZE,1,list[pos].name);
                        break;
                    case 'B':
                    	utn_getName("\nApellido: ","\nError",1,TEXT_SIZE,1,list[pos].lastName);
                        break;
                    case 'C':
                        utn_getFloat("\nSalario: ","\nError",1,TEXT_SIZE,1,&list[pos].salary);
                        break;
                    case 'D':
                        utn_getUnsignedInt("\nSector: ","\nError",1,TEXT_SIZE,1,&list[pos].sector);
                        break;
                    case 'S':
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
            }while(opcion!='S');
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Ordenar
/** \brief Sort the elements in the array of employees, the argument order indicate UP or DOWN order
* \param list Employee*
* \param len int
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployees(eVenta* list,int len)
{
    int retorno=-1;
    int i, j;
    char bufferApellido[TEXT_SIZE];
    int bufferId;
    int bufferIsEmpty;
    int bufferSector;
    float bufferSalario;
    char bufferNombre[TEXT_SIZE];

    if(list!=NULL && len>=0)
    {
        for (i = 1; i < len; i++)
        {
            strcpy(bufferApellido,list[i].lastName);
            bufferId=list[i].idUnico;
            bufferIsEmpty=list[i].isEmpty;
            bufferSector=list[i].sector;
            bufferSalario=list[i].salary;
            strcpy(bufferNombre,list[i].name);

            j = i - 1;
            while ((j >= 0) && (strcmp(bufferApellido,list[j].lastName)<0 || (strcmp(bufferApellido,list[j].lastName)==0 && bufferSector<list[j].sector)))
            {
                strcpy(list[j + 1].lastName,list[j].lastName);
                list[j + 1].idUnico=list[j].idUnico;
                list[j + 1].isEmpty=list[j].isEmpty;
                list[j + 1].sector=list[j].sector;
                list[j + 1].salary=list[j].salary;
                strcpy(list[j + 1].name,list[j].name);

                j--;
            }
            strcpy(list[j + 1].lastName,bufferApellido);
            list[j + 1].idUnico=bufferId;
            list[j + 1].isEmpty=bufferIsEmpty;
            list[j + 1].sector=bufferSector;
            list[j + 1].salary=bufferSalario;
            strcpy(list[j + 1].name,bufferNombre);
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Listar
/** \brief print the content of employees array
* \param list Employee*
* \param len int
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int printEmployees(eVenta* list, int len)
{
    int retorno=-1;
    int i;

    if(list!=NULL && len>=0)
    {
        for(i=0;i<len;i++)
        {
            if(list[i].isEmpty==0)
            {
                printf("\nID: %d    Nombre: %s  Apellido: %s    Salario: %.2f   Sector: %d",list[i].idUnico,list[i].name,list[i].lastName,list[i].salary,list[i].sector);
            }
        }
        retorno=0;
    }
    return retorno;
}

/** \brief Reports total and average salaries, and how many employees are above average salary.
*\param list Employee*
* \param len int
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int reportSalaryEmployee(eVenta* list, int len)
{
    int retorno=-1;
    int i;
    int contador=0;
    int acumulado=0;

    if(list!=NULL && len>=0)
    {
        for(i=0;i<len;i++)
        {
            if(list[i].isEmpty==0)
            {
                contador++;
                acumulado+=list[i].salary;
            }
        }
        printf("\nTotal salarios: %d",acumulado);
        acumulado/=contador;
        printf("\nSalario promedio: %d",acumulado);
        contador=0;

        for(i=0;i<len;i++)
        {
            if(list[i].isEmpty==0 && list[i].salary>acumulado)
            {
                contador++;
            }
        }
        printf("\nCantidad de empleados que superan el salario promedio: %d",contador);
        retorno=0;
    }
    return retorno;
}

//////////////////////////////////////////////
void menuPrincipal()
{
    printf("\n\nMENU PRINCIPAL\n");
    printf("--------------\n");
    printf("1 - Altas\n");
    printf("2 - Modificar\n");
    printf("3 - Baja\n");
    printf("4 - Informar\n");
    printf("5 - Salir\n");
}

void menuInformes()
{
    printf("\n\nMENU INFORMES\n");
    printf("-------------\n");
    printf("1 - Listado de los empleados ordenados alfabetica por Apellido y Sector\n");
    printf("2 - Total y promedio de los salarios, y cuantos empleados superan el salario promedio\n");
    printf("3 - Salir");
}
