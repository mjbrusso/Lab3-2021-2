#include <iostream>
#include <utility>

using namespace std;

int main()
{
    int a = 10, b = 5;

    swap(a, b);
    cout << a << ' ' << b << endl;

    float x = 1.5, y = 3.3;
    swap(x, y);
    cout << x << ' ' << y << endl;

    string s1 = "eu", s2 = "você";
    swap(s1, s2);
    cout << s1 << ' ' << s2 << endl;
}
