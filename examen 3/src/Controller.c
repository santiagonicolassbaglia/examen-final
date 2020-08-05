/*
 * Controller.c
 *
 *  Created on: 21 jun. 2020
 *      Author: admin
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "parser.h"
#include "utn.h"
#include "Controller.h"

#include "Error.h"


#define RESP_LEN 2

// \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	FILE* auxFile;
	if( path != NULL && pArrayListEmployee != NULL )//Valida que los punteros recibidos en la funcion sean coherentes.
	{
		auxFile = fopen(path,"r");//Abre el archivo en modo lectura.
		if( auxFile != NULL &&//Valida que el archivo que se buscó abrir no sea NULL.
			!parser_EnviosFromText(auxFile,pArrayListEmployee) )//Llama a la funcion que parsea los datos del archivo.
		{
			retorno = 0;
		}
		fclose(auxFile);//Se cierra el archivo.
	}
    return retorno;
}









int controller_saveAsText(char* nombreArchivo , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	FILE* auxFile = NULL;
	eError* auxEnvio = NULL;


	    int dia;
	    int mes;
	    int anio;
	    char hora[HORA_LEN];
	    char nombre[NOMBRE_LEN];
	    char mensaje[MENSAJE_LEN];
	    int gravedad;


	int i;

	if( nombreArchivo != NULL && pArrayListEmployee != NULL )
	{
		auxFile = fopen(nombreArchivo,"w");
		if( auxFile != NULL )
		{
			printf( " Dia / MES / AÑO \t--HORA\t-- NOMBRE DE SERVICIO\t--MENSAJE DE ERROR\t--GRAVEDAD\t \n");

			for(i=0;i<ll_len(pArrayListEmployee);i++)//Recorre el la lista dinamica de empleados.
			{
				auxEnvio = ll_get(pArrayListEmployee,i);//Obtiene la informacion del empleado en la posicion i.

				if( auxEnvio  != NULL &&

						!error_getDia(auxEnvio, &dia)&&
						!error_getMes(auxEnvio, &mes)&&
						!error_getAnio(auxEnvio, &anio)&&
						!Error_getHora(auxEnvio, hora)&&
						!Error_getNombre(auxEnvio, nombre)&&
						!Error_getMensaje(auxEnvio, mensaje)&&
						!Error_getGravedad(auxEnvio, &gravedad))




				{


					fprintf(auxFile,"%d/%d/%d-> %s-> %s-> %s-> %d \n", dia, mes, anio,hora, nombre, mensaje, gravedad);


				}
			}
			retorno = 0;
			fclose(auxFile);//Cierra el archivo.
		}
	}
    return retorno;
}








int controller_ListError(LinkedList* pArrayListEnvios)
{
    eError *auxEnvio;

    int auxReturn = -1;
    int i;

    int dia;
    	    int mes;
    	    int anio;
    	    char hora[HORA_LEN];
    	    char nombre[NOMBRE_LEN];
    	    char mensaje[MENSAJE_LEN];
    	    int gravedad;

    if(pArrayListEnvios != NULL)
    {
        auxReturn = 0;
        printf( " Dia / MES / AÑO \t--HORA\t-- NOMBRE DE SERVICIO\t--MENSAJE DE ERROR\t--GRAVEDAD\t \n");

        for(i=0; i<ll_len(pArrayListEnvios); i++)
        {
        	auxEnvio = ll_get(pArrayListEnvios, i);
            if (   !error_getDia(auxEnvio, &dia)&&
					!error_getMes(auxEnvio, &mes)&&
					!error_getAnio(auxEnvio, &anio)&&
					!Error_getHora(auxEnvio, hora)&&
					!Error_getNombre(auxEnvio, nombre)&&
					!Error_getMensaje(auxEnvio, mensaje)&&
					!Error_getGravedad(auxEnvio, &gravedad))
		    {
            	printf(" %d / %d / %d - HORA:%s  - NOMBRE:%s  -  MENSAJE: %s - GRAVEDAD: %d\n", dia, mes, anio,hora, nombre, mensaje, gravedad);
            }

          }

    }

    return auxReturn;
}








// para el FILTERR !







int controller_laGravedadEsMenorA3(void* pElement)
{
	eError* pError= (eError*)pElement;
	int ret=0;
	int auxGrav;

	auxGrav=pError->gravedad;

	if(auxGrav <3 )
	{
		ret=1;

	}
	else
	{
		ret=0;
	}


	return ret;
}












int controller_laGravedadEs3(void* pElement)
{
	eError* pError= (eError*)pElement;
	int ret=0;
	int auxGrav;

	auxGrav=pError->gravedad;

	if(auxGrav== 3 )
	{
		ret=1;

	}
	else
	{
		ret=0;
	}


	return ret;
}




int controller_laGravedadEsEntre4Y7(void* pElement)
{
	eError* pError= (eError*)pElement;
	int ret=0;
	int auxGrav;

	auxGrav=pError->gravedad;

	if( auxGrav >=4 && auxGrav <=7)
	{
		ret=1;

	}
	else
	{
		ret=0;
	}


	return ret;
}









int controller_laGravedadEsMayorA7(void* pElement)
{
	eError* pError= (eError*)pElement;
	int ret=0;
	int auxGrav;

	auxGrav=pError->gravedad;

	if( auxGrav > 7)
	{
		ret=1;

	}
	else
	{
		ret=0;
	}


	return ret;
}











int controller_filtrarGravedad(LinkedList* this)
{
	LinkedList* listaFiltrada;


	 int retorno=-1;

	 if (this != NULL)
	 {

listaFiltrada  =      ll_filter(this,controller_laGravedadEs3);
if( listaFiltrada!=NULL)
{
     printf("--------------------------------------------------------------------------------------------\t\n\n");
	 printf("-- lista filtrada. La gravedad estando en nivel 3.. se encuentra en el archivo warnings.txt \t\n\n");
	 printf("--------------------------------------------------------------------------------------------\t\n\n");
	 controller_saveAsText("warnings.txt",listaFiltrada);

	 retorno= 0;

}else
	{
	printf("ERROR");
	}



//******
listaFiltrada =   ll_filter(this,controller_laGravedadEsEntre4Y7);

					if( listaFiltrada!=NULL)
					{
						 printf("--------------------------------------------------------------------------------------------\t\n\n");
						 printf("-- lista filtrada. La gravedad es entre 4 y 7  \t\n\n");
						 printf("--------------------------------------------------------------------------------------------\t\n\n");
						 controller_ListError(listaFiltrada);
						 retorno= 0;

					}else
					{
						printf("ERROR");
					}



listaFiltrada=ll_filter(this,controller_laGravedadEsMayorA7);
					if( listaFiltrada!=NULL)
					{
						 printf("--------------------------------------------------------------------------------------------\t\n\n");
						 printf("-- lista filtrada. La gravedad es mayor a 7 se encuentra en el archivo errors.txt\t\n\n");
						 printf("--------------------------------------------------------------------------------------------\t\n\n");

						 controller_saveAsText("errors.txt",listaFiltrada);
						 retorno= 0;

					}else
					{
						printf("ERROR");
					}

	 }

 return retorno;
}













int controller_contadorDeGravedad(LinkedList* this)

{
	 int retorno=-1;


	 int laGravedadEsMenorA3=0;
	 int laGravedadEs3=0;
	 int laGravedadEsEntre4Y7=0;
	 int laGravedadEsMayorA7=0;

	 if(this != NULL)
	 {

	 laGravedadEsMenorA3= ll_count(this,controller_laGravedadEsMenorA3);

	  printf("--------------------------------------------------------------------------------------------\t\n\n");
	  printf("-- La cantidad de gravedad menor a 3: %d\n ", laGravedadEsMenorA3);
	  printf("--------------------------------------------------------------------------------------------\t\n\n");

	  laGravedadEs3 = ll_count(this,controller_laGravedadEs3);

	  printf("--------------------------------------------------------------------------------------------\t\n\n");
	  printf("-- La cantidad de gravedad en nivel 3: %d\n ", laGravedadEs3);
	  printf("--------------------------------------------------------------------------------------------\t\n\n");

	  laGravedadEsEntre4Y7= ll_count(this,controller_laGravedadEsEntre4Y7);

	  printf("--------------------------------------------------------------------------------------------\t\n\n");
	  printf("-- La cantidad de gravedad entre 4 y 7 %d\n ", laGravedadEsEntre4Y7);
	  printf("--------------------------------------------------------------------------------------------\t\n\n");


	  laGravedadEsMayorA7= ll_count(this,controller_laGravedadEsMayorA7);

	  printf("--------------------------------------------------------------------------------------------\t\n\n");
	  printf("-- La cantidad de gravedad siendo mayor a 7 :%d\n ", laGravedadEsMayorA7);
	  printf("--------------------------------------------------------------------------------------------\t\n\n");


	  retorno= 0;
	 }

	 return retorno ;
}


/*




int controller_ListConCosto(LinkedList* pArrayListEnvios)
{
    eError *pEnvios;

    int auxReturn = -1;
    int i;

    int id;
        char nombre[NOMBRE_LEN];
        int kmRecorridos;
        float costoEnvio;

        char auxEntrega[50];

    if(pArrayListEnvios != NULL)
    {
        auxReturn = 0;
        printf("\n\nId  \t\t   NOMBRE  \t\t KM RECORRIDOS \t\t TIPO ENTREGA   \t\t COSTO ENVIO \n\n");

        for(i=0; i<ll_len(pArrayListEnvios); i++)
        {
        	pEnvios = ll_get(pArrayListEnvios, i);
            if (    !Envios_getId(pEnvios,&id) &&
            		!Envios_getNombre(pEnvios,nombre) &&
            		!Envios_getKmRecorridos(pEnvios,&kmRecorridos)&&
					!Envios_getTipoEntregaTxt(pEnvios,auxEntrega)&&
					!Envios_getCostoEnvio(pEnvios,&costoEnvio))

            {


            	            if( pEnvios->tipoEntrega==1)
            	        	{
            	        	 strncpy(auxEntrega,"segun disponibilidad",30);
            	        	  Envios_setTipoEntregaTxt(pEnvios,auxEntrega);
            	        	}
            	            else if( pEnvios->tipoEntrega==2)
            	        	{
            	        		strncpy(auxEntrega,"normal",30);
            	        		Envios_setTipoEntregaTxt(pEnvios,auxEntrega);
            	        	}

            	            else if(pEnvios->tipoEntrega==3)
            				{
            					strncpy(auxEntrega,"express",30);
            					Envios_setTipoEntregaTxt(pEnvios,auxEntrega);
            				}
            	        	else {
            	        		   printf("error");
            	             	}







            	printf("ID: %d - NOMBRE: %s  - KM RECORRIDOS:%d  -  TIPO ENTREGA: %s  - COSTO ENVIO:%.2f\n",id,nombre,kmRecorridos,auxEntrega,costoEnvio);


            }
          }

    }

    return auxReturn;
}








*/






















