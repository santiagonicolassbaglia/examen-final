/*
 * Employee.c
 *
 *  Created on: 21 jun. 2020
 *      Author: admin
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Envios.h"
#include "LinkedList.h"

static int esNumero(char* cadena, int len);
static int esNombre(char* cadena, int len);
static int esFlotante(char* cadena);
static int esCuit(char* cadena,int len);
static int esDescripcion(char* cadena, int len);
/**
 * \brief Solicita un espacio en memoria para un empleado.*
 */
eEnvios* Envios_new()
{
	  eEnvios* auxiliarP = NULL;
		auxiliarP = (eEnvios*) malloc(sizeof(eEnvios));
		return auxiliarP;

}

/**
 * \brief Borra de memoria el espacio ocupado por un empleado.

 */
void Envios_delete(eEnvios* this)
{
	if( this != NULL )//Valida que el puntero al empleado no sea NULL.
	{
		free(this);//Libera espacio en memoria que ocupa el empleado reibido en la funcion.
	}
}



//Crea un nuevo empleado, recibiendo TODOS los elementos de tipo cadena de caracteres.

eEnvios* Envios_newParametrosTxt(char* idStr,char* nombreStr,char* idCamionStr, char* zonaStr, char* kmStr, char* tipoEntregaStr)
{
	eEnvios* nuevoEnvios ;
	int flag = 0;

	nuevoEnvios = Envios_new();//Asigna espacio en memoria para el empleado.


	if( nuevoEnvios != NULL &&
		    idStr != NULL && nombreStr != NULL && idCamionStr != NULL && zonaStr != NULL && kmStr != NULL && tipoEntregaStr != NULL &&
		!Envios_setIdTxt(nuevoEnvios,idStr) &&
		!Envios_setNombre(nuevoEnvios, nombreStr) &&
		!Envios_setIdCamionTxt(nuevoEnvios,idCamionStr) &&
		!Envios_setZona(nuevoEnvios,zonaStr) &&
		!Envios_setKmRecorridosTxt(nuevoEnvios,kmStr)&&
		!Envios_setTipoEntregaTxt(nuevoEnvios,tipoEntregaStr))



	{
		flag = 1;//Si pasa las validaciones del IF, crea un nuevo empleado y cambia el estado de flag a 1 para que NO entre en el siguiente IF.
	}
	if( flag == 0 )//En caso de que no se hayan pasado las validaciones del IF anterior, va a entrar en este IF.
	{
		Envios_delete(nuevoEnvios);//Si entra en este IF, se va a liberar el espacio en memoria brindado a auxEmployee ya que no se cargaron los datos correctamente.
		nuevoEnvios = NULL;//Se apunta el auxEmployee a NULL.
	}
	return nuevoEnvios;
}









eEnvios* Envios_newParametros(int idStr,char* nombreStr,int idCamionStr, char* zonaStr, int kmStr, int tipoEntregaStr)
{
	eEnvios* nuevoEnvios ;
	int flag = 0;

	nuevoEnvios =Envios_new();//Asigna espacio en memoria para el empleado.


	if( nuevoEnvios != NULL &&//Valida que esa direccion no sea NULL.
		idStr > 0 && nombreStr != NULL && zonaStr != NULL && idCamionStr > 0 && kmStr > 0 && tipoEntregaStr > 0 &&

		    !Envios_setId(nuevoEnvios,idStr) &&
			!Envios_setNombre(nuevoEnvios, nombreStr) &&
			!Envios_setIdCamion(nuevoEnvios,idCamionStr) &&
			!Envios_setZona(nuevoEnvios,zonaStr) &&
			!Envios_setKmRecorridos(nuevoEnvios,kmStr)&&
			!Envios_setTipoEntrega(nuevoEnvios,tipoEntregaStr))
	{
		flag = 1;//Si pasa las validaciones del IF, crea un nuevo empleado y cambia el estado de flag a 1 para que NO entre en el siguiente IF.
	}
	if( flag == 0 )//En caso de que no se hayan pasado las validaciones del IF anterior, va a entrar en este IF.
	{
		Envios_delete(nuevoEnvios);//Si entra en este IF, se va a liberar el espacio en memoria brindado a auxEmployee ya que no se cargaron los datos correctamente.
		nuevoEnvios = NULL;//Se apunta el auxEmployee a NULL.
	}
	return nuevoEnvios;
}






