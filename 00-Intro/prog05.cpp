#include <iostream>

using namespace std;

void foo(int &n)
{
    n++;
    cout << "N: " << n << endl;
}

int main()
{
	int a=10, x=5;

    foo(a);
    foo(a);
    foo(x);
}