//Incluimos bibliotecas y namespaces respectivos

#include <iostream>
#include <stdlib.h> //para usar el "system ("cls")
#include <locale.h> //para usar caracteres en español
using namespace std;
#include "funciones.h"
#include "funcionPrincipal.h"
#include "funciones.h"


int main()
{
    cout<<"Bienvenido a Ta-te-ti."<<endl;
    cout<<"By: Hernan Villalba."<<endl;
    setlocale(LC_ALL, "spanish"); //para usar caracteres en español
    juego();

    return 0;
}
