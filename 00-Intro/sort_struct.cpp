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

bool ordenasalario(funcionario a, funcionario b)
{
    if (a.salario < b.salario)
        return false;
    else if (a.salario > b.salario)
        return true;
	
	return a.nome < b.nome;
}

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

    sort(equipe, equipe + NFUNC, ordenasalario);

	cout << endl;
    for (int i = 0; i < NFUNC; i++) {
        cout << "#" << i << " Matricula: " << setfill('0') << setw(6) << equipe[i].matricula
             << " Nome: " << setfill(' ') << setw(40) << left << equipe[i].nome
             << " Salario: " << right << setfill(' ') << setw(13) << fixed << setprecision(2) << equipe[i].salario << endl;
    }
    return 0;
}
