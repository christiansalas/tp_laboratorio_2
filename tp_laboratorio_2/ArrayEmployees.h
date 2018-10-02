#ifndef ArrayEmployees_H_INCLUDED
#define ArrayEmployees_H_INCLUDED


struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
}typedef Employees;



int addEmployees(Employees* list, int len);
int initEmployees(Employees* list,int len);
int utn_getNombre(  char* pNombre, int limite, char* msg,
                    char* msgErr, int reintentos);
int pedirIdVacio(Employees *list, int len, int * id);
int  utn_getFloat(   float *pFloat, int limite, char *mensaje,
                    char *mensajeError, int reintentos);
//static int isValidFloat(char *pBuffer, int limite);
int utn_getEntero(  int *pEntero, int limite, char *mensaje,
                    char *mensajeError, int reintentos);

int con_modificarPorId(Employees* list,int len,int id);
int menuEmployees(int*opcion);
static int isValidNombre(char* pBuffer,int limite);
static int getString(char* pBuffer, int limite);
int initEmployees(Employees* list, int len);
int findEmployeeById(Employees* list, int len,int id);
int ModificarEmployeesPorId(Employees* list, int len,int id );
int removeEmployee(Employees* list, int len , int id);

int sortEmployees(Employees* list, int len, int order);
int printEmployees(Employees* list, int length);
int employeesMenu (Employees*list, int len);
int sortEmployees(Employees* list, int len, int order);
void imprimirEmpleados(Employees* list, int len);
void EmployeesPromedio(Employees* list, int len);






















#endif
