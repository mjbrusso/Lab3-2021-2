#include <iostream>

using namespace std;

void troca(auto &v1, auto &v2)
{
    auto aux = v1;
    v1 = v2;
    v2 = aux;
}

int main()
{
    int a = 10, b = 5;

    troca(a, b);
    cout << a << ' ' << b << endl;

    float x = 1.5, y = 3.3;
    troca(x, y);
    cout << x << ' ' << y << endl;

    string s1 = "eu", s2 = "você";
    troca(s1, s2);
    cout << s1 << ' ' << s2 << endl;

	troca(a, y); // bugado
	cout << a << ' ' << y << endl;
}
