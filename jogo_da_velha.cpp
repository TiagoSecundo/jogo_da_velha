#include <iostream>
#include <windows.h>
#include <time.h>
using namespace std;
string j_1, j_2;
char caracter_jogador_1 = 'X', caracter_jogador_2 = 'O';
char matriz[3][3];
bool primeiro = true;
int menu();
void jogo();
void matriz_2();
void tabuleiro();
void jogadores();
void verificar();
int main()
{
    int escolha = menu();
    switch (escolha)
    {
    case 1:
        jogo();
        break;
    case 2:
        cout << "Até a proxima... ";
    default:
        break;
    }
    return 0;
}
int menu()
{ // menu inicial do jogo
    int jogo;
    cout << "----------------------------------------" << endl;
    cout << "      BEM VINDO AO JOGO DA VELHA " << endl;
    cout << "----------------------------------------" << endl;
    cout << " Insira a opçao desejada: " << endl;
    cout << "1. Iniciar jogo. " << endl;
    cout << "2. Sair " << endl;
    cin >> jogo;
    system("cls");

    return jogo;
}

void jogo()
{
    cout << " Insira nome do jogador 1: " << endl;
    cin >> j_1;
    cout << " Insira nome do jogador 2: " << endl;
    cin >> j_2;
    matriz_2();
    tabuleiro();
}
void matriz_2()
{ // criando espaços vazios na funçao

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matriz[i][j] = ' ';
        }
    }
}
void tabuleiro()

{ // escreve tabuleiro
    system("cls");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {

            cout << " " << matriz[i][j] << " ";

            if (j < 2)
            {
                cout << "|";
            }
        }
        cout << endl;

        if (i < 2)
        {
            cout << "___ ___ ___\n";
        }
        cout << endl;
    }
    jogadores();
}

void jogadores()
{
    int linha, coluna;
    cout << "Digite uma linha:" << endl;
    cin >> linha;
    cout << "Digite uma coluna:" << endl;
    cin >> coluna;
    if (matriz[linha][coluna] != ' ')
    {
        cout << "Posição indisponivel, tente novamente";
    }
    else
    {
        if (primeiro)
        {
            matriz[linha][coluna] = caracter_jogador_1;
        }
        else
        {
            matriz[linha][coluna] = caracter_jogador_2;
        }

        primeiro = !primeiro;
    }

    tabuleiro();
}
void verificar()
{
}
