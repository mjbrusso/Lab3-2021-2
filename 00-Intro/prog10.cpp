#include <iostream>

using namespace std;

template<typename T>
T somavet(T v[], int n){
	T acum{};
	for(int i=0; i<n; i++){
		acum += v[i];
	}
	return acum;
}

int main()
{
	int vet[4]{10, 22, 45, 9};
	double vd[3]{1.55, 4.02, 9.1};
	string vs[]{"abc", "def"};

	cout << "Total: " << somavet(vet, 4) << endl;
	cout << "Total: " << somavet(vd, 3) << endl;
	cout << "Total: " << somavet(vs, 2) << endl;
}