//toma el dato
int Envios_setIdTxt(eEnvios* this, char* id)
{
	int retorno = -1;

	if( this != NULL && id != NULL &&//Valida que ambos punteros sean coherentes.
		esNumero(id,INT_LEN) )//Valida que la cadena sea numerica entera.
	{
		retorno = 0;
		this->id = atoi(id);//Si pasa las validaciones del IF, convierte a entero la cadena recibida y se la asigna al empleado (this).
	}
	return retorno;
}

int Envios_setId(eEnvios* this,int id)
{
	int retorno = -1;

	if( this != NULL && id > 0 )
	{
		this->id = id;
		retorno = 0;
	}
	return retorno;
}


int Envios_getId(eEnvios* this,int* id)
{
	int retorno = -1;

	if( this != NULL && id != NULL )//Valida que ambos punteros sean coherentes.
	{
		*id = this->id;//Asigna al puntero id, el identificador cargado en el empleado.
		retorno = 0;
	}
	return retorno;
}



//------------------

int Envios_setNombre(eEnvios* this, char* nombre)
{
	int retorno = -1;

	if( this != NULL && nombre != NULL &&//Valida que ambos punteros sean coherentes.
		esNombre(nombre,NOMBRE_LEN) )//Valida que la cadena sea valido como nombre o apellido.
	{
		retorno = 0;
		strncpy(this->nombre,nombre,NOMBRE_LEN);//Si pasa las validaciones del IF, copia lo recibido en la funcion al empleado (this).
	}
	return retorno;
}




int Envios_getNombre(eEnvios* this,char* nombre)
{
	int retorno = -1;

	if( this != NULL && nombre != NULL )//Valida que ambos punteros sean coherentes.
	{
		strncpy(nombre,this->nombre,NOMBRE_LEN);//Asigna al puntero nombre, el nombre cargado en el empleado.
		retorno = 0;
	}
	return retorno;
}

//---------------------------------------

int Envios_setIdCamionTxt(eEnvios* this, char* idCamion)
{
	int retorno = -1;

	if( this != NULL && idCamion != NULL &&//Valida que ambos punteros sean coherentes.
		esNumero(idCamion,INT_LEN) )
	{
		retorno = 0;
		this->idCamion = atoi(idCamion);
	}
	return retorno;
}


int Envios_setIdCamion(eEnvios* this,int idCamion)
{
	int retorno = -1;

	if( this != NULL && idCamion > 0 )
	{
		this->idCamion = idCamion;
		retorno = 0;
	}
	return retorno;
}



int Envios_getIdCamion(eEnvios* this,int* idCamion)
{
    int returnAux = -1;

    if(this != NULL && idCamion != NULL)
    {
        *idCamion = this->idCamion;
        returnAux = 0;
    }

    return returnAux;
}

//------------------------

int Envios_setKmRecorridosTxt(eEnvios* this, char* kmRecorridos)
{
	int retorno = -1;

	if( this != NULL && kmRecorridos!= NULL &&//Valida que ambos punteros sean coherentes.
		esNumero(kmRecorridos,INT_LEN) )//Valida que la cadena sea numerica entera.
	{
		retorno = 0;
		this->kmRecorridos = atoi(kmRecorridos);//Si pasa las validaciones del IF, convierte a entero la cadena recibida y se la asigna al empleado (this).
	}
	return retorno;
}




int Envios_setKmRecorridos(eEnvios* this,int kmRecorridos)
{
	int retorno = -1;

	if( this != NULL && kmRecorridos > 0 )
	{
		this->kmRecorridos = kmRecorridos;
		retorno = 0;
	}
	return retorno;
}


int Envios_getKmRecorridos(eEnvios* this,int* kmRecorridos)
{
    int returnAux = -1;

    if(this != NULL && kmRecorridos != NULL)
    {
        *kmRecorridos = this->kmRecorridos;
        returnAux = 0;
    }

    return returnAux;
}

//----------------------------

int Envios_setTipoEntregaTxt(eEnvios* this, char* tipoEntrega)
{
	int retorno = -1;

	if( this != NULL && tipoEntrega!= NULL &&//Valida que ambos punteros sean coherentes.
		esNumero(tipoEntrega,INT_LEN) )//Valida que la cadena sea numerica entera.
	{
		retorno = 0;
		this->tipoEntrega = atoi(tipoEntrega);//Si pasa las validaciones del IF, convierte a entero la cadena recibida y se la asigna al empleado (this).
	}
	return retorno;
}




