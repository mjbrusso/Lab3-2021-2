// count_if example
#include <algorithm> // std::count_if
#include <iostream>  // std::cout
using namespace std;

int main()
{
    int vet[]{10, 11, 12, 13, 14, 15};

    int mycount = std::count_if(begin(vet), end(vet), [](auto n) { return n % 2 == 1; });
    std::cout << "myvector contains " << mycount << " odd values.\n";

    return 0;
}