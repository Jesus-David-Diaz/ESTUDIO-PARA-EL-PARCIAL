#include <iostream> //incluye la libreria de entrada y salida
#include <string> //incluye la libreria de cadenas de caracteres
using namespace std; //evite escribir std:: antes de cada objeto de la libreria estandar
int main() { //declaracion de la funcion principal

    int a, b; //declaracion de las variables a y b de tipo int
    int perfectos = 0; //declaracion de la variable perfectos de tipo int
    int abundantes = 0; //declaracion de la variable abundantes de tipo int
    int deficientes = 0; //declaracion de la variable deficientes de tipo int

    // Solicitud e ingreso de datos
    cout << "Ingrese a y b (1 <= a <= b): ";
    cin >> a >> b;
    // Validacion del rango
    if (a < 1 || a > b) {
        cout << "Rango invalido." << endl;
        return 0; // Termina el programa si la entrada no cumple las condiciones
    }

//Si a es menor a 1, o a es mayor a b, se imprime un mensaje de error y el programa termina. 

    // Recorrido de cada numero en el intervalo [a, b]
    for (int i = a; i <= b; i++) { 

//se declara i, que guarda el valor de a ingresado por el usuario
//Mientras i sea menor o igual a b, el bucle continua
//después de cada iteración, i se incrementa en 1

        int suma_divisores = 0; //se declara la variable suma_divisores, que almacena la suma de los divisores propios del número i
        // Calculo de la suma de divisores propios
        for (int d = 1; d < i; d++) {

//se declara d, que guarda el valor de 1 (d de divisor)
//Mientras d sea menor a i, el bucle continua
//después de cada iteración, d se incrementa en 1


            if (i % d == 0) { //Si el residuo de la división entre el número i y el divisor d es igual a 0, significa que d es un divisor propio de i
                suma_divisores += d; //Se suma el divisor d a la suma de divisores
            }
        }
        // Clasification del numero e incremento de contadores
        string tipo = ""; //se declara la variable tipo, que almacena el tipo de número (perfecto, abundante o deficiente)
        if (suma_divisores == i) { //Si la suma de los divisores propios es igual al número i, entonces el número es perfecto
            tipo = "perfecto";
            perfectos++;
        } else if (suma_divisores > i) { //Si la suma de los divisores propios es mayor al número i, entonces el número es abundante
            tipo = "abundante";
            abundantes++;
        } else {
            tipo = "deficiente"; //Si la suma de los divisores propios es menor al número i, entonces el número es deficiente
            deficientes++;
        }
        // Impresion del resultado para el numero actual
        cout << i << ": " << tipo << " (suma de divisores = " << suma_divisores << ")" << endl;
    }
    // Impresion del resumen final
    cout << "Perfectos: " << perfectos << ", abundantes: " << abundantes << ", deficientes: " << deficientes << endl;
    return 0;
}