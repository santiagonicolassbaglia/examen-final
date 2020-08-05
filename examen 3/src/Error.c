/*
 * Employee.c
 *
 *  Created on: 21 jun. 2020
 *      Author: admin
 */


#include "Error.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"

static int esNumero(char* cadena, int len);
static int esNombre(char* cadena, int len);
static int esFlotante(char* cadena);
static int esCuit(char* cadena,int len);
static int esDescripcion(char* cadena, int len);
/**
 * \brief Solicita un espacio en memoria para un empleado.*
 */



eError* Error_new()
{
	  eError* auxiliarP = NULL;
		auxiliarP = (eError*) malloc(sizeof(eError));
		return auxiliarP;

}


/**
 * \brief Borra de memoria el espacio ocupado por un empleado.

 */
void Error_delete(eError* this)
{
	if( this != NULL )//Valida que el puntero al empleado no sea NULL.
	{
		free(this);//Libera espacio en memoria que ocupa el empleado reibido en la funcion.
	}
}



//Crea un nuevo empleado, recibiendo TODOS los elementos de tipo cadena de caracteres.

eError* Error_newParametrosTxt(char* dia,char* mes,char* anio, char* hora,char* nombreStr, char* gravedad,char* mensaje)
{
	eError* nuevoError ;
	int flag = 0;

	nuevoError = Error_new();//Asigna espacio en memoria para el empleado.


	if( nuevoError != NULL &&
		  dia != NULL && mes != NULL && anio != NULL && hora != NULL && nombreStr != NULL && gravedad != NULL && mensaje != NULL &&
		!error_setDiaTxt(nuevoError,dia) &&
		!error_setMesTxt(nuevoError,mes) &&
		!error_setAnioTxt(nuevoError,anio) &&
		!Error_setNombre(nuevoError, nombreStr) &&
		!Error_setHora(nuevoError,hora) &&
		!Error_setGravedadTxt(nuevoError,gravedad)&&
		!Error_setMensaje(nuevoError,mensaje))



	{
		flag = 1;//Si pasa las validaciones del IF, crea un nuevo empleado y cambia el estado de flag a 1 para que NO entre en el siguiente IF.
	}
	if( flag == 0 )//En caso de que no se hayan pasado las validaciones del IF anterior, va a entrar en este IF.
	{
		Error_delete(nuevoError);//Si entra en este IF, se va a liberar el espacio en memoria brindado a auxEmployee ya que no se cargaron los datos correctamente.
		nuevoError = NULL;//Se apunta el auxEmployee a NULL.
	}
	return nuevoError;
}









eError* Error_newParametros(int dia,int mes,int anio,char* nombreStr, char* hora, int gravedad,char* mensaje)
{
	eError* nuevoError ;
	int flag = 0;

	nuevoError =Error_new();//Asigna espacio en memoria para el empleado.


	if( nuevoError != NULL &&//Valida que esa direccion no sea NULL.
			 dia > 0 && mes > 0 && anio > 0 && hora != NULL && nombreStr != NULL && gravedad > 0 && mensaje != NULL &&

		        !Error_setDia(nuevoError,dia) &&
				!Error_setMes(nuevoError,mes) &&
				!Error_setAnio(nuevoError,anio) &&
				!Error_setNombre(nuevoError, nombreStr) &&
				!Error_setHora(nuevoError,hora) &&
				!Error_setGravedad(nuevoError,gravedad)&&
				!Error_setMensaje(nuevoError,mensaje))

	{
		flag = 1;//Si pasa las validaciones del IF, crea un nuevo empleado y cambia el estado de flag a 1 para que NO entre en el siguiente IF.
	}
	if( flag == 0 )//En caso de que no se hayan pasado las validaciones del IF anterior, va a entrar en este IF.
	{
		Error_delete(nuevoError);//Si entra en este IF, se va a liberar el espacio en memoria brindado a auxEmployee ya que no se cargaron los datos correctamente.
		nuevoError = NULL;//Se apunta el auxEmployee a NULL.
	}
	return nuevoError;
}







//------------------

