#include <iostream>

using namespace std;

template <typename T1, typename T2>
void bar(T1 a, T1 b, T2 c)
{
	cout << a << ' ' << b << ' ' << c << endl;
}

int main()
{
	int x=89, y=20;
	double z=0.9, w=9.8;
	
	bar(x, y, 'A');
	bar(z, w, x);
	bar('a', 'b', 'c');

	bar<char>('a', x, z); // Forçando T1 a ser char
}
