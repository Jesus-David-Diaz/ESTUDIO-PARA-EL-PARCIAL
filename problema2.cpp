#include <iostream>
#include <string>
using namespace std;
int main() {
    int a, b;
    int perfectos = 0;
    int abundantes = 0;
    int deficientes = 0;
    // Solicitud e ingreso de datos
    cout << "Ingrese a y b (1 <= a <= b): ";
    cin >> a >> b;
    // Validacion del rango
    if (a < 1 || a > b) {
        cout << "Rango invalido." << endl;
        return 0; // Termina el programa si la entrada no cumple las condiciones
    }

    // Recorrido de cada numero en el intervalo [a, b]
    for (int i = a; i <= b; i++) {
        int suma_divisores = 0;
        // Paso 4: Calculo de la suma de divisores propios
        for (int d = 1; d < i; d++) {
            if (i % d == 0) {
                suma_divisores += d;
            }
        }
        // Clasification del numero e incremento de contadores
        string tipo = "";
        if (suma_divisores == i) {
            tipo = "perfecto";
            perfectos++;
        } else if (suma_divisores > i) {
            tipo = "abundante";
            abundantes++;
        } else {
            tipo = "deficiente";
            deficientes++;
        }
        // Impresion del resultado para el numero actual
        cout << i << ": " << tipo << " (suma de divisores = " << suma_divisores << ")" << endl;
    }
    // Impresion del resumen final
    cout << "Perfectos: " << perfectos << ", abundantes: " << abundantes << ", deficientes: " << deficientes << endl;
    return 0;
}