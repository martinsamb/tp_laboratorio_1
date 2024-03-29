#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

#define STR_SIZE 128

typedef struct
{
    int id;
    char nombre[STR_SIZE];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldo);
Employee* employee_newBinario(Employee empleado);

void employee_delete();

int employee_setIdStr(Employee* this,char* id);
int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadasStr(Employee* this,char* horasTrabajadas);
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldoStr(Employee* this,char* sueldo);
int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int employee_cmpId(void* punteroI, void* punteroJ);
int employee_cmpName(void* this1, void* this2);

int employee_searchId(LinkedList* pArrayListEmployee, int valorBuscado, int* index);
int employee_searchMaxId(LinkedList* pArrayListEmployee, int* maxID);

void menuPrincipal();


#endif // employee_H_INCLUDED
