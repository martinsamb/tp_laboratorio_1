#define LEN_SIZE 5
#define LEN_NAME 100
#define  LEN_LASTNAME 100

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

typedef struct
{
    int idUnico;
    int isEmpty;
    //-----------------
    char name[LEN_NAME];
    int sector;
    float salary;
    char lastName[LEN_LASTNAME];

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
