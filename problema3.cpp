#include <iostream> //incluye la biblioteca de entrada y salida
#include <string> //incluye la biblioteca de cadenas
#include <cmath> //incluye la biblioteca de funciones matematicas
using namespace std; //evita tener que escribir std:: antes de cada elemento de la biblioteca estándar
int main() { //funcion principal del programa
    int n; // Declaracion de la variable para la altura del rombo   
    char c; // Declaracion de la variable para el caracter a utilizar en el rombo
    // Lectura y validacion de la altura del rombo mediante do-while

    do { // Inicio del bucle do-while para la validacion de la altura
        cout << "Ingrese la altura del rombo (entero impar positivo): ";
        cin >> n;

        if (n <= 0 || n % 2 == 0) { //si n es menor o igual a 0 o n es par, se imprime un mensaje de error y se solicita nuevamente la entrada
            cout << "Valor invalido, intente de nuevo." << endl;
        }
    } while (n <= 0 || n % 2 == 0); 

//Si no se cumple que n sea mayor a 0 y n sea impar, el bucle se repite solicitando nuevamente la entrada del usuario

    // Lectura del caracter, al romper el bucle do-while

    cout << "Ingrese el caracter: ";
    cin >> c;
    // Determinacion del indice de la fila central
    int centro = n / 2; 
    //Se declara la variable centro, que almacena el indice de la fila central del rombo, calculado como n dividido entre 2
    // Como c++ utiliza indices basados en cero, la fila central se encuentra en el indice n/2
    //c++ quita el resultado decimal de la division, por lo que si n es 5, centro sera 2 (la tercera fila)


    // Recorrido de cada fila del rombo (de 0 a n - 1)
    for (int i = 0; i < n; i++) { 
//se declara i, que guarda la fila actual, se inicia en 0 porque c++ empieza desde 0, pero i=0 es la primera fila
//Mientras i sea menor a n, el bucle continua
//después de cada iteración, i se incrementa en 1

        // Calculo de la distancia de la fila actual respecto al centro
        int distancia = abs(i - centro);

//abs es una función de valor absoluto, así, evaluando la fila 0, la distancia será 2 (la fila central es 2, y 0 - 2 = -2, cuyo valor absoluto es 2)


        // Cantidad de espacios y simbolos a imprimir segun la distancia
        int espacios = distancia; 
        //la cantidad de espacios en las filas que no sean el centro, es igual a la distancia entre la fila centro y la fila que se está evaluando

        //Cantidad de simbolos que se van a imprimir por fila
        int simbolos = n - (2 * distancia);
//la cantidad de simbolos que se van a imprimir disminuyen simétricamente con cada fila



        // Impresion de espacios iniciales
        for (int j = 0; j < espacios; j++) {
            cout << " ";
        }
        // Impresion de los caracteres del rombo
        for (int j = 0; j < simbolos; j++) {
            cout << c;
        }
        // Salto de linea al finalizar la fila
        cout << endl;
    }
    return 0;
}