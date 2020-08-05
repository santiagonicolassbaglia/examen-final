#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

#define MENSAJE_LEN 300
#define NOMBRE_LEN 300
#define HORA_LEN 128
#define INT_LEN 128
#define FLOAT_LEN 128

typedef struct
{
    int dia;
    int mes;
    int anio;
}Efecha;


typedef struct
{
    Efecha fecha;
    char hora[HORA_LEN];
    char nombre[NOMBRE_LEN];
    int gravedad;
    char mensaje[MENSAJE_LEN];



} eError;

eError* Error_new();
eError* Error_newParametrosTxt(char* dia,char* mes,char* anio, char* hora,char* nombreStr, char* gravedad,char* mensaje);
eError* Error_newParametros(int dia,int mes,int anio,char* nombreStr, char* hora, int gravedad,char* mensaje);

void Error_delete(eError* this);

int Error_setNombre(eError* this, char* nombre);
int Error_getNombre(eError* this,char* nombre);

int Error_setGravedadTxt(eError* this, char* gravedad);
int Error_setGravedad(eError* this,int gravedad);
int Error_getGravedad(eError* this,int* gravedad);

int Error_setHora(eError* this, char* hora);
int Error_getHora(eError* this,char* hora);

int Error_setMensaje(eError* this, char* mensaje);
int Error_getMensaje(eError* this,char* mensaje);

int error_setDiaTxt(eError* this, char* dia);
int Error_setDia(eError* this,int dia);
int error_getDia(eError* this,int *dia);

int error_setMesTxt(eError* this, char* mes);
int Error_setMes(eError* this,int mes);
int error_getMes(eError* this,int *mes);

int error_setAnioTxt(eError* this, char* anio);
int Error_setAnio(eError* this,int anio);
int error_getAnio(eError* this,int *anio);





int filtroTipo11(void* pElement, int dato);


void Error_agregarCosto(void* variableA);


int Error_imprimir(eError* pEmployee);


int Envio_ordenarPorZona(void* var1, void* var2);





#endif // employee_H_INCLUDED
