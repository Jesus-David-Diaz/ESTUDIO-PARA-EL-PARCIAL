#include <iostream> //Incluye la biblioteca de entrada y salida
#include <string> //incluye la biblioteca de cadenas
#include <cctype> //Incluye las funciones caracteres
using namespace std; //evita escribir std:: antes de cada elemento de la biblio estándar
int main() { //Declaración de la funcion principal
    char opcion; //Declaramos una variable opción con el tipo de dato de caracter
    int k; //Declaramos una variable de tipo entero, con el nombre k
    string mensaje; //declaramos una variable de tipo string con el nombre de mensaje

    
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