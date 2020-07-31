/*
 * Controller.h
 *
 *  Created on: 21 jun. 2020
 *      Author: admin
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);


int controller_ListEnvios(LinkedList* pArrayListEmployee);

int controller_IdMaximo(LinkedList* pArrayListEmployee, int* id);
int controller_Alta(LinkedList* pArrayListEmployee);


int controller_Modificar(LinkedList* pArrayListEmployee);

int controller_Ordenar(LinkedList* pArrayListEmployee);

int controller_Baja(LinkedList* pArrayListEmployee);

int controller_buscarPorId(LinkedList* pArrayListEmployee, int id, int* AlojarID);


int controller_ListConCosto(LinkedList* pArrayListEnvios);

// punto 4

//int controller_enviosPorZona(void* pElement, char* pZona);

//------------------------------------------------

int controller_loadFromTextCosto(char* path , LinkedList* pArrayListEmployee);



int controller_ordenarlistaZona(LinkedList* pEnvio);
int controller_sortEnvio(LinkedList* pArrayListEmployee);


//void controller_ImprimirZonas(void* pElement);



int controller_ListarPunto5(LinkedList* pArrayListEnvios);


int controller_hacerEl5(void* pElement);



//punto 5
/*
int controller_ImprimirZonas(LinkedList* pArrayListEnvio);

int envio_ComparaZonas(void*pElement,LinkedList* this);


*/
#endif /* CONTROLLER_H_ */