int Error_setNombre(eError* this, char* nombre)
{
	int retorno = -1;

	if( this != NULL && nombre != NULL &&//Valida que ambos punteros sean coherentes.
		esDescripcion(nombre,NOMBRE_LEN) )//Valida que la cadena sea valido como nombre o apellido.
	{
		retorno = 0;
		strncpy(this->nombre,nombre,NOMBRE_LEN);//Si pasa las validaciones del IF, copia lo recibido en la funcion al empleado (this).
	}
	return retorno;
}



int Error_getNombre(eError* this,char* nombre)
{
	int retorno = -1;

	if( this != NULL && nombre != NULL )//Valida que ambos punteros sean coherentes.
	{
		strncpy(nombre,this->nombre,NOMBRE_LEN);//Asigna al puntero nombre, el nombre cargado en el empleado.
		retorno = 0;
	}
	return retorno;
}



//------------------------

int Error_setGravedadTxt(eError* this, char* gravedad)
{
	int retorno = -1;

	if( this != NULL && gravedad!= NULL &&//Valida que ambos punteros sean coherentes.
		esNumero(gravedad,INT_LEN) )//Valida que la cadena sea numerica entera.
	{
		retorno = 0;
		this->gravedad = atoi(gravedad);//Si pasa las validaciones del IF, convierte a entero la cadena recibida y se la asigna al empleado (this).
	}
	return retorno;
}




int Error_setGravedad(eError* this,int gravedad)
{
	int retorno = -1;

	if( this != NULL && gravedad > 0 )
	{
		this->gravedad = gravedad;
		retorno = 0;
	}
	return retorno;
}


int Error_getGravedad(eError* this,int* gravedad)
{
    int returnAux = -1;

    if(this != NULL && gravedad != NULL)
    {
        *gravedad = this->gravedad;
        returnAux = 0;
    }

    return returnAux;
}

//----------------------------


int Error_setHora(eError* this, char* hora)
{
	int retorno = -1;

	if( this != NULL && hora != NULL &&//Valida que ambos punteros sean coherentes.
		esDescripcion(hora,HORA_LEN) )//Valida que la cadena sea valido como nombre o apellido.
	{
		retorno = 0;
		strncpy(this->hora,hora,HORA_LEN);//Si pasa las validaciones del IF, copia lo recibido en la funcion al empleado (this).
	}
	return retorno;
}




int Error_getHora(eError* this,char* hora)
{
	int retorno = -1;

	if( this != NULL && hora != NULL )//Valida que ambos punteros sean coherentes.
	{
		strncpy(hora,this->hora,HORA_LEN);//Asigna al puntero nombre, el nombre cargado en el empleado.
		retorno = 0;
	}
	return retorno;
}




//-------------------------


int Error_setMensaje(eError* this, char* mensaje)
{
	int retorno = -1;

	if( this != NULL && mensaje != NULL &&//Valida que ambos punteros sean coherentes.
		esDescripcion(mensaje,MENSAJE_LEN) )//Valida que la cadena sea valido como nombre o apellido.
	{
		retorno = 0;
		strncpy(this->mensaje,mensaje,MENSAJE_LEN);//Si pasa las validaciones del IF, copia lo recibido en la funcion al empleado (this).
	}
	return retorno;
}




int Error_getMensaje(eError* this,char* mensaje)
{
	int retorno = -1;

	if( this != NULL && mensaje != NULL )//Valida que ambos punteros sean coherentes.
	{
		strncpy(mensaje,this->mensaje,MENSAJE_LEN);//Asigna al puntero nombre, el nombre cargado en el empleado.
		retorno = 0;
	}
	return retorno;
}







//-------------------------



int error_setDiaTxt(eError* this, char* dia)
{
	int retorno = -1;

	if( this != NULL && dia != NULL &&//Valida que ambos punteros sean coherentes.
		esNumero(dia,31) )//Valida que la cadena sea numerica entera.
	{
		retorno = 0;
		this->fecha.dia = atoi(dia);//Si pasa las validaciones del IF, convierte a entero la cadena recibida y se la asigna al empleado (this).
	}
	return retorno;
}




int Error_setDia(eError* this,int dia)
{
	int retorno = -1;

	if( this != NULL && dia > 0 )
	{
		this->fecha.dia = dia;
		retorno = 0;
	}
	return retorno;
}





