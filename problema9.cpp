#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main() {
    int opcion;
    // Presentacion del menu y lectura de la opcion
    cout << "1. Comprimir" << endl;
    cout << "2. Descomprimir" << endl;
    cout << "Opcion: ";
    cin >> opcion;
    // Limpieza del bufer de entrada antes de leer la cadena con getline
    cin.ignore();
    string cadena;
    cout << "Cadena: ";
    getline(cin, cadena);
    if (opcion == 1) {
        // Opcion 1 - Compresion RLE
        string comprimida = "";
        if (!cadena.empty()) {
            char actual = cadena[0];
            int contador = 1;
            // Recorrido de la cadena desde el segundo caracter
            for (size_t i = 1; i < cadena.length(); i++) {
                if (cadena[i] == actual) {
                    contador++;
                } else {
                    // Acumular el caracter y la cantidad convertida a texto con to_string
                    comprimida += actual + to_string(contador);
                    actual = cadena[i];
                    contador = 1;
                }
            }
            // Concatenar el ultimo grupo procesado
            comprimida += actual + to_string(contador);
        }
        cout << "Comprimida: " << comprimida << endl;
    } else if (opcion == 2) {
        // Paso 3: Opcion 2 - Descompresion RLE
        string descomprimida = "";
        bool valido = true;
        if (cadena.empty()) {
            valido = false;
        }
        size_t i = 0;
        while (i < cadena.length() && valido) {
            char c = cadena[i];
            // El elemento actual NO debe ser un digito
            if (isdigit(c)) {
                valido = false;
                break;
            }
            i++; // Avanzar al siguiente indice para buscar la cantidad
            // Debe existir al menos un digito inmediatamente despues del caracter
            if (i >= cadena.length() || !isdigit(cadena[i])) {
                valido = false;
                break;
            }
            // Lectura del numero (soporta cantidades de varios digitos como 12)
            int num = 0;
            while (i < cadena.length() && isdigit(cadena[i])) {
                num = num * 10 + (cadena[i] - '0');
                i++;
            }
            // La cantidad repetida debe ser un numero estrictamente mayor que cero
            if (num <= 0) {
                valido = false;
                break;
            }
            // Reconstruccion agregando el caracter 'c' repetido 'num' veces
            for (int k = 0; k < num; k++) {
                descomprimida += c;
            }
        }
        // Impresion segun el estado de validacion
        if (valido) {
            cout << "Descomprimida: " << descomprimida << endl;
        } else {
            cout << "Formato invalido" << endl;
        }
    } else {
        cout << "Opcion invalida" << endl;
    }
    return 0;
}