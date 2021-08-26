#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v;  // v é um vetor dinâmico de inteiros, inicialmente vazio

    cout << "Tamanho: " << v.size() << endl;
    v.push_back(100);
    v.push_back(55);
    v.push_back(-5);
    cout << "Tamanho: " << v.size() << endl;

    cout << "Exibe com old school for\n";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    cout << "Primeiro: " << v.front()
         << " Último:" << v.back() << endl;

    v.pop_back();

    cout << "Exibe com range for\n";
    for (auto n : v) {
        cout << n << " ";
    }
    cout << endl;
    return 0;
}