#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

#define ZONA_LEN 300
#define NOMBRE_LEN 128
#define INT_LEN 128
#define FLOAT_LEN 128

typedef struct
{
    int id;
    char nombre[NOMBRE_LEN];
    int idCamion;
    char zona[ZONA_LEN];
    int kmRecorridos;
    int tipoEntrega;

    float costoEnvio;
} eEnvios;

eEnvios* Envios_new();
eEnvios* Envios_newParametrosTxt(char* idStr,char* nombreStr, char* kmStr, char* tipoEntregaStr);
eEnvios* Envios_newParametros(int idStr,char* nombreStr, int kmStr, int tipoEntregaStr);

void Envios_delete(eEnvios* this);

int Envios_setIdTxt(eEnvios* this, char*id);
int Envios_getId(eEnvios* this,int*id);
int Envios_setId(eEnvios* this,int id);

int Envios_setNombre(eEnvios* this,char *nombre);
int Envios_getNombre(eEnvios* this,char*nombre);

int Envios_setIdCamionTxt(eEnvios* this, char* idCamion);
int Envios_setIdCamion(eEnvios* this,int idCamion);
int Envios_getIdCamion(eEnvios* this,int* idCamion);

int Envios_setKmRecorridosTxt(eEnvios* this, char* kmRecorridos);
int Envios_setKmRecorridos(eEnvios* this,int kmRecorridos);
int Envios_getKmRecorridos(eEnvios* this,int* kmRecorridos);

int Envios_setTipoEntregaTxt(eEnvios* this, char* tipoEntrega);
int Envios_setTipoEntrega(eEnvios* this,int tipoEntrega);
int Envios_getTipoEntrega(eEnvios* this,int* tipoEntrega);
int Envios_getTipoEntregaTxt(eEnvios* this,char* tipoEntrega);

int Envios_setCostoEnvioTxt(eEnvios* this, char* costoEnvio);
int Envios_setCostoEnvio(eEnvios* this,float costoEnvio);
int Envios_getCostoEnvio(eEnvios* this,float*costoEnvio);

int Envios_setZona(eEnvios* this, char* zona);
int Envios_getZona(eEnvios* this,char* zona);



int filtroTipo11(void* pElement, int dato);


void Envios_agregarCosto(void* variableA);


int Envios_imprimir(eEnvios* pEmployee);


int Envio_ordenarPorZona(void* var1, void* var2);





#endif // employee_H_INCLUDED
