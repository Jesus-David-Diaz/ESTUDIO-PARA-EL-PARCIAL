#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n;

    //Lectura del número de filas

    cout << "Numero de filas (1 a 15): ";
    cin >> n;

    // Validación del rango permitido
    if (n < 1 || n > 15) {
        cout << "El número de filas debe estar entre 1 y 15." << endl;
        return 0;
    }

// Ancho fijo para la impresión de los números, ajustado a 4 caracteres
const int ANCHO = 4;

    // Generación de cada fila del triángulo
    for (int i = 0; i < n; i++) {

        // Espacios iniciales para centrar el triángulo en pantalla
        for (int j = 0; j < (n - i - 1); j++) {
            cout << " ";
        }

        long long coef = 1; // C(n, 0) = 1

        for (int k = 0; k <= i; k++) {
            // Imprimimos el coeficiente con un ancho fijo usando setw
            cout << setw(ANCHO/2) << coef;
            cout << " "; // Espacio entre los números
            // Obtenemos el siguiente coeficiente usando la relación dada:
            // C(n, k+1) = C(n, k) * (n - k) / (k + 1)
            coef = coef * (i - k) / (k + 1);
        }
        cout << endl;
    }

    return 0;
}