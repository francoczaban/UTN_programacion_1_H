#define ESTADO_PAUSADO	0
#define ESTADO_ACTIVO	1
#define TEXTO_LEN 65

typedef struct{
	char texto[TEXTO_LEN];
	int isEmpty;
	int idPub;
	int idCliente;
	int rubro;
	int estado;
}Publicaciones;


int pub_imprimir(Publicaciones* auxAviso);
int pub_inicializarArray(Publicaciones* array, int limite);
int pub_altaArray(Publicaciones* array, int limite, int indice, int* idPub, int idCliente);
int pub_getEmptyIndex(Publicaciones* array, int limite);
int pub_imprimirArray(Publicaciones* array, int limite);
int pub_buscarId(Publicaciones array[], int limite, int valorBuscado);
int pub_modificarArray(Publicaciones* array, int limite, int indice, int pausa);
int pub_bajaArray(Publicaciones* array, int limite, int indice);
int pub_ordenarPorNombre(Publicaciones* array, int limite);
int pub_altaForzadaArray(Publicaciones* array,int limite, int indice, int* idPub, int* idCliente, char* texto, int* rubro, int* estado);
