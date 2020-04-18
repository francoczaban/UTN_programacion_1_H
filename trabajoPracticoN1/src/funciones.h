
/* Validar que la opcion del usuario este dentro del rango de las opciones del menu
 * @param opcion ingresada por usuario
 * @return opcion validada
 * */
int validarOpcion(int opcion);

/* Devuelve el numero ingersado por el usuario
 * @return numero ingersado
 * */
int pedirNumero();

/* Devuelve la suma entre 2 numeros
 * @param primer numero
 * @param segunda numero
 * @return resultado suma
 * */
int sumar(int num1, int num2);

/* Devuelve la resta entre 2 numeros
 * @param primer numero
 * @param segunda numero
 * @return resultado resta
 * */
int restar(int num1, int num2);

/* Devuelve la division entre 2 numeros
 * @param primer numero
 * @param segunda numero
 * @return resultado division
 * */
float dividir(int num1, int num2);

/* Devuelve la multiplicacion entre 2 numeros
 * @param primer numero
 * @param segunda numero
 * @return resultado multiplicacion
 * */
int multiplicar(int num1, int num2);

/* Devuelve el factorial del numero ingresado
 * @param primer numero
 * @return factorial del numero
 * */
int factorial(int num);

/* Imprime en pantalla los resultados de las operaciones
 * @param suma
 * @param resta
 * @param division
 * @param multiplicacion
 * @param factorialPrimerNumero
 * @param factorialSegundoNumero
 * */
void imprimirResultados(int rtaSum, int rtaRes, float rtaDiv, int rtaMul, int rtaFacA, int rtaFacB);