int error_getDia(eError* this,int *dia)
{
    int auxRetorno=-1 ;

    if ( this != NULL && dia!=NULL)
    {
        *dia = this->fecha.dia;
        auxRetorno = 0;
    }

    return auxRetorno;
}

//**********************
int error_setMesTxt(eError* this, char* mes)
{
	int retorno = -1;

	if( this != NULL && mes != NULL &&//Valida que ambos punteros sean coherentes.
		esNumero(mes,12) )//Valida que la cadena sea numerica entera.
	{
		retorno = 0;
		this->fecha.mes = atoi(mes);//Si pasa las validaciones del IF, convierte a entero la cadena recibida y se la asigna al empleado (this).
	}
	return retorno;
}




int Error_setMes(eError* this,int mes)
{
	int retorno = -1;

	if( this != NULL && mes > 0 )
	{
		this->fecha.mes = mes;
		retorno = 0;
	}
	return retorno;
}







int error_getMes(eError* this,int *mes)
{
    int auxRetorno=-1 ;

    if ( this != NULL && mes!=NULL)
    {
        *mes = this->fecha.mes;
        auxRetorno = 0;
    }

    return auxRetorno;
}

int error_setAnioTxt(eError* this, char* anio)
{
	int retorno = -1;

	if( this != NULL && anio != NULL &&//Valida que ambos punteros sean coherentes.
		esNumero(anio,3000) )//Valida que la cadena sea numerica entera.
	{
		retorno = 0;
		this->fecha.anio = atoi(anio);//Si pasa las validaciones del IF, convierte a entero la cadena recibida y se la asigna al empleado (this).
	}
	return retorno;
}





int Error_setAnio(eError* this,int anio)
{
	int retorno = -1;

	if( this != NULL && anio > 0 )
	{
		this->fecha.anio = anio;
		retorno = 0;
	}
	return retorno;
}





int error_getAnio(eError* this,int *anio)
{
    int auxRetorno=-1 ;

    if ( this != NULL && anio!=NULL)
    {
        *anio = this->fecha.anio;
        auxRetorno = 0;
    }

    return auxRetorno;
}




//----------------------------------








/*





void Error_agregarCosto(void* variableA)
{
	int tipoEntrega;
    float costo;
    int kmRecorridos;


    Error_getTipoEntrega(variableA, &tipoEntrega);
    Error_getKmRecorridos(variableA, &kmRecorridos);

    if(tipoEntrega==1)
    {
    	if(kmRecorridos < 45)
    	{
    		costo = (77 * kmRecorridos) + 90;
    		Error_setCostoEnvio(variableA,costo);
    	}
    	else
    	{
			costo = (90 * kmRecorridos) + 90;
			Error_setCostoEnvio(variableA,costo);
		}

    }
    else if(tipoEntrega == 2)
    {
    	if(kmRecorridos < 45)
    	{
    		costo = (77 * kmRecorridos) + 350;
    		Error_setCostoEnvio(variableA,costo);
    	}
    	else
    	{
    		costo = (90 * kmRecorridos) + 350;
    		Error_setCostoEnvio(variableA,costo);
    	}

    }else if(tipoEntrega == 3)
    {
    	if(kmRecorridos < 45)
    	{
    	    costo = (77 * kmRecorridos) + 580;
    	    Error_setCostoEnvio(variableA,costo);
    	}
    	else
    	{
    	    costo = (90 * kmRecorridos) + 580;
    	    Error_setCostoEnvio(variableA,costo);
    	}
    }

}








// para el FILTERR !
int filtroTipo11(void* pElement, int dato)
{
	eError* pEnvio= (eError*)pElement;
	int ret=0;
	int tipo;

	tipo=pEnvio->tipoEntrega;


	if(tipo== dato)
		{
			ret = 1;
		}
	else
	{
		ret=0;
	}


	return ret;
}








*/











/*
int Envio_ordenarPorZona(void* var1, void* var2)
{
    char zona1[50];
    char zona2[50];
    int auxReturn = 0;

	eError* emp1 = (eError*) var1;
	eError* emp2 = (eError*) var2;

    Error_getZona(var1, zona1);
    Error_getZona(var2,zona2);

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
			    cadena[i] != '_' &&
				cadena[i] != ':' &&
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

