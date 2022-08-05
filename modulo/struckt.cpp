#include <iostream>
#include <windows.h>

using namespace std;

struct Banco
{
    float saldo;
    string nome;
    int numconta;
};

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    float maior = 10000.00, menor = 100.00;
    int aux = 0;
    Banco conta[5];
    conta[0].saldo = 7500.00;
    conta[1].saldo = 2500.00;
    conta[2].saldo = 1000.00;
    conta[3].saldo = 9500.50;
    conta[4].saldo = 9000.40;

    for (int i = 0; i < 5; i++)
    {
        aux++;
        conta[i].numconta = aux++;
        cout << "Insira nome: " << endl;
        cin >> conta[i].nome;
        if (menor < conta[i].saldo)
        {
            menor = conta[i].saldo;
        }
        if (maior > conta[i].saldo)
        {
            maior = conta[i].saldo;
        }
    }
    for (int i = 0; i < 5; i++)
    {
        if (menor == conta[i].saldo)
        {
            cout << " "<< conta[i].numconta << " " << conta[i].nome << " " << menor << endl;
        }
        if (maior == conta[i].saldo)
        {
            cout << endl
                 << conta[i].numconta << " " << conta[i].nome << " " << maior;
        }
    }

    cout << endl
         << endl;
    return 0;
}