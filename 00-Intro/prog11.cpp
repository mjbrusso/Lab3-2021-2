#include <iostream>

using namespace std;

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

}
