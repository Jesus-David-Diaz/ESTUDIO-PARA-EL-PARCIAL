#include <iostream> //Incluye la biblioteca de entrada y saliga
#include <string> //Incluye la biblioteca de cadenas

using namespace std; //evita escribir std:: antes de cada elemento de la biblio estándar

int main() { //declaración de la función principal
    string contraseña; //declaramos una variable de tipo string
    //Lectura de la contraseña
    cout << "Ingrese la contraseña: "; 
    cin >> contraseña; 

    //BANDERAS BOOLEANAS PARA VERIFICAR LOS REQUISITOS
    bool tieneMayuscula = false; 
    bool tieneMinuscula = false;
    bool tieneDigito = false;
    bool tieneSimbolo = false;

//Se asume que las banderas son falsas para cada requisito porque luego se van a verificar,
// si cambian su valor a verdadero, se verá reflejado en la salida


    //Recorrido de la cadena una sola vez
    for (char c : contraseña) {
//introducimos un ciclo for, donde declaramos una variable c de tipo char, es decir, que guarda un carácter

        if (c >= 'A' && c <= 'Z') {
            tieneMayuscula = true;
            //Si el carácter c contiene letras mayúsculas, la bandera tieneMayuscula cambia su valor a true
        } else if (c >= 'a' && c <= 'z') {
            tieneMinuscula = true;
            //Si el carácter c contiene letras minúsculas, la bandera tieneMinuscula cambia su valor a true
        } else if (c >= '0' && c <= '9') {
            tieneDigito = true;
            //Si el carácter c tiene un dígito (1-9), la bandera tieneDigito cambia su valor a true
        } else {
            tieneSimbolo = true;
            //Si el caracter c no tiene ni mayuscula, ni minuscula, ni digito, si o si debe tener símbolo, por tanto, la bandera booleana cambia a true
        }
    }

    //Verificación de la longitud mínima
    bool longitudValida = (contraseña.size() >= 8);

    //Se introduce otra variable booleana (longitudValida), que debe tener un tamaño mayor o igual a 8, si esto se cumple,
    //la bandera toma un valor verdadero, si no, toma un valor falso

    //Evaluación global de los requisitos
    bool esvalida = longitudValida && tieneMayuscula && tieneMinuscula && tieneDigito && tieneSimbolo;

    //Se define otra variable booleana donde se reunen todos los requisitos, si falta uno, la boolena toma un valor falso 

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