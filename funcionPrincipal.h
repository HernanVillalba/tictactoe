#ifndef FUNCIONPRINCIPAL_H_INCLUDED
#define FUNCIONPRINCIPAL_H_INCLUDED

void juego()
{
    setlocale(LC_ALL, "spanish"); //para usar caracteres en español
    const int f=3, c=3;
    char matriz[f][c];

    iniciarMatriz(matriz);
    cin.ignore();

    int ganador=0,fichas=1,turnoYNumeroJugador=0;
    while(fichas <= 10 || ganador != 0)
    {
        turnoYNumeroJugador++;
        system("cls");
        mostrarMatriz(matriz);
        if(fichas==10) //este if sirve para mostrar la ultima ficha colocada en el caso de que no haya ganadores
        {
            break;
        }
        turnoJugador(fichas); //muestra a quien le toca el turno
        colocarFicha(matriz,&fichas,turnoYNumeroJugador); //coloco la ficha en la posicion ingesada por el jugador
        verificarVictoria(matriz,&ganador); //verifica si hay un ganador, pasando "ganador" por referencia para que me modifique el valor original en 0

        //verifico si ganó algún jugador para cortar el ciclo for
        if(ganador==1)
        {
            system("cls"); //si es asi,borro el dibujo y lo vuelvo a mostrar para mostrar la ultima ficha colocada.
            mostrarMatriz(matriz);
            break; //corto el for
        }
        else if(ganador==2)
        {
            system("cls");
            mostrarMatriz(matriz);
            break;
        }
    }

    mostrarGanador(ganador);
    cin.get();

    int opcionSalir;
    opcionSalir=usuarioOpcionSalir();
    if(opcionSalir==1)
    {
        return juego();
    }
    else
    {
        return;
    }

}


#endif // FUNCIONPRINCIPAL_H_INCLUDED
