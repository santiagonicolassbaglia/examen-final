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









int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	FILE* auxFile = NULL;
	eEnvios* auxEnvio = NULL;


	    int id;
	    char nombre[NOMBRE_LEN];
	    int idCamion;
	    char zona[ZONA_LEN];
	    int kmRecorridos;
	    int tipoEntrega;
	    float costo;

	int i;

	if( path != NULL && pArrayListEmployee != NULL )
	{
		auxFile = fopen(path,"w");
		if( auxFile != NULL )
		{
			printf( " ID\t--NOMBRE\t--ID CAMION\t--ZONA\t--KM RECORRIDOS--TIPO DE ENTREGA\t--COSTO ENVIO\t \n");

			for(i=0;i<ll_len(pArrayListEmployee);i++)//Recorre el la lista dinamica de empleados.
			{
				auxEnvio = (eEnvios*)ll_get(pArrayListEmployee,i);//Obtiene la informacion del empleado en la posicion i.

				if( auxEnvio  != NULL &&

						!Envios_getId(auxEnvio, &id)&&
						!Envios_getNombre(auxEnvio, nombre)&&
						!Envios_getIdCamion(auxEnvio,&idCamion)&&
						!Envios_getZona(auxEnvio,zona)&&
						!Envios_getKmRecorridos(auxEnvio,&kmRecorridos)&&
						!Envios_getTipoEntrega(auxEnvio,&tipoEntrega)&&
						!Envios_getCostoEnvio(auxEnvio,&costo))


				{

					printf("------------------------------------------------------------------------\n");
					fprintf(auxFile,"%d -> %s -> %d -> %s -> %d-> %d->%.2f \n", id, nombre, idCamion, zona ,kmRecorridos,tipoEntrega, costo);
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
        int idCamion;
        char zona[ZONA_LEN];
        int kmRecorridos;
        int tipoEntrega;


    if(pArrayListEnvios != NULL)
    {
        auxReturn = 0;
        printf("\n\nId  \t\t   NOMBRE \t\t ID CAMION \t\tZONA  \t\t KM RECORRIDOS \t\t TIPO ENTREGA\n\n");

        for(i=0; i<ll_len(pArrayListEnvios); i++)
        {
        	pEnvios = ll_get(pArrayListEnvios, i);
            if (    !Envios_getId(pEnvios,&id) &&
            		!Envios_getNombre(pEnvios,nombre) &&
            		!Envios_getIdCamion(pEnvios,&idCamion) &&
            		!Envios_getZona(pEnvios,zona)&&
            		!Envios_getKmRecorridos(pEnvios,&kmRecorridos)&&
					!Envios_getTipoEntrega(pEnvios,&tipoEntrega))

		    {
            	printf("ID: %d - NOMBRE: %s - ID CAMION: %d  -ZONA: %s  - KM RECORRIDOS:%d  -  TIPO ENTREGA: %d\n",id,nombre,idCamion,zona,kmRecorridos,tipoEntrega);
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
        int idCamion;
        char zona[ZONA_LEN];
        int kmRecorridos;
        int tipoEntrega;
        float costoEnvio;


    if(pArrayListEnvios != NULL)
    {
        auxReturn = 0;
        printf("\n\nId  \t\t   NOMBRE \t\t ID CAMION \t\tZONA  \t\t KM RECORRIDOS \t\t TIPO ENTREGA   \t\t COSTO ENVIO \n\n");

        for(i=0; i<ll_len(pArrayListEnvios); i++)
        {
        	pEnvios = ll_get(pArrayListEnvios, i);
            if (    !Envios_getId(pEnvios,&id) &&
            		!Envios_getNombre(pEnvios,nombre) &&
            		!Envios_getIdCamion(pEnvios,&idCamion) &&
            		!Envios_getZona(pEnvios,zona)&&
            		!Envios_getKmRecorridos(pEnvios,&kmRecorridos)&&
					!Envios_getTipoEntrega(pEnvios,&tipoEntrega)&&
					!Envios_getCostoEnvio(pEnvios,&costoEnvio))

		    {
            	printf("ID: %d - NOMBRE: %s - ID CAMION: %d  -ZONA: %s  - KM RECORRIDOS:%d  -  TIPO ENTREGA: %d  - COSTO ENVIO:%.2f\n",id,nombre,idCamion,zona,kmRecorridos,tipoEntrega,costoEnvio);
            }

          }

    }

    return auxReturn;
}












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


//---------------------------------------------------------------
// punto 5




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



















//--------------------------------------------------------- punto 5 fallido!






/*
int controller_ordenarlistaZona(LinkedList* pEnvio)
{

    int auxReturn = -1;

    if(pEnvio != NULL)
    {
    	 auxReturn = 0;

    	 printf("\nOrdenando los datos...\n\n");
    	 ll_sort(pEnvio, Envio_ordenarPorZona, 1);


    }

    return auxReturn;

}


*/

/*
int controller_sortEnvio(LinkedList* pArrayListEmployee)
{
    int auxReturn = -1;

    if(pArrayListEmployee != NULL)
    {
        controller_ordenarlistaZona(pArrayListEmployee);
        auxReturn = 0;
    }

    return auxReturn;
}

*/













/*

void controller_ImprimirZonas(void* pElement)
{
	eEnvios* pEnvios= (eEnvios*)pElement;
	LinkedList* cloneArray = NULL;

	char zona[40];
	int flag=0;

strncpy(zona, pEnvios->zona,50);


	 while(ll_contains(pElement,zona)==0)
	 {
		 flag=1;
		 ll_add(pEnvios,zona);
		 printf("%s", pEnvios);

	 }


}

*/

/*
int info_huevadas(LinkedList *lista)
 {
	eEnvios * pEnviosAux;

 	int retorno = -1;
 	char zona[1000];
 	int flag;
 	char zona2[20];
 	int i;
 	int j;
 	int indice = 0;



 	if(lista != NULL)
 	{


 		for(i=0; i<ll_len(lista); i++)
 		{
 			flag = 0;

		strcpy(zona[indice], zona2);

 			for(j=0; j<indice; j++)
 			{
 				if(strncmp(zona2,zona[j],50)==0)
 				{


	pEnviosAux = ll_get(lista, i);
 			Envios_getZona(pEnviosAux,zona2);
 			printf("%s", zona2);
 			indice++;
 				}
 			}

 		}

 		if(flag == 0)
 		{
 			flag = 1;

 		}

 	}


 	return retorno;
 }

*/


//--------------------------------------------------------- punto 5 fallido!


/*


int controller_ordenarlistaZona(LinkedList* pEnvio)
{

    int auxReturn = -1;

    if(pEnvio != NULL)
    {
    	 auxReturn = 0;

    	 printf("\nCargando las Zonas...\n\n");
    	 ll_sort(pEnvio, Envio_ordenarPorZona, 1);


    }

    return auxReturn;

}





int controller_sortEnvio(LinkedList* pArrayListEmployee)
{
    int auxReturn = -1;

    if(pArrayListEmployee != NULL)
    {
        controller_ordenarlistaZona(pArrayListEmployee);
        auxReturn = 0;
    }

    return auxReturn;
}













int controller_ListarPunto5(LinkedList* pArrayListEnvios)
{
    eEnvios *pEnvios;

    int auxReturn = -1;
    int i;

        char zona[ZONA_LEN];



    if(pArrayListEnvios != NULL)
    {
        auxReturn = 0;
        printf("\n\nId  \t\t   NOMBRE \t\t ID CAMION \t\tZONA  \t\t KM RECORRIDOS \t\t TIPO ENTREGA   \t\t COSTO ENVIO \n\n");

        for(i=0; i<ll_len(pArrayListEnvios); i++)
        {
        	pEnvios = ll_get(pArrayListEnvios, i);
            if ( !Envios_getZona(pEnvios,zona))

		    {
            	printf("-ZONA: %s \n",zona);
            }

          }

    }

    return auxReturn;
}


*/






/*




int controller_hacerEl5(void* pElement)
{
	eEnvios* pEnvio= (eEnvios*)pElement;


	int retorno= -1;
	char zona[50];



	  Envios_getZona(pEnvio, zona);


//	strncpy (zona,pEnvio->zona,300);

	retorno =0;

	    if(!strncmp(zona, 'lanus',300))
	    {
	       printf(" lanus");
	    }
	    else if(!strncmp(zona, 'caba',300))
	    {
	    	printf(" caba");
	    }
	    else if(!strncmp(zona,'avellaneda',300))
	    {
	        printf ("avellaneda");
	    }





 	return retorno;

}





*/
































