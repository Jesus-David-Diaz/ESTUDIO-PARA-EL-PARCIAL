#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main() {
    char opcion;
    int k;
    string mensaje;
    //Lectura de la opcion (Cifrar/Descifrar) y del desplazamiento k
    cout << "Cifrar (C) o descifrar (D): ";
    cin >> opcion;
    cout << "Desplazamiento: ";
    cin >> k;
    //Limpieza del bufer de entrada antes de usar getline
    cin.ignore();
    // Lectura del mensaje completo
    cout << "Mensaje: ";
    getline(cin, mensaje);
    // Ajuste del desplazamiento si la opcion es descifrar
    if (opcion == 'D' || opcion == 'd') {
        k = -k;
    }
    //Normalizacion del desplazamiento k al rango positivo [0, 25]
    int shift = (k % 26 + 26) % 26;
    //Cifrado/Descifrado caracter por caracter
    string resultado = "";
    for (size_t i = 0; i < mensaje.length(); i++) {
        char c = mensaje[i];
        if (isupper(c)) {
            // Desplazamiento manteniendo mayuscula
            char cifrado = 'A' + (c - 'A' + shift) % 26;
            resultado += cifrado;
        } else if (islower(c)) {
            // Desplazamiento manteniendo minuscula
            char cifrado = 'a' + (c - 'a' + shift) % 26;
            resultado += cifrado;
        } else {
            // Los caracteres no alfabeticos se copian sin cambios
            resultado += c;
        }
    }
    // Impresion del resultado final
    cout << "Resultado: " << resultado << endl;
    return 0;
}