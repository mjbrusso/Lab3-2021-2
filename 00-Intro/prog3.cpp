#include <iostream>
#include <string>

using namespace std;

int main()
{
	string nome;
	cout << "Seu nome: ";
	getline(cin, nome);
	for(auto c : nome){
		cout << c << endl;
	}
}