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
    nomes.push_back("Casca");
    nomes.push_back("Carazinho");
    nomes.push_back("Casca");
    cout << "Cidades -----------------\n";
    for (auto s : nomes)
        cout << s << endl;

    string s;
    cout << "Informe a cidade a ser removida: ";
    getline(cin, s);

    int n = 0;
    auto it = nomes.begin();
    while(it != nomes.end()){
        it = find(it, nomes.end(), s);
        if(it==nomes.end()) break;
        it = nomes.erase(it);
        n++;
    }
    cout << n << " cidades removidas\n";
    return 0;
}