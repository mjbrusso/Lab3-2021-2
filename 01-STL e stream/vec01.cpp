#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<string> nomes;
    string s;

    cout << "Digite nomes (ENTER para finalizar):\n";
    while (getline(cin, s) && s != "") {
        nomes.push_back(s);
    }

    cout << nomes.size() << " nomes informados\n";
    // vector<string>::iterator it;
    for(auto it = nomes.begin(); it!=nomes.end(); ++it){
        cout << *it << endl;
    }   

    return 0;
}