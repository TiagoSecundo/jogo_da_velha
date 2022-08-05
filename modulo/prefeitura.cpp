#include <iostream>
#include <windows.h>

using namespace std;

struct Prefeitura
{
    string nome;
    char sexo;
    float salario;
    int idade, filhos;
};

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    Prefeitura pesquisa[20];
    int media_filhos = 0;
    float media_salario = 0.0, maior_salario = 0.0, percentural_F = 0.0, aux = 0.0, cont=0.0;

    for (int i = 0; i < 20; i++)
    {
        // aux++;
        cout << "Insira nome: " << endl;
        cin >> pesquisa[i].nome;
        cout << "Insira sexo: (m/f)" << endl;
        cin >> pesquisa[i].sexo;
        cout << "Insira salario: " << endl;
        cin >> pesquisa[i].salario;
        cout << "Insira idade: " << endl;
        cin >> pesquisa[i].idade;
        cout << "Insira numero de filhos: " << endl;
        cin >> pesquisa[i].filhos;
        if (maior_salario < pesquisa[i].salario)
        {
            maior_salario = pesquisa[i].salario;
        }
        if (pesquisa[i].sexo == 'f' && pesquisa[i].salario >= 1000.00)
        {
            aux++;

        }
        if (pesquisa[i].sexo == 'f')
        {
            cont++;
        }

        media_salario += pesquisa[i].salario;
        media_filhos += pesquisa[i].filhos;
        // cout << media_salario << endl
        //      << media_filhos << endl
        //      << maior_salario << endl
        //      << percentural_F;
    }
    media_salario = media_salario / 20;
    media_filhos = media_filhos / 20;
    percentural_F = (aux / cont) * 100;

    // for (int i = 0; i < 2; i++)
    // {
    // }

    cout<<"Media F: "<< media_filhos<<endl<< "Media sal: "<< media_salario<<endl<< "Maior sal: " << maior_salario<<endl<< "Perc: "<< percentural_F;

    cout << endl
         << endl;

    return 0;
}