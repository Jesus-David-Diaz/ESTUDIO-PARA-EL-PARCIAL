#include <iostream>

using namespace std;

int main() {
    long long N;
    cout << "Ingrese N (>= 1): ";
    cin >> N;

    if (N < 1) {
        cout << "El valor de N debe ser mayor o igual a 1." << endl;
        return 0;
    }

    long long mejor_numero = 1;
    long long max_pasos = -1;
    long long max_valor_alcanzado = 1;

    // Evaluamos cada valor inicial desde 1 hasta N
    for (long long i = 1; i <= N; i++) {
        long long x = i;
        long long pasos = 0;
        long long valor_max_secuencia = i;

        // Simulamos la secuencia de Collatz hasta llegar a 1
        while (x > 1) {
            if (x > valor_max_secuencia) {
                valor_max_secuencia = x;
            }

            if (x % 2 == 0) {
                x = x / 2;
            } else {
                x = 3 * x + 1;
            }
            pasos++;
        }

        // Si encuentra una secuencia estrictamente mayor en pasos, actualizamos el mejor caso
        // (Al usar '>' estrictamente, si hay empate conservamos el primer número encontrado)
        if (pasos > max_pasos) {
            max_pasos = pasos;
            mejor_numero = i;
            max_valor_alcanzado = valor_max_secuencia;
        }
    }

    // Mostramos los resultados según el formato solicitado
    cout << "Numero con la secuencia mas larga: " << mejor_numero << endl;
    cout << "Pasos: " << max_pasos << endl;
    cout << "Valor maximo alcanzado: " << max_valor_alcanzado << endl;

    return 0;
}