/*


// punto 4

int controller_enviosPorZona(void* pElement, char* pZona)
{
	eEnvios* pEnvios= (eEnvios*)pElement;
	int ret=0;
	char zonas[40];

 strcpy(pEnvios->zona,pZona);


	 if( !strncmp(zonas,pZona,50))
	{
		ret=1;

	}
	else
	{
		ret=0;
	}


	return ret;
}

*/
//---------------------------------------------------------------
// punto 5



/*
int controller_ImprimirZonas(LinkedList* pArrayListEnvio)
	{
		int retorno = -1;
		int i;
		eEnvios* pEnvio = NULL;

		if (pArrayListEnvio!= NULL)
		{
			for (i = 0;i< ll_len(pArrayListEnvio);i++)
			{
				pEnvio = ll_get(pArrayListEnvio, i);

				if(pEnvio != NULL)
				{
					printf("\n-ZONA : %s \n",pEnvio->zona);
				}
			}
			retorno = 0;
		}

		return retorno;
	}







int envio_ComparaZonas(void*pElement,LinkedList* this)
{
	int retorno= -1;
	int i;
	eEnvios* pEnvio = (eEnvios*) pElement;
	eEnvios* auxiliar;
	if(pEnvio != NULL && this != NULL )
	{
		retorno = 0;
		for(i=0;i<ll_len(this);i++)
		{
			auxiliar =  ll_get(this,i);
			if(!strcmp(pEnvio->zona,auxiliar->zona))
			{
				retorno = 1;
			}
		}

	}
	return retorno;
}





*/



