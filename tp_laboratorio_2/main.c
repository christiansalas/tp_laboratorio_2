#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "ArrayEmployees.h"

#define CANTIDAD_EMPLOYEES 1000








int main()
{


Employees arrayEmployees[CANTIDAD_EMPLOYEES];
initEmployees(arrayEmployees,CANTIDAD_EMPLOYEES);
employeesMenu (arrayEmployees,  CANTIDAD_EMPLOYEES);

return 0;





}
