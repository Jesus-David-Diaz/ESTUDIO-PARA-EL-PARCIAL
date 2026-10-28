#include <iostream> //incluye  la biblio de entrada y salida
#include <string> //incluye la biblio de cadenas

using namespace std; //evita escribir std:: antes de cada elemento de la biblio estándar

int main() { //declara la funcion principal
    int numero; //declara un numero entero

    //Leer un número entero
    cout << "Ingrese un numero entero entre 1 y 3999: ";
    cin >> numero;

    //Validar el rango del número
    if (numero < 1 || numero > 3999) {
        cout << "El numero ingresado no esta en el rango permitido." << endl;
    } else{
        //Arreglos con los valores decimales sus representaciones en numeros romanos
        //Incluye las formas esenciales de los números romanos (900, 400, 90, 40, 9, 4
        const int TAM = 13; //se añade la constante TAM con los 13 valores posibles
        int valores[TAM] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1}; //Los valores TAM son los números con escrituras en romanos diferentes
        string romanos[TAM] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"}; //Los romanos TAM son las escrituras de los numeros

        //Variable para almacenar el resultado en números romanos
        string resultado = ""; 
        int aux = numero; //se declara un auxiliar que es igual al número ingresado en consola

        //Algoritmo para convertir el número decimal a romano
        for (int i = 0; i < TAM; i++) {

            //Se declara el numero entero i con un valor de cero
            //Mientras i sea menor a la casilla TAM, el bucle se repite
            //Con cada iteración, i se incrementa en 1

            while (aux >= valores[i]) {

                //mientras el auxiliar sea mayor o igual al valor de la casilla i
                resultado += romanos[i];
                aux -= valores[i];
            }
        }
        //Impresión del resultado
        cout << "El numero " << numero << " en numeros romanos es: " << resultado << endl;
    }
return 0;
}