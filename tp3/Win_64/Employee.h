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
Employee* employee_newParametrosInt(int id, char* nombreStr,int horasTrabajadas, int sueldo);
Employee* employee_newBinario(Employee empleado);

void employee_delete();

int employee_setIdStr(Employee* this,char* id);
int employee_setId(Employee* this,int id);
int employee_setNombre(Employee* this,char* nombre);
int employee_setHorasTrabajadasStr(Employee* this,char* horasTrabajadas);
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_setSueldoStr(Employee* this,char* sueldo);
int employee_setSueldo(Employee* this,int sueldo);

int employee_getId(Employee* this,int* id);
int employee_getNombre(Employee* this,char* nombre);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);
int employee_getSueldo(Employee* this,int* sueldo);

int employee_compareId(void* punteroA, void* punteroB);
int employee_compareName(void* this1, void* this2);

int employee_searchById(LinkedList* pArrayListEmployee, int valorBuscado, int* index);
int employee_searchMaxId(LinkedList* pArrayListEmployee, int* maxID);

void menuPrincipal();
void menuModificar();


#endif // employee_H_INCLUDED
