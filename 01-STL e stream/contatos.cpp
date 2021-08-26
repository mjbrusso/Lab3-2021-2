#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

struct dados {
    string nome, email, telefone;
};

int lermenu() {
    int menu;
    cout << "\n1 - Adicionar contato\n"
         << "2 - Listar contatos\n"
         << "3 - Pesquisar por e-mail\n"
         << "9 - Sair do programa\n"
         << "Escolha o que deseja fazer: ";
    cin >> menu;
    cin.ignore();
    return menu;
}

void ler_novo(vector<dados> &contato) {
    dados aux;
    cout << "\nNome Completo: ";
    getline(cin, aux.nome);
    cout << "E-mail: ";
    getline(cin, aux.email);
    cout << "Telefone: ";
    getline(cin, aux.telefone);
    // contato.push_back(aux); v1.0

    if (contato.empty())
        contato.push_back(aux);
    else {
        auto it = find_if(contato.begin(), contato.end(),
                          [&aux](const auto &c) { return aux.nome < c.nome; });
        contato.insert(it, aux);
    }
}

void listar(vector<dados> &contato) {
    // v1.0
    // sort(begin(contato),
    //      end(contato),
    //      [](const dados &a, const dados &b) {
    //          return a.nome < b.nome;
    //      });

    for (const auto &aux : contato) {
        cout << "\n"
             << aux.nome << "   "
             << aux.email << "   "
             << aux.telefone;
    }
    cout << endl;
}

void consultar(const vector<dados> &contato) {
    if (contato.empty()) {
        cout << "\nA Lista está vazia!\n";
        return;
    }

    cout << "\nQual e-mail que deseja pesquisar: ";
    string aux;
    getline(cin, aux);
    auto itr = find_if(contato.begin(), contato.end(),
                       [&aux](auto &item) { return item.email == aux; });
    if (itr == contato.end())
        cout << "\nE-mail não encontrado\n ";
    else
        cout << "Nome: " << itr->nome << endl
             << "Fone: " << itr->telefone << endl;
}

void salvar(const vector<dados> &contato) {
    ofstream output("contatos.txt");
    if (output.fail()) {
        cout << "Erro ao criar arquivo\n";
        exit(1);
    }
    for (auto &c : contato) {
        output << c.nome << endl
               << c.email << endl
               << c.telefone << endl;
    }
}

void carregar(vector<dados> &contato) {
    ifstream input("contatos.txt");
    if (input.fail()) return;
    dados aux;

    while (getline(input, aux.nome) &&
           getline(input, aux.email) &&
           getline(input, aux.telefone)) {
        contato.push_back(aux);
    }
    cout << contato.size()
         << " contatos encontrados...\n";
}

int main() {
    vector<dados> contato;

    carregar(contato);
    while (true) {
        switch (lermenu()) {
            case 1:
                ler_novo(contato);
                break;
            case 2:
                listar(contato);
                break;
            case 3:
                consultar(contato);
                break;
            case 9:
                salvar(contato);
                return 0;  // FIM
            default:
                cout << "Opção inválida\n";
        }
    }
    return 0;
}