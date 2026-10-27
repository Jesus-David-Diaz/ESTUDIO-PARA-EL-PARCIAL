#include <iostream> //incluye la libreria de entrada y salida
#include <string> //incluye la libreria de cadenas de caracteres
#include <cctype> //incluye la libreria de funciones para caracteres
using namespace std; //evite escribir std:: antes de cada objeto de la libreria estandar
int main() { //declaracion de la funcion principal

    string frase; //declaracion de la variable frase de tipo string
    int vocales = 0; //declaracion de la variable vocales de tipo int
    int consonantes = 0; //declaracion de la variable consonantes de tipo int
    int digitos = 0; //declaracion de la variable digitos de tipo int
    int espacios = 0; //declaracion de la variable espacios de tipo int
    int otros = 0; //declaracion de la variable otros de tipo int

    // Lectura de la frase completa
    cout << "Ingrese una frase: ";
    getline(cin, frase); //lee una linea completa de texto ingresada en consola y la almacena en la variable frase

    // Recorrido caracter por caracter
    for (size_t i = 0; i < frase.length(); i++) { 

        //size_t es un tipo de dato que no tiene signo y evita problemas con .length
        //i guarda la posición de cada caracter empezando en 0
        //i < frase.length() es la condición, mientras i sea menor a la longitud, el bucle continua
        //i++ incrementa i en 1 en cada iteración del bucle


        char c = frase[i]; //declara la variable c, que almacena el caracter de la frase en la posición i
        if (isdigit(c)) { 
            digitos++;
        } else if (isspace(c)) {
            espacios++;
        } else if (isalpha(c)) {
            char min = tolower(c); //convierte el caracter a minuscula para facilitar la comparación
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