#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"

/** \brief Reserva espacio en memoria para un empleado
 *
 * \param void
 * \return Employee*
 *
 */
Employee* employee_new(void)       //constructor         //nuevo empleado
{
    return (Employee*) malloc(sizeof(Employee));
}

/** \brief Valida los campos y los carga en una variable Employee
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param horasTrabajadasStr char*
 * \param sueldoStr char*
 * \return Employee*
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* retorno=NULL;
    Employee* bufferP;

    if(idStr!=NULL && nombreStr!=NULL && horasTrabajadasStr!=NULL && sueldoStr!=NULL)
    {
        bufferP=employee_new();
        if(bufferP!=NULL)
        {
            if(!employee_setIdStr(bufferP,idStr) &&
                !employee_setNombre(bufferP,nombreStr) &&
                !employee_setHorasTrabajadasStr(bufferP,horasTrabajadasStr) &&
                !employee_setSueldoStr(bufferP,sueldoStr))
            {
                retorno=bufferP;
            }
            else
            {
                employee_delete(bufferP);
            }
        }
    }
    return retorno;
}

/** \brief Valida los campos y los carga en una variable Employee
 *
 * \param empleado Employee
 * \return Employee*
 *
 */
Employee* employee_newBinario(Employee empleado)
{
    Employee* retorno=NULL;
    Employee* bufferP;

    char arrayBuffers[3][STR_SIZE];

    sprintf(arrayBuffers[0],"%d",empleado.id);
    sprintf(arrayBuffers[1],"%d",empleado.horasTrabajadas);
    sprintf(arrayBuffers[2],"%d",empleado.sueldo);

    if(arrayBuffers[0]!=NULL && empleado.nombre!=NULL && arrayBuffers[1]!=NULL && arrayBuffers[2]!=NULL)
    {
        bufferP=employee_new();
        if(bufferP!=NULL)
        {
            if(!employee_setIdStr(bufferP,arrayBuffers[0]) &&
                !employee_setNombre(bufferP,empleado.nombre) &&
                !employee_setHorasTrabajadasStr(bufferP,arrayBuffers[1]) &&
                !employee_setSueldoStr(bufferP,arrayBuffers[2]))
            {
                retorno=bufferP;
            }
            else
            {
                employee_delete(bufferP);
            }
        }
    }
    return retorno;
}

/** \brief Libera el espacio reservado en memoria para un empleado
 *
 * \param this Employee*
 * \return void
 *
 */
void employee_delete(Employee* this)
{
    if(this!=NULL)
    {
        free(this);
    }
}

//********************************************************************************************************************
//Setter+getters


/** \brief Valida un campo y lo carga en la variable Employee
 *
 * \param this Employee*
 * \param id char*
 * \return int
 *
 */
int employee_setIdStr(Employee* this,char* id)
{
    int retorno=-1;
    if(this!=NULL && id!=NULL && isValidNumber(id))
    {
        retorno=employee_setId(this,atoi(id));
    }
    return retorno;
}

/** \brief Valida un campo y lo carga en la variable Employee
 *
 * \param this Employee*
 * \param id int
 * \return int
 *
 */
int employee_setId(Employee* this,int id)
{
    int retorno=-1;
    if(this!=NULL && id>=0)
    {
        this->id=id;
        retorno=0;
    }
    return retorno;
}

/** \brief Devulve el valor contenido en un campo de una variable Employee
 *
 * \param this Employee*
 * \param id int*
 * \return int
 *
 */
int employee_getId(Employee* this,int* id)
{
    int retorno=-1;
    if(this!=NULL && id!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

/** \brief Valida un campo y lo carga en la variable Employee
 *
 * \param this Employee*
 * \param nombre char*
 * \return int
 *
 */
int employee_setNombre(Employee* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL && isValidName(nombre))
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}

/** \brief Devulve el valor contenido en un campo de una variable Employee
 *
 * \param this Employee*
 * \param nombre char*
 * \return int
 *
 */
int employee_getNombre(Employee* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}

/** \brief Valida un campo y lo carga en la variable Employee
 *
 * \param this Employee*
 * \param horasTrabajadas char*
 * \return int
 *
 */
int employee_setHorasTrabajadasStr(Employee* this,char* horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL && horasTrabajadas!=NULL && isValidNumber(horasTrabajadas))
    {
        retorno=employee_setHorasTrabajadas(this,atoi(horasTrabajadas));
    }
    return retorno;
}

/** \brief Valida un campo y lo carga en la variable Employee
 *
 * \param this Employee*
 * \param horasTrabajadas int
 * \return int
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL && horasTrabajadas>=0)
    {
        this->horasTrabajadas=horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

/** \brief Devulve el valor contenido en un campo de una variable Employee
 *
 * \param this Employee*
 * \param horasTrabajadas int*
 * \return int
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL && horasTrabajadas!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

/** \brief Valida un campo y lo carga en la variable Employee
 *
 * \param this Employee*
 * \param sueldo char*
 * \return int
 *
 */
