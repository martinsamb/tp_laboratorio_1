
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

}eVenta;


#endif /* ARRAYEMPLOYEES_H_ */

int initEmployees(eVenta* list, int len);
int findEmptyEmployee(eVenta* list, int len, int* id);
int findEmployeeById(eVenta* list,int len, int position, int* id);
int addEmployees(eVenta* list, int len, int* id);
int removeEmployee(eVenta* list, int len);
int modifyEmployees(eVenta* list, int len);
int sortEmployees(eVenta* list,int len);
int printEmployees(eVenta* list, int len);
int reportSalaryEmployee(eVenta* list, int len);
void menuPrincipal();
void menuInformes();
