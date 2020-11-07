#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    char bufferId[2000];
    char bufferNombre[2000];
    char bufferHorasTrabajadas[2000];
    char bufferSueldo[2000];
    Employee *bufferEmp;
    if(pFile!=NULL)
    {
        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferNombre,bufferHorasTrabajadas,bufferSueldo);
            bufferEmp = employee_newParametros(bufferId,bufferNombre,bufferHorasTrabajadas,bufferSueldo);
            if(bufferEmp != NULL)
                ll_add(pArrayListEmployee, bufferEmp);
        }
        retorno = 0;
    }
    return retorno;
}


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    Employee aEmployee;
    Employee *pEmployee = employee_new();
    if(pArrayListEmployee != NULL)
    {
        if(pFile!=NULL)
        {
            while(!feof(pFile))
            {
                pEmployee = employee_newParametrosInt(aEmployee.id,
                                                aEmployee.nombre,
                                                aEmployee.horasTrabajadas,
                                                aEmployee.sueldo);
                fread(&aEmployee, sizeof(Employee), 1, pFile);
                if(pEmployee != NULL)
                {
                    ll_add(pArrayListEmployee, pEmployee);
                }
                else
                {
                    employee_delete(pEmployee);
                }
            }
            fclose(pFile);

            printf("\nCarga exitosa\n");
            retorno = 0;
        }
    }
     return retorno;
}

