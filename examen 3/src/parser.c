/*
 * parser.c
 *
 *  Created on: 21 jun. 2020
 *      Author: admin
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Parser.h"

#include "Error.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 * \param path Puntero al archivo recibido.
 * \param pArrayListEmployee Puntero a la lista dinamica.
 * \return Retorna 0 si copió aunque sea 1 archivo correctamente; -1 en caso de error.
 *
 */
int parser_EnviosFromText(FILE* pFile , LinkedList* pArrayListEnvios)
{
	int retorno = -1;
	eError* pEnvios = NULL;

	    char dia[500];
	    char mes[500];
	    char anio[500];
	    char hora[500];
	    char nombre[500];
	    char gravedad[500];
	    char mensaje[500];

	if( pFile != NULL && pArrayListEnvios!= NULL )//Valida que los punteros recibidos en la funcion sean coherentes.
	{
		do
		{

			if( fscanf(pFile, "%[^/]/%[^/]/%[^;];%[^;];%[^;];%[^;];%[^\n]\n", dia, mes, anio, hora ,nombre,gravedad,mensaje )== 7)// lee el texto y retorna la cantidad de datos
			{
				printf("%s/ %s/ %s  -%s-  %s - %s -%s\n", dia, mes, anio, hora ,nombre,gravedad,mensaje );
				pEnvios = Error_newParametrosTxt( dia, mes, anio, hora ,nombre,gravedad,mensaje );
				if( pEnvios != NULL && //Verifica que el empleado se haya cargado correctamente y haya encontrado espacio en memoria.
					!ll_add(pArrayListEnvios,pEnvios) )//Agrega el empleado a la lista dinamica.
				{
					retorno = 0;
				}
			}
		}while(!feof(pFile));//Mientras el archivo sea leyendo filas (empleados) es decir 1 seguira iterando, cuando sea 0 saldra del bucle.
	}
    return retorno;
}
