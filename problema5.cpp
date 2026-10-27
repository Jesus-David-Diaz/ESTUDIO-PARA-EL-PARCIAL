#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main() {
    string frase;
    // Lectura de la frase completa
    cout << "Ingrese una frase: ";
    getline(cin, frase);
    //Inicializacion de los dos indices y la bandera de control
    int inicio = 0;
    int fin = frase.length() - 1;
    bool es_palindromo = true;
    //Recorrido mediante ciclo while comparando desde los extremos
    while (inicio < fin) {
        // Omitir espacios y signos de puntuacion desde el inicio
        while (inicio < fin && !isalpha(frase[inicio])) {
            inicio++;
        }
        // Omitir espacios y signos de puntuacion desde el final
        while (inicio < fin && !isalpha(frase[fin])) {
            fin--;
        }
        // Comparacion de los caracteres en minuscula
        if (tolower(frase[inicio]) != tolower(frase[fin])) {
            es_palindromo = false;
            break; // Si un par no coincide, se interrumpe la busqueda
        }
        //Avanzar el indice inicial y retroceder el indice final
        inicio++;
        fin--;
    }
    //Impresion del resultado
    if (es_palindromo) {
        cout << "Es palindromo." << endl;
    } else {
        cout << "No es palindromo." << endl;
    }
    return 0;
}