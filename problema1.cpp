#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main() {
    string frase;
    int vocales = 0;
    int consonantes = 0;
    int digitos = 0;
    int espacios = 0;
    int otros = 0;
    // Lectura de la frase completa
    cout << "Ingrese una frase: ";
    getline(cin, frase);
    // Recorrido caracter por caracter
    for (size_t i = 0; i < frase.length(); i++) {
        char c = frase[i];
        if (isdigit(c)) {
            digitos++;
        } else if (isspace(c)) {
            espacios++;
        } else if (isalpha(c)) {
            char min = tolower(c);
            if (min == 'a' || min == 'e' || min == 'i' || min == 'o' || min == 'u') {
                vocales++;
            } else {
                consonantes++;
            }
        } else {
            otros++;
        }
    }
    // Impresion de resultados
    cout << "Vocales: " << vocales << endl;
    cout << "Consonantes: " << consonantes << endl;
    cout << "Digitos: " << digitos << endl;
    cout << "Espacios: " << espacios << endl;
    cout << "Otros simbolos: " << otros << endl;

    return 0;
}