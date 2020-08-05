#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Error.h"
#include "parser.h"
#include "utn.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int main(void)
{
	setbuf(stdout, NULL);

	char cargarDatos[50];


	int opcion;
    LinkedList* listaError = ll_newLinkedList();//Crea una lista d;inamica.
    LinkedList* listaFiltrada = ll_newLinkedList();


	do
	{
		if( !utn_getNumero(&opcion, "Por favor, ingrese una opción: " // Obtiene un numero, que le asigna una "opción" para que el pgm prosiga segun el numero indicado.
											 "\n\t 1. Cargar datos desde `log.txt´ (TEXT). "
											 "\n\t 2. Lista Filtrada."
											 "\n\t 3. Cantidad de gravedad"
											"\n\t 4.."
											"\n\t 5. salir."
											 ,"La opción ingresada es invalida.\n",1,5,2) )
		{
				switch(opcion)
				{
					case 1:



								if(!controller_loadFromText("log.txt",listaError) )//Carga los datos desde un archivo en modo texto.
									{
										printf("Carga realizada con exito!.\n\n");
									}
									else
									{
										printf("No se pudo cargar el archivo!.\n\n");
									}




							      break;


					 case 2:



						if(!controller_filtrarGravedad( listaError))
						{
							printf("FILTRADO CON EXITO");

						}else{
								printf("ERROR");
				  			}


						           break;

					 case 3:

						 if(! controller_contadorDeGravedad(listaError))
				          {
							printf("FILTRADO CON EXITO");

				          }else
				              {
				        	  	  printf("ERROR");

							  }


						            break;




/*
					 case 4:





							if (!utn_getNumero(&tipo,"ingrese el tipo que quiere verificar los datos del envio:", "Error, por favor vuelva a intentarlo",1,3, 4))
											{

												 if(tipo > 0)
												 {
												 listaFiltrada= ll_filterAgregado(listaEmpleados,filtroTipo11,tipo);
												 printf("tamaño %d", ll_len(listaFiltrada));
												 if( ! controller_saveAsText("data3.csv",listaFiltrada))//Guarda los datos en un archivo en modo texto.
													{
														printf("Lista guardada en archivo con exito!.\n\n");
													}
													else
													{
														printf("No se pudo guardar la lista en el archivo!.\n\n");
													}
												 }
											}

*/

						 break;









				}
		}

	}while(opcion != 5);
    return EXIT_SUCCESS;
}
