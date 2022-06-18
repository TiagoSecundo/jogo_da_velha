#include <iostream>
#include <windows.h>
#include <time.h>
using namespace std;
string j_1, j_2;
char caracter_jogador_1 = 'X', caracter_jogador_2 = 'O';
char matriz[3][3];
bool primeiro = true;
bool ganhou = false;
bool fim = false;
int cont_jogador1 = 0, cont_jogador2 = 0, cont_empate = 0;
int menu();
void jogo();
void matriz_2();
void tabuleiro();
void jogadores();
bool verificar();
int main() // funcao principal do codigo
{
    int escolha = menu();
    int esc;
    cout << " Insira nome do jogador 1: " << endl;
    cin >> j_1;
    cout << " Insira nome do jogador 2: " << endl;
    cin >> j_2;
    do { 
        jogo();
        cout<<"O jogador " << j_1 << " ganhou " << cont_jogador1 << " partidas." << endl;
        cout<<"O jogador " << j_2 << " ganhou " << cont_jogador2 << " partidas."<< endl;
        cout<<"Partidas empatadas " << cont_empate << endl;
        cout<<"Digite '1' para jogar novamente. "<< endl;
        cout<<"Digite '0' para sair do jogo. " << endl;
        cin>> esc;
    }
    while (esc == 1);

    
     
}
int menu()
{ // menu inicial do jogo
    int jogo1;
    cout << "----------------------------------------" << endl;
    cout << "      BEM VINDO AO JOGO DA VELHA " << endl;
    cout << "----------------------------------------" << endl
         << endl
         << endl;
    cout << " Insira a opcao desejada: " << endl;
    cout << "1. Iniciar jogo. " << endl;
    cout << "2. Sair " << endl;
    cin >> jogo1;
    system("cls");

    return jogo1;
}

void jogo()
{
    
    matriz_2();
    do
    {
        tabuleiro();
        jogadores();
        verificar();
    } while (ganhou == false);
   
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
}

void jogadores()
{ // Recebe nome e as posicoes de jogadas de cada player
    int linha, coluna;

    cout << "Jogador 1 = X " << endl
         << "Jogador 2 = O " << endl;

    cout << "Digite uma linha: (0 ate 2)" << endl;
    cin >> linha;
    cout << "Digite uma coluna:(0 ate 2)" << endl;
    cin >> coluna;
    if (matriz[linha][coluna] != ' ')
    {
        cout << "Posicao indisponivel, tente novamente" << endl;
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
bool verificar()
{ // verifica o ganhador
    if (matriz[0][0] == 'X' && matriz[0][1] == 'X' && matriz[0][2] == 'X' ||
        matriz[1][0] == 'X' && matriz[1][1] == 'X' && matriz[1][2] == 'X' ||
        matriz[2][0] == 'X' && matriz[2][1] == 'X' && matriz[2][2] == 'X' ||
        matriz[0][1] == 'X' && matriz[1][1] == 'X' && matriz[2][1] == 'X' ||
        matriz[0][2] == 'X' && matriz[1][2] == 'X' && matriz[2][2] == 'X' ||
        matriz[0][0] == 'X' && matriz[1][1] == 'X' && matriz[2][2] == 'X' ||
        matriz[0][2] == 'X' && matriz[1][1] == 'X' && matriz[2][0] == 'X' ||
        matriz[0][0] == 'X' && matriz[1][0] == 'X' && matriz[2][0] == 'X')
    {
        cont_jogador1++;
        ganhou = true;
        return true;
    }
    if (matriz[0][0] == 'O' && matriz[0][1] == 'O' && matriz[0][2] == 'O' ||
        matriz[1][0] == 'O' && matriz[1][1] == 'O' && matriz[1][2] == 'O' ||
        matriz[2][0] == 'O' && matriz[2][1] == 'O' && matriz[2][2] == 'O' ||
        matriz[0][1] == 'O' && matriz[1][1] == 'O' && matriz[2][1] == 'O' ||
        matriz[0][2] == 'O' && matriz[1][2] == 'O' && matriz[2][2] == 'O' ||
        matriz[0][0] == 'O' && matriz[1][1] == 'O' && matriz[2][2] == 'O' ||
        matriz[0][2] == 'O' && matriz[1][1] == 'O' && matriz[2][0] == 'O' ||
        matriz[0][0] == 'O' && matriz[1][0] == 'O' && matriz[2][0] == 'O')
    {
        cont_jogador2++;
        ganhou = true;
        return true;
    }
    else if (matriz[0][0] != ' ' && matriz[0][1] != ' ' && matriz[0][2] != ' ' &&
             matriz[1][0] != ' ' && matriz[1][1] != ' ' && matriz[1][2] != ' ' &&
             matriz[2][0] != ' ' && matriz[2][1] != ' ' && matriz[2][2] != ' ')
    {
        cont_empate++;
        ganhou = true;
        return true;
    }
}