int employee_setSueldoStr(Employee* this,char* sueldo)
{
    int retorno=-1;
    if(this!=NULL && sueldo!=NULL && isValidNumber(sueldo))
    {
        retorno=employee_setSueldo(this,atoi(sueldo));
    }
    return retorno;
}

/** \brief Valida un campo y lo carga en la variable Employee
 *
 * \param this Employee*
 * \param sueldo int
 * \return int
 *
 */
int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno=-1;
    if(this!=NULL && sueldo>=0)
    {
        this->sueldo=sueldo;
        retorno=0;
    }
    return retorno;
}

/** \brief Devulve el valor contenido en un campo de una variable Employee
 *
 * \param this Employee*
 * \param sueldo int*
 * \return int
 *
 */
int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno=-1;
    if(this!=NULL && sueldo!=NULL)
    {
        *sueldo=this->sueldo;
        retorno=0;
    }
    return retorno;
}

//*******************************************************************

/** \brief Busca un ID y devuelve el indice
 *
 * \param pArrayListEmployee LinkedList*
 * \param valorBuscado int
 * \param index int*
 * \return int
 *
 */
int employee_searchId(LinkedList* pArrayListEmployee, int valorBuscado, int* index)
{
    int retorno=-1;
    int i;
    int bufferID;
    int size=ll_len(pArrayListEmployee);
    Employee* puntero=NULL;

    if(pArrayListEmployee!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            puntero=ll_get(pArrayListEmployee,i);
            employee_getId(puntero,&bufferID);

            if(valorBuscado==bufferID)
            {
                *index=i;
                retorno=0;
            }
        }
    }
    return retorno;
}

/** \brief Compara dos ID
 *
 * \param this1 void*
 * \param this2 void*
 * \return int
 *
 */
int employee_cmpId(void* this1, void* this2)
{
    int retorno=-1;

    int bufferIdI;
    int bufferIdJ;

    if(this1!=NULL && this2!=NULL)
    {
        employee_getId((Employee*)this1,&bufferIdI);
        employee_getId((Employee*)this2,&bufferIdJ);
        if(bufferIdI==bufferIdJ)
            retorno=0;
        else if(bufferIdI>bufferIdJ)
            retorno=1;
        else if(bufferIdI<bufferIdJ)
            retorno=-1;
    }
    return retorno;
}

/** \brief Compara dos Nombres
 *
 * \param this1 void*
 * \param this2 void*
 * \return int
 *
 */
int employee_cmpName(void* this1, void* this2)
{
    int retorno=-1;

    char bufferI[STR_SIZE];
    char bufferJ[STR_SIZE];

    if(this1!=NULL && this2!=NULL)
    {
        employee_getNombre((Employee*)this1,bufferI);
        employee_getNombre((Employee*)this2,bufferJ);
        if(strcmp(bufferI,bufferJ)==0)
            retorno=0;
        if(strcmp(bufferI,bufferJ)>0)
            retorno=1;
        if(strcmp(bufferI,bufferJ)<0)
            retorno=-1;
    }
    return retorno;
}

/** \brief Busca el maximo ID
 *
 * \param pArrayListEmployee LinkedList*
 * \param maxID int*
 * \return int
 *
 */
int employee_searchMaxId(LinkedList* pArrayListEmployee, int* maxID)
{
    int retorno=-1;
    Employee* puntero=NULL;
    int size=ll_len(pArrayListEmployee);
    int i;
    int bufferId;
    int bufferMaxId=*maxID;

    if(pArrayListEmployee!=NULL && maxID!=NULL)
    {
        for(i=0;i<size;i++)
        {
            puntero=ll_get(pArrayListEmployee,i);
            if(puntero!=NULL)
            {
                employee_getId(puntero,&bufferId);
                if(bufferId>bufferMaxId)
                    bufferMaxId=bufferId;
            }
        }
        *maxID=bufferMaxId;
        retorno=0;
    }
    return retorno;
}

//------------------------------------------------//
void menuPrincipal()
{
     printf("\n MENU PRINCIPAL\n");
     printf("--------------------------------------------------------------------------\n");
     printf("1-Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n");
     printf("2-Cargar los datos de los empleados desde el archivo data.csv (modo binario)\n");
     printf("3-Alta de empleado\n");
     printf("4-Modificar datos de empleado\n");
     printf("5-Baja de empleado\n");
     printf("6-Listar empleados\n");
     printf("7-Ordenar empleados\n");
     printf("8-Guardar los datos de los empleados en el archivo data.csv (modo texto)\n");
     printf("9-Guardar los datos de los empleados en el archivo data.csv (modo binario)\n");
     printf("10-Salir\n");

}


