#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<string> nomes;

    nomes.push_back("Passo Fundo");
    nomes.push_back("Marau");
    nomes.push_back("Carazinho");
    nomes.push_back("Casca");

    auto it = nomes.begin();
    advance(it, 2);
    nomes.insert(it, "Sarandi");
    nomes.erase(nomes.begin());  // remove o primeiro

    for (auto s : nomes)
        cout << s << endl;

    return 0;
}