#define NOMBRE_LEN 50
#define CUIT_LEN 12

typedef struct {
	char nombre[NOMBRE_LEN];
	char apellido[NOMBRE_LEN];
	char cuit[CUIT_LEN];
	int isEmpty;
	int id;
}Cliente;

int cli_imprimir(Cliente* pElemento);
int cli_inicializarArray(Cliente* array, int limite);
int cli_altaArray(Cliente* array,int limite, int indice, int* id);
int cli_getEmptyIndex(Cliente* array,int limite);
int cli_imprimirArray(Cliente* array,int limite);
int cli_buscarId(Cliente array[], int limite, int valorBuscado);
int cli_modificarArray(Cliente* array,int limite, int indice);
int cli_bajaArray(Cliente* array,int limite, int indice);
void cli_imprimirClientes(int idCliente, int limite);
