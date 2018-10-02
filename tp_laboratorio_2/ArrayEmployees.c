#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "ArrayEmployees.h"
#define CANTIDAD_EMPLOYEES 1000


/**
* \brief Evalua si se trata de un float
* \param pBuffer Es la cadena que evaluamos
* \param limite Es el numero maximo de cifras
* \return En caso de exito retorna 1, si no 0
*/
static int isValidFloat(char *pBuffer, int limite)
{
    int retorno = 0;
    int i;
    int contadorDePuntos = 0;
    if  ((pBuffer != NULL && limite > 0 ) &&
        (((pBuffer[0] == '-' || pBuffer[0] == '+') && pBuffer[1] != '.') ||
        (pBuffer[0]>='0' && pBuffer[0]<='9')))
    {
        retorno = 1;
        for(i=1;i < limite && pBuffer[i] != '\0';i++)
        {
            if(pBuffer[i]=='.' && contadorDePuntos==0)
            {
                contadorDePuntos++;
            }
            else if (!(pBuffer[i]>='0' && pBuffer[i]<='9'))
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}
/**
* \brief    Toma la cadena y evalua si es un nombre
* \param pNombre Recibe el texto ingresado en caso de exito
* \param limite Es el tamano maximo del string
* \param msg Es el mensaje que se muestra al usuario antes de introducir datos
* \param msgErr Es el mensaje que se muestra en caso de error
* \param reintentos Veces que el usuario podra volver a introducir el dato
* \return En caso de exito retorna 0, si no -1
*/
int utn_getNombre(  char* pNombre, int limite, char* msg,
                    char* msgErr, int reintentos)
{
    int retorno=-1;
    char bufferNombre[CANTIDAD_EMPLOYEES];

    if( pNombre != NULL && limite > 0 && msg != NULL &&
        msgErr != NULL && reintentos >= 0)
    {
        do
        {
            reintentos--;
            printf("%s",msg);
            if( getString(bufferNombre,limite) == 0 &&
                isValidNombre(bufferNombre,limite))
                {
                    strncpy(pNombre,bufferNombre,limite);
                    retorno = 0;
                    break;
                }
            else
                {
                    printf("%s",msgErr);
                }
        }while(reintentos >= 0);
    }
    return retorno;
}
/**
* \brief    Evalua si es un nombre valido
* \param pBuffer Es la cadena que evaluamos
* \param limite Es el tamano maximo del string
* \return En caso de exito retorna 1, si no 0
*/

static int isValidNombre(char* pBuffer,int limite)
{
    int retorno = 0;
    int i;
    if(pBuffer != NULL && limite > 0)
    {
        retorno = 1;
        for(i=0;i < limite && pBuffer[i] != '\0';i++)
        {
            if(tolower(pBuffer[i]) < 'a' || tolower(pBuffer[i]) > 'z')
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}
/**
* \brief El usuario ingresa una cadena con fgets
* \param pBuffer Recibe el texto ingresado en caso de exito
* \param limite Es el tamano maximo del string
* \return En caso de exito retorna 0, si no -1
*/

static int getString(char* pBuffer, int limite)
{

    int retorno = -1;
    char bufferStr[ CANTIDAD_EMPLOYEES];
    int len;
    if(pBuffer != NULL && limite > 0)
    {
        //__fpurge(stdin);
          //  fflush(stdin);
        fgets(bufferStr,limite,stdin);

        len = strlen(bufferStr);
        if(len != limite-1 ||  bufferStr[limite-2] == '\n')
        {
            bufferStr[len-1] = '\0';
        }
        retorno = 0;
        strncpy(pBuffer,bufferStr,limite);
    }
    return retorno;
}

 /**
* \brief    Toma la cadena y evalua si es un float en caso de exito lo transforma a float
* \param pFloat Recibe el numero ingresado en caso de exito
* \param limite Es el tamano maximo de cifras
* \param mensaje Es el mensaje que se muestra al usuario antes de introducir datos
* \param mensajeError Es el mensaje que se muestra en caso de error
* \param reintentos Veces que el usuario podra volver a introducir el dato
* \return En caso de exito retorna 0, si no -1
*/

int  utn_getFloat(   float *pFloat, int limite, char *mensaje,
                    char *mensajeError, int reintentos)
{
    int retorno=-1;
    char bufferFloat[4096];
    if( pFloat != NULL && limite > 0 && mensaje != NULL &&
        mensajeError != NULL && reintentos>=0)
    {
        do
        {
            reintentos--;
            printf("\n%s", mensaje);
            if( getString(bufferFloat, limite) == 0 &&
                isValidFloat(bufferFloat, limite))
            {
                *pFloat = atof(bufferFloat);
                retorno = 0;
                break;
            }
            else
            {
                printf("\n%s", mensajeError);
            }
        }while(reintentos>=0);
    }
    return retorno;
}

/**
* \brief    Evalua si es un nombre valido
* \param pBuffer Es la cadena que evaluamos
* \param limite Es el tamano maximo del string
* \return En caso de exito retorna 1, si no 0
*/
static int isValidEntero(char *pBuffer, int limite)
{
    int retorno = 0;
    int i;
    if  ((pBuffer != NULL && limite > 0 ) &&
        (pBuffer[0] == '-' || pBuffer[0] == '+' ||
        (pBuffer[0]>='0' && pBuffer[0]<='9')))
    {
        retorno = 1;
        for(i=1;i < limite && pBuffer[i] != '\0';i++)
        {
            if (!(pBuffer[i]>='0' && pBuffer[i]<='9'))
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/**
* \brief    Toma la cadena y evalua si es un entero en caso de exito lo transforma a entero
* \param pEntero Recibe el numero ingresado en caso de exito
* \param limite Es el tamano maximo de cifras
* \param mensaje Es el mensaje que se muestra al usuario antes de introducir datos
* \param mensajeError Es el mensaje que se muestra en caso de error
* \param reintentos Veces que el usuario podra volver a introducir el dato
* \return En caso de exito retorna 0, si no -1
*/
int utn_getEntero(  int *pEntero, int limite, char *mensaje,
                    char *mensajeError, int reintentos)

{


    int retorno=-1;
    char bufferEntero[4096];
    if( pEntero != NULL && limite > 0 && mensaje != NULL &&
        mensajeError != NULL && reintentos>=0)
    {
        do
        {
            reintentos--;
            printf("\n%s", mensaje);
            if( getString(bufferEntero, limite) == 0 &&
                isValidEntero(bufferEntero, limite))
            {
                *pEntero = atoi(bufferEntero);
                retorno = 0;
                break;
            }
            else
            {
                printf("\n%s", mensajeError);
            }
        }while(reintentos>=0);
    }
    return retorno;
}

/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok*/

int addEmployees(Employees* list, int len)
{
int i;
int retorno =-1;
char auxNombre [50];
char auxApellido [50];
float auxSalario;
int auxSector ;

        if(list != NULL && len > 0)
            {
                 for(i=0;i<len;i++)
                 {
                     fflush(stdin);
                        if( list[i].isEmpty ==0
                        &&
                         utn_getNombre(auxNombre,50,"\n Ingrese nombre \n","\n Error, nombre Invalido\n", 2)==0
                         &&
                         utn_getNombre(auxApellido,50,"\n Ingrese apellido \n","\n Error, apellido Invalido\n", 2)==0
                         &&
                         utn_getFloat(&auxSalario,len,"\n Ingrese salario \n","\n Error, salario Invalido\n", 2)==0
                         &&
                         utn_getEntero(&auxSector,len,"\n Ingrese sector \n","\n Error, sector Invalido\n", 2)== 0)
                        {
                            list[i].id = i;
                            strncpy(list[i].name, auxNombre, 50);
                            strncpy(list[i].lastName, auxApellido, 50);
                            list[i].salary =  auxSalario;
                            list[i].sector = auxSector;
                            list[i].isEmpty =  1;
                            retorno = 0;


                            retorno = 0;
                            break;
                         }
                    }

            }




return retorno;
}

/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */

int findEmployeeById(Employees* list, int len,int id)
{
    int i;
    int retorno=-1;

    for(i=0;i<len;i++)
        {
        if(list[id].isEmpty==1 )
            {
            retorno=0;
            }
        }
    return retorno;
}

/**
* \brief    Funcion que muestra el menu principal .
* \param list Recibe el array ingresado.
* \param len es el tamaño del string.
*/
int menuEmployees(int*opcion)
{
    int auxOpcion;

        printf("1- ALTAS \n");
        printf("2-MODIFICAR \n");
        printf("3-BAJA \n");
        printf("4- INFORMAR \n");
        printf("5- Salir \n");
        fflush(stdin);

        while(scanf("%d",&auxOpcion)==0||auxOpcion<1||auxOpcion>5)
            {
                fflush(stdin);
                //__fpurge(stdin);
                printf("Error ingrese una opcion valida\n");
            }
                *opcion=auxOpcion;
    return 0;
}

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employees* list, int len)

{
    int retorno = -1;
    int i;

    if(list != NULL && len > 0)
        {
          for(i=0;i<len;i++)
            {
                list[i].isEmpty=0;
                retorno =0;
            }
        }

   return retorno;
}

/**
* \brief   Recibe un id, lo valida y permite la modificacion de el dato seleccionado.
* \param list Recibe el array ingresado.
* \param Id es el id a evaluar validar y modificar
* \param len Es el tamano maximo del string
*/

int ModificarEmployeesPorId(Employees *list, int len,int id )

{
    int retorno = -1;
    int opcion;
    char auxNombre[50];
    char auxApellido[50];
    float auxSalario;
    int auxSector;
    if(list != NULL && len > 0 && len>0 && id >= 0 && id < len )
    {
        if (list[id].isEmpty == 1)
        {
            printf("\n Desea modificar : \n 1-Nombre: \n 2-Apellido: \n 3-Salario: \n 4 Sector: \n 5-Salir \n");
            scanf("%d",&opcion);
            switch(opcion)
            {
                case 1:
                    fflush(stdin);
                if (utn_getNombre(auxNombre, 50, "\n Ingrese nombre :\n", "Nombre Invalido! \n", 2)==0)
                {
                    strncpy(list[id].name, auxNombre, 50);
                    printf("\n Se ha modificado el nombre con exito!!\n");
                    break;
                }
                case 2:
                                        fflush(stdin);

                if (utn_getNombre( auxApellido,50, "\n Ingrese apellido: \n","\Apellido invalido!\n", 2) == 0)
                {
                    strncpy(list[id].lastName, auxApellido, 51);
                    printf("Apellido modicado\n");
                    break;
                }
                case 3:
                                        fflush(stdin);

                if (utn_getFloat(&auxSalario,20, "\n Ingrese Salario:\n", " \nError de datos\n",2 )== 0)
                {
                    list[id].salary =  auxSalario;
                    printf("\n Se ha modificado el salario con exito!!\n");
                    break;
                }
                case 4:
                                        fflush(stdin);

                if (utn_getEntero( &auxSector , 20, "\nIngrese numero de Sector\n", "\n sector invalido!\n", 2) == 0)
                {
                   list[id].sector =  auxSector;
                    printf("\nSe ha modificado el sector con exito!\n");
                    break;
                }
                default :
                printf("Opcion no valida\n");
            }
            retorno = 0;
        }else
        {
            printf("\nEl id ingresado es inexistente!!\n");
        }
    }
return retorno;
}




 /** \brief Remove a Employees by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len es el tamaño del array.
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */
int removeEmployee(Employees* list, int len , int id)
{
    int retorno = -1;


    fflush(stdin);

     if(list != NULL && len > 0  && id >= 0 && list[id].isEmpty == 1)
        {
            list[id].isEmpty=0;
            retorno = 0;
        }
        else
            {
               printf("\n Error, el id ingresado no existe... \n");
            }


return retorno;


 }
/**
* \brief    Funcion que muestra el menu principal .
* \param list Recibe el array ingresado.
* \param len es el tamaño del string.
*/
int employeesMenu (Employees*list, int len)
 {

int opcionMenuUno;
int opcionMenuDos;
int auxiliarID;
int flag =0;
int i;
int retorno = -1;

     do
    {
        menuEmployees(&opcionMenuUno);

        switch(opcionMenuUno)
        {
                case 1:

                 if   (addEmployees(list,len)==0)
                     {
                         printf("\n Empleado guardado \n");
                         flag =1 ;

                          break;
                     }

                case  2:
                     for (i=0;i<len; i++)
                        {
                           if( list[i].isEmpty == 1 )
                               {
                                   flag =1;
                                   break;
                               }
                        }
                        if(flag == 0)
                           {
                                printf("\n Error, no hay empleados cargados!!\n");
                                break;
                           }
                        fflush(stdin);
                            if ( flag == 1 && utn_getEntero(&auxiliarID, len, "Ingrese id\n","No es un id valido \n", 3) == 0 &&
                                ModificarEmployeesPorId( list, len, auxiliarID) == 0)
                                    {
                                        printf("Empleado Modificado\n");
                                        flag = 0;
                                        break;
                                    }
                                    break;
                case 3:
                       for (i = 0; i< len ; i++)
                                {
                                    if (list[i].isEmpty == 1)
                                        {
                                        flag = 1;
                                        break;
                                        }
                                }
                        if (flag == 0)
                                {
                                printf("\n Error, no hay empleados cargados!!\n");
                                }

                                fflush(stdin);
                        if( flag == 1 && utn_getEntero(&auxiliarID,len,"\n Ingrese ID:\n","\n Error ingrese solo numeros \n",2)==0
                            && removeEmployee(list, len,auxiliarID)==0)
                                {
                                    printf("\n Empleado Borrado con exito!! \n");
                                    flag = 0;
                                      break;
                                }


                                break;

                    case 4 :
                           	for (i = 0; i< len ; i++)
                                {
                                if (list[i].isEmpty == 1)
                                    {
                                    flag = 1;
                                    break;
                                    }
                                }
                                if (flag == 0)
                                    {
                                    printf("No hay informacion cargada\n");
                                    }



                            if (flag == 1)
                               {
                                   printf("\n Elija Opcion : \n");
                                    printf("1- Lista de empleados\n");
                                    printf("2- Total y promedio de salarios y cuantos empleados superan el salario promerio\n");

                                    scanf("%d",&opcionMenuDos);
                                    switch(opcionMenuDos)
                                        {
                                            case 1:
                                            sortEmployees(list, len, 1);
                                            imprimirEmpleados(list, len);
                                            break;
                                            case 2:
                                            EmployeesPromedio(list, len);
                                            break;
                                            default:
                                            printf("\n Opcion no valida!! \n");
                                            break;
                                        }
                                }
                                            //flag = 0;
                                            break;
                                case 5:
                                        printf("\n Cerrando\n");
                                        retorno = 0;
                                        break;

                }


            }while(opcionMenuUno != 5);



return retorno;
}

/**
* \brief   Funcion que recibe un string  y lo ordena por apellido,
*           si tienen el mismo apellido, por sector.-
* \param list recibe el array ingresado.
* \param len es el tamaño del string.
* \param  order es el orden de acomodamiendo :1 menor a mayor y 0 de  mayor a menor
*/
int sortEmployees(Employees* list, int len, int order)
{
  int i, j;
  int auxiliarId;
  char auxNombre[50];
  char auxApellido[50];
  int auxSector;
  float auxSalario;
  if (list!= NULL && len > 0 && (order == 0 || order == 1))
    {
        for(i = 0; i < len; i++)
        {
          j = i + 1;
                fflush(stdin);
                if(list[i].isEmpty == 1&& list[j].isEmpty == 1 && order == 1 && strcmp(list[i].lastName,list[j].lastName) >0
                   || (strcmp(list[i].lastName,list[j].lastName) ==0 && list[i].sector > list[j].sector))
                {
                    auxiliarId = list[j].id;
                    list[j].id = list[i].id;
                    list[i].id = auxiliarId;

                    strncpy(auxApellido, list[j].lastName, 50);
                    strncpy(list[j].lastName,list[i].lastName, 50);
                    strncpy(list[i].lastName,auxApellido, 50);

                    strncpy(auxNombre, list[j].name, 50);
                    strncpy(list[j].name,list[i].name, 50);
                    strncpy(list[i].name,auxNombre, 50);

                    auxSalario = list[j].salary;
                    list[j].salary = list[i].salary;
                    list[i].salary = auxSalario;

                    auxSector = list[j].sector;
                    list[j].sector = list[i].sector;
                    list[i].sector = auxSector;
                }else if(list[i].isEmpty == 1&& list[j].isEmpty == 1 && order == 0 && strcmp(list[i].lastName,list[j].lastName) <0
                         || strcmp(list[i].lastName,list[j].lastName) ==0 && list[i].sector < list[j].sector)
                {
                    auxiliarId = list[j].id;
                   list[j].id = list[i].id;
                    list[i].id = auxiliarId;

                    strncpy(auxApellido, list[j].lastName, 50);
                    strncpy(list[i+1].lastName,list[i].lastName, 50);
                    strncpy(list[i].lastName,auxApellido, 50);

                    strncpy(auxNombre, list[j].name, 50);
                    strncpy(list[i+1].name,list[i].name, 50);
                    strncpy(list[i].name,auxNombre, 50);

                    auxSalario = list[j].salary;
                    list[j].salary = list[i].salary;
                    list[i].salary = auxSalario;

                    auxSector = list[j].sector;
                   list[j].sector = list[i].sector;
                    list[i].sector = auxSector;
                }
        }
    }
    return 1;
}




/**
* \brief   toma el string e imprime lo que hay guardado en cada posicion.
* \param list recibe el array ingresado.
* \param len es el tamaño del string.

*/
void imprimirEmpleados(Employees* list, int len)
{
      if (list != NULL && len > 0)
      {
      	for (int i =0; i< len; i++ )
		{
			if(list[i].isEmpty == 1)
            {
                printf("\nId: %d\n", list[i].id);
                printf("Nombre: %s\n", list[i].name);
                printf("Apellido: %s\n", list[i].lastName);
                printf("Salario: %f\n", list[i].salary);
                printf("Sector: %d\n", list[i].sector);
                printf("**********************\n");                }
        }
      }
}



/**
* \brief    Funcion que calcula el total de los salarios percibidos, y el promedio de los sueldos.
* \param llist Recibe el array ingresado
* \param len es el tamaño del string.
*/

void EmployeesPromedio(Employees* list, int len)
{
   	int i, j;
	float acumuladorSalarios = 0;
	int superanPromedio = 0;
    int contadorSalarios = 0;
	if(list != NULL && len > 0 && len>0 )
	{
		for (i =0; i< len; i++ )
		{
			if(list[i].isEmpty == 1)
			{
				acumuladorSalarios = acumuladorSalarios + list[i].salary;
				contadorSalarios++;
			}
		}
		if (acumuladorSalarios > 0)
		{
			printf("\n El total de los salarios es : %f\n", acumuladorSalarios);
			printf("\n El promedio de los sueldos  es: %f\n", acumuladorSalarios/contadorSalarios);
		}
		for (j =0; j< len; j++)
		{
			if (list[j].isEmpty == 1 && list[j].salary > (acumuladorSalarios/contadorSalarios))
			{
				printf("\nId: %d\n", list[j].id);
				printf("\nNombre: %s\n", list[j].name);
				printf("\nApellido: %s\n ", list[j].lastName);
				printf("\nSalario: %f\n", list[j].salary);
				printf("\nSector: %d\n", list[j].sector);
				printf("                             \n");
				superanPromedio++;
				fflush(stdin);
			}
		}
		printf("\nLa cantidad de empleados que superan el sueldo promedio son : %d\n", superanPromedio);
	}
}














