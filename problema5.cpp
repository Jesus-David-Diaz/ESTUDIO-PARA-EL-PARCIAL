#include <iostream> //Incluye la libreria de entrada y salida
#include <string> //incluye la libreria para cadenas
#include <cctype> //incluye la libreria para funciones de caracteres
using namespace std; //evita escribir std:: antes de cada elemento de la biblio estándar
int main() { //declara la función principal
    string frase; //declara la variable frase

    // Lectura de la frase completa
    cout << "Ingrese una frase: "; 
    getline(cin, frase); //lee y guarda la frase completa 

    //Inicializacion de los dos indices y la bandera de control
    int inicio = 0; //se declara la variable inicio con el valor de 0
    int fin = frase.length() - 1; //se declara la variable fin, que es igual a la longitud de la frase menos 1, porque se inicializa en 0
    bool es_palindromo = true; //se declara la variable es_palindromo con un valor VERDADERO

    //Recorrido mediante ciclo while comparando desde los extremos
    while (inicio < fin) { //mientras el inicio sea menor que el final
        
        // Omitir espacios y signos de puntuacion desde el inicio
        while (inicio < fin && !isalpha(frase[inicio])) {
            inicio++;
        }

//MIENTRAS EL INICIO SEA MENOR AL FINAL YYYYYYYY la frase tenga espacios y signos de puntuación, el inicio aumenta un caracter en la frase

        // Omitir espacios y signos de puntuacion desde el final
        while (inicio < fin && !isalpha(frase[fin])) {
            fin--;
        }

//MIENTRAS EL INICIO SEA MENOR AL FINAL YYYYYYYY la frase tenga espacios y signos de puntuación, el final decrece un caracter en la frase

        // Comparacion de los caracteres en minuscula
        if (tolower(frase[inicio]) != tolower(frase[fin])) {
            es_palindromo = false;
            break; // Si un par no coincide, se interrumpe la busqueda
        }

//Si la frase en minúsculas desde el inicio es diferente a la frase en minusculas por el final, entonces NO ES PALÍNDROMO

        //Avanzar el indice inicial y retroceder el indice final para seguir evaluando la frase
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