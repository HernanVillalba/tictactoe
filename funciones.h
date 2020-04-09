#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
using namespace std;

const int fil=3,col=3;

void iniciarMatriz(char mat[fil][col])
{
    char num=49;
    for(int f=0; f<fil; f++)
    {
        for(int c=0; c<col; c++)
        {
            mat[f][c]=num;
            num++;
        }
    }
}

void mostrarMatriz(char mat[fil][col])
{
    cout<<"\t\t\t    Tateti\n"<<endl;

    for(int f=0; f<fil; f++)
    {
        cout<<"\t\t\t*---*---*---*"<<endl;
        cout<<"\t\t\t| ";
        for(int c=0; c<col; c++)
        {
            cout<<mat[f][c]<<" | ";
        }
        cout<<endl;
    }
    cout<<"\t\t\t*---*---*---*"<<endl;
}

void turnoJugador(int x)
{
    if(x%2!=0) //si X esta en algunos de esos valores, es el jugador X
    {
        cout<<"\n\t\t     --->Turno de 'X'.<---\n"<<endl;
    }
    else if(x%2==0) //si X esta en algunos de esos valores, es el jugador Y
    {
        cout<<"\n\t\t     --->Turno de 'O'.<---\n"<<endl;
    }
}

void colocarFicha(char mat[fil][col],int* fichas,int turnoYNumeroJugador)
{
    char numUsuario;
    cout<<"¿Donde quiere colocar la ficha?: "; //pregunto la posicion donde se colocara la ficha dentro del menu
    cin>>numUsuario;
    for(int f=0; f<fil; f++)
    {
        for(int c=0; c<col; c++)
        {
            if(numUsuario == mat[f][c])
            {
                if(mat[f][c]!= 'X' && mat[f][c]!= 'O')
                {
                    *fichas+=1;
                    if(turnoYNumeroJugador%2!=0)
                    {
                        mat[f][c]='X';
                    }
                    else if(turnoYNumeroJugador%2==0)
                    {
                        mat[f][c]='O';
                    }
                }
            }
        }
    }

}

void verificarVictoria(char mat[fil][col], int *ganador)
{
    //---------------------verficar para "X"-----------------
    if((mat[0][0]=='X'&&mat[0][1]=='X'&&mat[0][2]=='X')||
            (mat[1][0]=='X'&&mat[1][1]=='X'&&mat[1][2]=='X')|| //lineas verticales
            (mat[2][0]=='X'&&mat[2][1]=='X'&&mat[2][2]=='X'))
    {
        *ganador=1;
    }
    if((mat[0][0]=='X'&&mat[1][0]=='X'&&mat[2][0]=='X')||
            (mat[0][1]=='X'&&mat[1][1]=='X'&&mat[2][1]=='X')|| //lineas horizontales
            (mat[0][2]=='X'&&mat[1][2]=='X'&&mat[2][2]=='X'))
    {
        *ganador=1;
    }
    if((mat[0][0]=='X'&&mat[1][1]=='X'&&mat[2][2]=='X')|| //lineas diagonales
            (mat[0][2]=='X'&&mat[1][1]=='X'&&mat[2][0]=='X'))
    {
        *ganador=1;
    }


    //---------------verficar para "Y"--------------

    if((mat[0][0]=='O'&&mat[0][1]=='O'&&mat[0][2]=='O')||
            (mat[1][0]=='O'&&mat[1][1]=='O'&&mat[1][2]=='O')|| //lineas verticales
            (mat[2][0]=='O'&&mat[2][1]=='O'&&mat[2][2]=='O'))
    {
        *ganador=2;
    }

    if((mat[0][0]=='O'&&mat[1][0]=='O'&&mat[2][0]=='O')||
            (mat[0][1]=='O'&&mat[1][1]=='O'&&mat[2][1]=='O')|| //lineas horizontales
            (mat[0][2]=='O'&&mat[1][2]=='O'&&mat[2][2]=='O'))
    {
        *ganador=2;
    }

    if((mat[0][0]=='O'&&mat[1][1]=='O'&&mat[2][2]=='O')|| //lineas diagonales
            (mat[2][0]=='O'&&mat[1][1]=='O'&&mat[0][2]=='O'))
    {
        *ganador=2;
    }

}

void mostrarGanador(int ganador)
{
    if(ganador==1)
    {
        cout<<"\n\t\tGana el jugador 'X'!!!\n";
    }
    else if(ganador==2)
    {
        cout<<"\n\t\tGana el jugador 'O'!!!\n";
    }
    else if (ganador==0)
    {
        cout<<"\n\t\tNo hay ganadores.\n";
    }
    cin.get();
}

int usuarioOpcionSalir()
{
    int opcion;
    do
    {
        system("cls");
        cout<<"Desea jugar nuevamente?"<<endl;
        cout<<"A) Si."<<endl;
        cout<<"B) No."<<endl;
        cout<<"Opcion: ";
        cin>>opcion;
        cin.ignore();
        system("cls");

        switch(opcion)
        {
        case 1:
        {
            return 1;
        }
        break;

        case 2:
        {
            cout<<"Muchas gracias por jugar!!! nos vemos."<<endl;
            system("pause");
            return 2;
        }
        break;

        default:
        {
            cout<<"Opcion incorrecta!!!"<<endl<<endl;
            system("pause");
        }
        break;
        }
    }
    while(opcion!=2);
}

#endif // FUNCIONES_H_INCLUDED
