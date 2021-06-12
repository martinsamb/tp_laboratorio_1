#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param pFile FILE*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    Employee* auxPuntero=NULL;
    char arrayBuffers[4][STR_SIZE];

    if(pFile!=NULL)
    {
        if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",arrayBuffers[0],arrayBuffers[1],arrayBuffers[2],arrayBuffers[3])==4)
            retorno=0;
        if(strcmp(arrayBuffers[0],"id")==0)
            retorno=-1;

        if(retorno==0)
        {
            auxPuntero=employee_newParametros(arrayBuffers[0],arrayBuffers[1],arrayBuffers[2],arrayBuffers[3]);         //valido los datos y lo guardo en aux
            if(auxPuntero!=NULL)
            {
                ll_add(pArrayListEmployee,auxPuntero);
                retorno=1;
            }
            else
            {
                retorno=-2;
            }
        }
    }
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param pFile FILE*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    Employee auxEmpleado;
    Employee* pEmpleado;

    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        if(fread(&auxEmpleado,sizeof(Employee),1,pFile)==1)
        {
            pEmpleado=employee_newBinario(auxEmpleado);
            if(pEmpleado!=NULL)
            {
                ll_add(pArrayListEmployee,pEmpleado);
                //printf("\n%d", pEmpleado->id);
                retorno=0;
            }
            else
            {
                retorno=-2;
            }
        }
    }
    return retorno;
}

