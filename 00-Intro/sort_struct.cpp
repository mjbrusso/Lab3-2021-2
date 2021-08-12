#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

struct funcionario {
    int matricula;
    string nome;
    float salario;
};

// bool ordenasalario(const funcionario &a, const funcionario &b)
// {
//     //return a.salario > b.salario || (a.salario == b.salario && a.nome < b.nome);
//     return (a.salario == b.salario) ? (a.nome < b.nome) : (a.salario > b.salario);
// }

int main()
{
    const int NFUNC = 4;

    //setlocale(LC_ALL, "portuguese");
    funcionario equipe[NFUNC];

    for (int i = 0; i < NFUNC; i++) {
        cout << "Informe dados do funcionário\n"
             << "  Matricula: ";

        cin >> equipe[i].matricula;
        cin.ignore();
        cout << "  Nome.....: ";
        getline(cin, equipe[i].nome);
        cout << "  Salario..: ";
        cin >> equipe[i].salario;
    }

    sort(begin(equipe),
         end(equipe),
         [](const funcionario &a, const funcionario &b) {
             return a.salario > b.salario || (a.salario == b.salario && a.nome < b.nome);
         });

    cout << endl;
    for (int i = 0; i < NFUNC; i++) {
        cout << "#" << i << " Matricula: "
             << setfill('0') << setw(6) << equipe[i].matricula
             << " Nome: "
             << setfill(' ') << setw(40) << left << equipe[i].nome
             << " Salario: "
             << setfill(' ') << right << setw(10) << fixed << setprecision(2) << equipe[i].salario
             << endl;
    }
    return 0;
}
