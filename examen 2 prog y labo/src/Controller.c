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
#include "Envios.h"


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
	eEnvios* auxEnvio = NULL;


	    int id;
	    char nombre[NOMBRE_LEN];
	    int kmRecorridos;
	    int tipoEntrega;
	    float costo;

	int i;

	if( nombreArchivo != NULL && pArrayListEmployee != NULL )
	{
		auxFile = fopen(nombreArchivo,"w");
		if( auxFile != NULL )
		{
			printf( " ID\t--NOMBRE\t--\t--TIPO DE ENTREGA\t--COSTO ENVIO\t \n");

			for(i=0;i<ll_len(pArrayListEmployee);i++)//Recorre el la lista dinamica de empleados.
			{
				auxEnvio = ll_get(pArrayListEmployee,i);//Obtiene la informacion del empleado en la posicion i.

				if( auxEnvio  != NULL &&

						!Envios_getId(auxEnvio, &id)&&
						!Envios_getNombre(auxEnvio, nombre)&&
						!Envios_getKmRecorridos(auxEnvio,&kmRecorridos)&&
						!Envios_getTipoEntrega(auxEnvio,&tipoEntrega)&&
						!Envios_getCostoEnvio(auxEnvio,&costo))


				{

					printf("------------------------------------------------------------------------\n");
					fprintf(auxFile,"%d -> %s -> %d-> %d->%.2f \n", id, nombre,kmRecorridos,tipoEntrega, costo);
					printf("------------------------------------------------------------------------\n");

				}
			}
			retorno = 0;
			fclose(auxFile);//Cierra el archivo.
		}
	}
    return retorno;
}








int controller_ListEnvios(LinkedList* pArrayListEnvios)
{
    eEnvios *pEnvios;

    int auxReturn = -1;
    int i;

    int id;
        char nombre[NOMBRE_LEN];
        int kmRecorridos;
        int tipoEntrega;


    if(pArrayListEnvios != NULL)
    {
        auxReturn = 0;
        printf("\n\nId  \t\t   NOMBRE  \t\t KM RECORRIDOS \t\t TIPO ENTREGA\n\n");

        for(i=0; i<ll_len(pArrayListEnvios); i++)
        {
        	pEnvios = ll_get(pArrayListEnvios, i);
            if (    !Envios_getId(pEnvios,&id) &&
            		!Envios_getNombre(pEnvios,nombre) &&
            		!Envios_getKmRecorridos(pEnvios,&kmRecorridos)&&
					!Envios_getTipoEntrega(pEnvios,&tipoEntrega))

		    {
            	printf("ID: %d - NOMBRE: %s  - KM RECORRIDOS:%d  -  TIPO ENTREGA: %d\n",id,nombre,kmRecorridos,tipoEntrega);
            }

          }

    }

    return auxReturn;
}














int controller_ListConCosto(LinkedList* pArrayListEnvios)
{
    eEnvios *pEnvios;

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



