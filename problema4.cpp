#include <iostream>
#include <string>

using namespace std;

int main() {
    int numero;

    //Leer un número entero
    cout << "Ingrese un numero entero entre 1 y 3999: ";
    cin >> numero;

    //Validar el rango del número
    if (numero < 1 || numero > 3999) {
        cout << "El numero ingresado no esta en el rango permitido." << endl;
    } else{
        //Arreglos con los valores decimales sus representaciones en numeros romanos
        //Incluye las formas esenciales de los números romanos (900, 400, 90, 40, 9, 4
        const int TAM = 13;
        int valores[TAM] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string romanos[TAM] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        //Variable para almacenar el resultado en números romanos
        string resultado = "";
        int aux = numero;

        //Algoritmo para convertir el número decimal a romano
        for (int i = 0; i < TAM; i++) {
            while (aux >= valores[i]) {
                resultado += romanos[i];
                aux -= valores[i];
            }
        }
        //Impresión del resultado
        cout << "El numero " << numero << " en numeros romanos es: " << resultado << endl;
    }
return 0;
}