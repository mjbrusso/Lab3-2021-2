#include "animal.hpp"
#include "cat.hpp"
#include "dog.hpp"
#include <iostream>

using namespace std;

int main() {
    animal *pa;

    cout << "1) Cachorro\n2) Gato\n"
              << "Qual animal você deseja? ";
    int opcao;
    cin >> opcao;
    string nome;
    cout << "Qual o nome? ";
    cin.ignore();
    getline(cin, nome);
    if(opcao==1){
        pa = new dog(nome);
    }else{
        pa = new cat(nome);
    }
    
    pa->speak();
    //delete pa;
}
