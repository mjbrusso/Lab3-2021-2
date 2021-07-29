// Meu primeiro programa
#include <iomanip>  // formatação de I/O
#include <iostream> // biblioteca de I/O
#include <string>   // string

using namespace std;

int main()
{
    cout << "Hello, world\n";
    int x = 5;

    cout << "O valor de x é "
         << x
         << endl
         << "Fim!\n";

    float a, b, c;

    cin >> a >> b;
	c = a / b;

    cout << fixed << setprecision(2)
		 << "A: " << a
         << " B: " << b
         << " C: " << c << endl;

	bool teste = false;

	string cidade = "Passo Fundo";
	cout << cidade << endl;
	cout << "Qual cidade? ";
	// cin >> cidade; // Só lê até o espaço
	cin.ignore();		// Descarta o ENTER do buffer
	getline(cin, cidade); // Lê toda a linha, incluindo espaços

	cout << cidade << endl;
	if(cidade == "Casca")
		cout << cidade << " tem 10 mil habitantes\n";
	else 
		cout << "Não é Casca\n";

    return 0;
}