int Envios_setTipoEntrega(eEnvios* this,int tipoEntrega)
{
	int retorno = -1;

	if( this != NULL && tipoEntrega > 0 )
	{
		this->tipoEntrega = tipoEntrega;
		retorno = 0;
	}
	return retorno;
}


int Envios_getTipoEntrega(eEnvios* this,int* tipoEntrega)
{
    int returnAux = -1;

    if(this != NULL && tipoEntrega != NULL)
    {
        *tipoEntrega = this->tipoEntrega;
        returnAux = 0;
    }

    return returnAux;
}


//--------------------------
int Envios_setCostoEnvioTxt(eEnvios* this, char* costoEnvio)
{
	int retorno = -1;
		float auxiliar;
		if(this != NULL && costoEnvio >= 0)
		{
			if(esFlotante(costoEnvio))
			{
				auxiliar = atof(costoEnvio);
				if(auxiliar>= 0)
				{
					retorno = 0;
					this->costoEnvio = auxiliar;
				}
			}
		}
		return retorno;
	}




int Envios_setCostoEnvio(eEnvios* this,float costoEnvio)
{
	int retorno = -1;
	if(this != NULL && costoEnvio >= 0)
	{
		retorno = 0;
		this->costoEnvio= costoEnvio;
	}
	return retorno;
}






int Envios_getCostoEnvio(eEnvios* this,float*costoEnvio)

{
    int returnAux = -1;

    if(this != NULL && costoEnvio != NULL)
    {
        *costoEnvio= this->costoEnvio;
        returnAux = 0;
    }

    return returnAux;
}


//--------------------------------



int Envios_setZona(eEnvios* this, char* zona)
{
	int retorno = -1;

	if( this != NULL && zona != NULL &&//Valida que ambos punteros sean coherentes.
		esNombre(zona,ZONA_LEN) )//Valida que la cadena sea valido como nombre o apellido.
	{
		retorno = 0;
		strncpy(this->zona,zona,ZONA_LEN);//Si pasa las validaciones del IF, copia lo recibido en la funcion al empleado (this).
	}
	return retorno;
}




int Envios_getZona(eEnvios* this,char* zona)
{
	int retorno = -1;

	if( this != NULL && zona != NULL )//Valida que ambos punteros sean coherentes.
	{
		strncpy(zona,this->zona,ZONA_LEN);//Asigna al puntero nombre, el nombre cargado en el empleado.
		retorno = 0;
	}
	return retorno;
}













//----------------------------------


void Envios_agregarCosto(void* variableA)
{
	int tipoEntrega;
    float costo;
    int kmRecorridos;


    Envios_getTipoEntrega(variableA, &tipoEntrega);
    Envios_getKmRecorridos(variableA, &kmRecorridos);

    if(tipoEntrega==0)
    {
    	if(kmRecorridos < 50)
    	{
    		costo = (150 * kmRecorridos) + 350;
    		Envios_setCostoEnvio(variableA,costo);
    	}
    	else
    	{
			costo = (100 * kmRecorridos) + 350;
			Envios_setCostoEnvio(variableA,costo);
		}

    }
    else if(tipoEntrega == 1)
    {
    	if(kmRecorridos < 50)
    	{
    		costo = (150 * kmRecorridos) + 420;
    		Envios_setCostoEnvio(variableA,costo);
    	}
    	else
    	{
    		costo = (100 * kmRecorridos) + 420;
    		Envios_setCostoEnvio(variableA,costo);
    	}

    }else if(tipoEntrega == 2)
    {
    	if(kmRecorridos < 50)
    	{
    	    costo = (150 * kmRecorridos) + 275;
    	    Envios_setCostoEnvio(variableA,costo);
    	}
    	else
    	{
    	    costo = (100 * kmRecorridos) + 275;
    	    Envios_setCostoEnvio(variableA,costo);
    	}
    }

}







// para el FILTERR !
int filtroZona11(void* pElement, char* dato)
{
	eEnvios* pEnvio= (eEnvios*)pElement;
	int ret=0;
	char zonaAux[50];

	 strncpy (zonaAux,pEnvio->zona,50);

	if(!strncmp(zonaAux, dato, 50))
		{
			ret = 1;
		}
	else
	{
		ret=0;
	}


	return ret;
}





















