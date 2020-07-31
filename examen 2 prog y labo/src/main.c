#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Envios.h"
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
	int tipo;


	int opcion;
    LinkedList* listaEmpleados = ll_newLinkedList();//Crea una lista d;inamica.
    LinkedList* listaFiltrada = ll_newLinkedList();
    LinkedList* listaZonas = ll_newLinkedList();

	do
	{
		if( !utn_getNumero(&opcion, "Por favor, ingrese una opción: " // Obtiene un numero, que le asigna una "opción" para que el pgm prosiga segun el numero indicado.
											 "\n\t 1. Cargar datos desde `examen2.csv´ (TEXT). "
											 "\n\t 2. Listar."
											 "\n\t 3. Calcular Costos"
											"\n\t 4. filtrar segun el tipo ."
											"\n\t 5. salir."
											 ,"La opción ingresada es invalida.\n",1,6,2) )
		{
				switch(opcion)
				{
					case 1:

                          utn_getDescripcion(cargarDatos,50,"ingrese el nombre del archivo que de desee abrir:", "Error , archivo no encontrado, por favor vuelva a intentarlo", 4);

                            if( !strncmp(cargarDatos,"examen2.csv",50) && cargarDatos!= NULL)

                          {

								if(!controller_loadFromText("examen2.csv",listaEmpleados) )//Carga los datos desde un archivo en modo texto.
									{
										printf("Carga realizada con exito!.\n\n");
									}
									else
									{
										printf("No se pudo cargar el archivo!.\n\n");
									}

                          }


							   break;


					 case 2:
						 if (!controller_ListConCosto(listaEmpleados ))
							 {
								printf("lista Cargada!.\n\n");
							 }
							 else
								{
									printf("No se pudo listar!.\n\n");
								}

					            break;

					 case 3:



						if(! ll_map(listaEmpleados,Envios_agregarCosto)&&
					       !controller_saveAsText("data2.csv",listaEmpleados))
						{

						 printf("lista guardada en el archivo con el costo realizado \n");

						}else{
							 printf("no se pudo calcular el costo");
						}



						break;

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



						 break;









				}
		}

	}while(opcion != 5);
    return EXIT_SUCCESS;
}
