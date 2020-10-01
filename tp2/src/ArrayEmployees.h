/*
 * ArrayEmployees.h
 *
 *  Created on: 27 sep. 2020
 *      Author: martin
 */

#define TEXT_SIZE 51

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

typedef struct
{
    int idUnico;
    int isEmpty;
    //-----------------
    char name[TEXT_SIZE];
    int sector;
    float salary;
    char lastName[TEXT_SIZE];

}Employee;


#endif /* ARRAYEMPLOYEES_H_ */

int initEmployees(Employee* list, int len);
int findEmptyEmployee(Employee* list, int len, int* id);
int findEmployeeById(Employee* list,int len, int position, int* id);
int addEmployees(Employee* list, int len, int* id);
int removeEmployee(Employee* list, int len);
int modifyEmployees(Employee* list, int len);
//int employee_ordenar(Employee array[],int size);
int sortEmployees(Employee* list,int len);
//int employee_listar(Employee array[], int size);
int printEmployees(Employee* list, int len);
//int employee_informarSalario(Employee array[], int size);
int reportSalaryEmployee(Employee* list, int len);
void menuPrincipal();
void menuInformes();