/*
int Envio_ordenarPorZona(void* var1, void* var2)
{
    char zona1[50];
    char zona2[50];
    int auxReturn = 0;

	eEnvios* emp1 = (eEnvios*) var1;
	eEnvios* emp2 = (eEnvios*) var2;

    Envios_getZona(var1, zona1);
    Envios_getZona(var2,zona2);

    if(strncmp(zona1, zona2,1000) > 0)
    {
        auxReturn = 1;
    }
    else if(strncmp(zona1, zona2,1000) < 0)
    {
        auxReturn = -1;
    }
    else if(!strncmp(zona1, zona2,1000) )
    {
        auxReturn = -1;
    }

    return auxReturn;
}

*/































//*********************************************************************************************

/**
 * \brief Verifica si la cadena ingresada es un numero entero válido.
 * \param cadena Cadena de caracteres a analizar.
 * \param \param len Define el tamaño de la cadena.
 * \return Retorna 1 si la cadena es un numero entero y 0 si no lo es.
 *
 */
static int esNumero(char* cadena, int len)
{
	int retorno = 0;
	int i;
	if(cadena != NULL && len > 0)//Valida que el puntero sea valido y que el tamañano de cadena sea razonable.
	{
		retorno = 1;
		for(i=0;i<len && cadena[i] != '\0';i++)
		{
			if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))//Valida que la primer posicion de la cadena pueda ser - o +
			{
				continue;//Itera una vez mas.
			}
			if(cadena[i] < '0'||cadena[i] > '9')//Valida que el contenido sea numerico.
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}


static int esNombre(char* cadena, int len)
{
	int retorno = 0;
	int i=0;

	if(cadena != NULL && len > 0)//Valida que el puntero sea valido y que el tamañano de cadena sea razonable.
	{
		retorno = 1;
		for(i=0 ; cadena[i] != '\0' && i < len; i++)//Itera 'i' hasta mientras sea distinta de '\0' y respetando el tamaño del array.
		{
			if( cadena[i] != ' ' && cadena[i] != '-' &&//Valida que se acepten nombres o apellidos compuestos.
				(cadena[i] < 'A' || cadena[i] > 'Z' ) &&//Valida que cadena sea solo letras(Mayus).
				(cadena[i] < 'a' || cadena[i] > 'z' ) )//Valida que cadena sea solo letras(Minus).
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}







static int esFlotante(char* cadena)
{
	int i=0;
	int retorno = 1;
	int contadorPuntos=0;

	if(cadena != NULL && strlen(cadena) > 0)
	{
		for(i=0 ; cadena[i] != '\0'; i++)
		{
			if(i==0 && (cadena[i] == '-' || cadena[i] == '+'))
			{
				continue;
			}
			if(cadena[i] < '0' || cadena[i] > '9' )
			{
				if(cadena[i] == '.' && contadorPuntos == 0)
				{
					contadorPuntos++;
				}
				else
				{
					retorno = 0;
					break;
				}
			}
		}
	}
	return retorno;
}














static int esCuit(char* cadena,int len)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && len > 0)//Valida que el puntero sea valido y que el tamañano de cadena sea razonable.
	{
		for(i=0 ; cadena[i] != '\0' && i < len; i++)
		{
			if( (i==2 || i==11) && (cadena[i] == '-') )//Acepta los guiones del cuit en el indice 2 y 11
			{
				continue;
			}
			if(cadena[i] < '0' || cadena[i] > '9')//Valida que los datos de cadena sean numericos
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}















static int esDescripcion(char* cadena, int len)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && len > 0)//Valida que el puntero sea valido y que el tamañano de cadena sea razonable.
	{
		for(i=0 ; cadena[i] != '\0' && i < len; i++)
		{
			if( cadena[i] != '.' &&
				cadena[i] != '-' &&
				cadena[i] != ',' &&
				cadena[i] != ' ' &&
				(cadena[i] < 'A' || cadena[i] > 'Z' ) &&
				(cadena[i] < 'a' || cadena[i] > 'z' ) &&
				(cadena[i] < '0' || cadena[i] > '9' ) )//Valida que lo recibido en cadena, sean '.', ',', ' ', letras o numeros.
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

