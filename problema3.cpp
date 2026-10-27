#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main() {
    int n;
    char c;
    // Lectura y validacion de la altura del rombo mediante do-while
    do {
        cout << "Ingrese la altura del rombo (entero impar positivo): ";
        cin >> n;

        if (n <= 0 || n % 2 == 0) {
            cout << "Valor invalido, intente de nuevo." << endl;
        }
    } while (n <= 0 || n % 2 == 0);
    // Lectura del caracter
    cout << "Ingrese el caracter: ";
    cin >> c;
    // Determinacion del indice de la fila central
    int centro = n / 2;
    // Recorrido de cada fila del rombo (de 0 a n - 1)
    for (int i = 0; i < n; i++) {
        // Calculo de la distancia de la fila actual respecto al centro
        int distancia = abs(i - centro);
        // Cantidad de espacios y simbolos a imprimir segun la distancia
        int espacios = distancia;
        int simbolos = n - (2 * distancia);
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