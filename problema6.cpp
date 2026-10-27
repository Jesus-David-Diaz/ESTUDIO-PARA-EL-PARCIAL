#include <iostream>
#include <string>

using namespace std;

int main() {
    string contraseña;
    //Lectura de la contraseña
    cout << "Ingrese la contraseña: ";
    cin >> contraseña;

    //BANDERAS BOOLEANAS PARA VERIFICAR LOS REQUISITOS
    bool tieneMayuscula = false;
    bool tieneMinuscula = false;
    bool tieneDigito = false;
    bool tieneSimbolo = false;

    //Recorrido de la cadena una sola vez
    for (char c : contraseña) {
        if (c >= 'A' && c <= 'Z') {
            tieneMayuscula = true;
        } else if (c >= 'a' && c <= 'z') {
            tieneMinuscula = true;
        } else if (c >= '0' && c <= '9') {
            tieneDigito = true;
        } else {
            tieneSimbolo = true;
        }
    }

    //Verificación de la longitud mínima
    bool longitudValida = (contraseña.size() >= 8);

    //Evaluación global de los requisitos
    bool esvalida = longitudValida && tieneMayuscula && tieneMinuscula && tieneDigito && tieneSimbolo;

    //Impresion del resultado
    if (esvalida) {
        cout << "La contraseña es válida." << endl;
    } else {
        //Impresión de los requisitos no cumplidos
        if (!longitudValida) {
            cout << "La contraseña debe tener al menos 8 caracteres." << endl;
        }
        if (!tieneMayuscula) {
            cout << "La contraseña debe tener al menos una letra mayúscula." << endl;
        }
        if (!tieneMinuscula) {
            cout << "La contraseña debe tener al menos una letra minúscula." << endl;
        }
        if (!tieneDigito) {
            cout << "La contraseña debe tener al menos un dígito." << endl;
        }
        if (!tieneSimbolo) {
            cout << "La contraseña debe tener al menos un símbolo." << endl;
        }
    }

    return 0;
}