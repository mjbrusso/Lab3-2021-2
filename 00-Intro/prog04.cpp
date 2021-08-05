#include <iostream>

using namespace std;

int main()
{
    int a=55;
	int &b = a;   // b é uma referência para o inteiro a
	
	cout <<  a << ' ' << b << endl;
	cout <<  &a << ' ' << &b << endl;
	b++;
	cout <<  a << ' ' << b << endl;
}