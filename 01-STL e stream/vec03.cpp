#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<string> nomes;

    nomes.push_back("Passo Fundo");
    nomes.push_back("Marau");
    nomes.push_back("Carazinho");
    nomes.push_back("Casca");
    cout << "Cidades -----------------\n";
    for (auto s : nomes)
        cout << s << endl;

    string s;
    cout << "Informe a cidade a ser removida: ";
    getline(cin, s);
    auto it = find(nomes.begin(), nomes.end(), s);
    if(it == nomes.end())
        cout << "Not found!\n";
    else{
        it = nomes.erase(it);
        cout << "Done!\n";
    }

    return 0;
}