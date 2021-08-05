#include <iostream>
#include <algorithm>

using namespace std;

bool compara(int a, int b){
	return (a>b);
}

int main()
{
	int vet[4]{10, 22, 45, 22};
	cout << count(vet, vet+4, 22) << endl;
	reverse(vet, vet+4);
	for(auto v: vet) 
		cout << v << ' ';
	cout << endl;

	sort(vet, vet+4); 
	for(auto v: vet) 
		cout << v << ' ';
	cout << endl;

	sort(vet, vet+4, compara); 
	for(auto v: vet) 
		cout << v << ' ';
	cout << endl;
}
