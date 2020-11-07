#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

  int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = -1;

    FILE* pFile;
    pFile = NULL;
    pFile = fopen(path,"r");

    if(pFile!=NULL)
    {
        if(path != NULL && pArrayListEmployee != NULL)
        {
             if(!parser_EmployeeFromText(pFile , pArrayListEmployee))
             {
                printf("\nCarga exitosa\n");
                fclose(pFile);
                retorno = 0;
             }
        }
     }
     return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

 int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    FILE* pFile;
    pFile = NULL;
    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path, "rb");
        if(!parser_EmployeeFromBinary(pFile ,pArrayListEmployee))
            retorno = 0;
    }
     return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */


int controller_addEmployee(LinkedList* pArrayListEmployee,int* ultimoId)
{
    int retorno=-1;
    char arrayBuffers[4][STR_SIZE];
    Employee* auxPuntero=NULL;

    if(pArrayListEmployee!=NULL)
    {
        utn_getTexto("\nNombre: ","\nError",1,STR_SIZE,1,arrayBuffers[1]);
        utn_getTexto("\nHoras Trabajadas: ","\nError",1,STR_SIZE,1,arrayBuffers[2]);
        utn_getTexto("\nSueldo: ","\nError",1,STR_SIZE,1,arrayBuffers[3]);
        sprintf(arrayBuffers[0],"%d",(*ultimoId)+1);

        auxPuntero=employee_newParametros(arrayBuffers[0],arrayBuffers[1],arrayBuffers[2],arrayBuffers[3]);
        if(auxPuntero!=NULL)
        {
            ll_add(pArrayListEmployee,auxPuntero);
            retorno=0;
            (*ultimoId)++;
            printf("\nAlta exitosa");
        }
    }
    return retorno;
}


/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int id;
    int index;
    int bufferID;
    int bufferHoras;
    int bufferSueldo;
    char bufferNombre[STR_SIZE];
    char bufferModify[STR_SIZE];
    Employee* puntero=NULL;
    int option1;

    if(pArrayListEmployee!=NULL)
    {
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,8,1,&id);
        if(employee_searchById(pArrayListEmployee,id,&index)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            do
            {
                puntero=ll_get(pArrayListEmployee,index);
                employee_getId(puntero,&bufferID);
                employee_getNombre(puntero,bufferNombre);
                employee_getHorasTrabajadas(puntero,&bufferHoras);
                employee_getSueldo(puntero,&bufferSueldo);

                printf("\n ID: %d   Nombre: %s  Horas: %d   Sueldo: %d",bufferID,bufferNombre,bufferHoras,bufferSueldo);

                menuModificar();
                //utn_getLetra("\nModificar: A - Nombre  B - Horas  C - Sueldo  S - Salir\n","\nError",1,&opcion);
                if(utn_getUnsignedInt(" ","\nError",1,sizeof(int),1,&option1)!=0)
                {
                    option1 = 4;
                }
                //int utn_getUnsignedInt(char* msg,char* msgError,int minSize,int maxSize,int reintentos,int* input)
                else
                {
                    switch(option1)
                    {
                        case 1:
                            utn_getName("\nNombre: ","\nError",1,STR_SIZE,1,bufferModify);
                            employee_setNombre(puntero,bufferModify);
                            break;
                        case 2:
                            utn_getTexto("\nHoras: ","\nError",1,sizeof(int),1,bufferModify);
                            employee_setHorasTrabajadasStr(puntero,bufferModify);
                            break;
                        case 3:
                            utn_getTexto("\nSueldo: ","\nError",1,sizeof(int),1,bufferModify);
                            employee_setSueldoStr(puntero,bufferModify);
                            break;

                        case 4:
                            break;
                        default:
                            printf("\nOpcion no valida");
                    }
                }

            }while(option1!= 4);
            retorno=0;
        }
    }
    return retorno;
}


/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int id;
    int index;
    if(pArrayListEmployee!=NULL)
    {
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,8,1,&id);
        if(employee_searchById(pArrayListEmployee,id,&index)==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            ll_remove(pArrayListEmployee,index);
            printf("\nBaja exitosa");
            retorno=0;
        }
    }
    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int i;
    int bufferID;
    int bufferHoras;
    int bufferSueldo;
    char bufferNombre[STR_SIZE];
    int size=ll_len(pArrayListEmployee);
    Employee* puntero;

    if(pArrayListEmployee!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            puntero=ll_get(pArrayListEmployee,i);
            employee_getId(puntero,&bufferID);
            employee_getNombre(puntero,bufferNombre);
            employee_getHorasTrabajadas(puntero,&bufferHoras);
            employee_getSueldo(puntero,&bufferSueldo);

            printf("\n ID: %d   Nombre: %s  Horas: %d   Sueldo: %d",bufferID,bufferNombre,bufferHoras,bufferSueldo);
        }
        retorno=0;
    }
    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    if(pArrayListEmployee!=NULL)
    {
        ll_sort(pArrayListEmployee,employee_compareName,1);
        retorno=0;
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int i;
    Employee* pEmpleado=NULL;
    int retorno=-1;
    FILE *pFile=NULL;
    int bufferID;
    int bufferHoras;
    int bufferSueldo;
    char bufferNombre[STR_SIZE];
    int contador=0;

    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        pFile=fopen(path,"w");
        if(pFile!=NULL)
        {
            for(i=0;i<ll_len(pArrayListEmployee);i++)
            {
                pEmpleado=ll_get(pArrayListEmployee,i);
                employee_getId(pEmpleado,&bufferID);
                employee_getNombre(pEmpleado,bufferNombre);
                employee_getHorasTrabajadas(pEmpleado,&bufferHoras);
                employee_getSueldo(pEmpleado,&bufferSueldo);

                if(fprintf(pFile,"%d,%s,%d,%d\n",bufferID,bufferNombre,bufferHoras,bufferSueldo)>8)
                    contador++;
            }
            retorno=0;
            fclose(pFile);
            printf("\nElementos guardados exitosamente: %d",contador);
        }
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int i;
    Employee* pEmpleado=NULL;
    int retorno=-1;
    FILE *pFile=NULL;
    int contador=0;
    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        pFile=fopen(path,"w");
        if(pFile!=NULL)
        {
            for(i=0;i<ll_len(pArrayListEmployee);i++)
            {
                pEmpleado=ll_get(pArrayListEmployee,i);
                contador+=fwrite(pEmpleado,sizeof(Employee),1,pFile);
            }
            retorno=0;
            fclose(pFile);
            printf("\nElementos guardados correctamente: %d",contador);
        }
    }
    return retorno;
}

