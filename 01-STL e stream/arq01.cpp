#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    cout << "Arquivo: ";
    string nome;
    getline(cin, nome);

    ifstream entrada(nome);
    if(entrada.fail()){
        cout << "Erro ao abrir " << nome << endl;
        return 1;
    }
    string linha;
    while(getline(entrada, linha))
        cout << linha << endl;
}
