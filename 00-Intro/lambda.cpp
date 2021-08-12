#include <iostream>

int somafn(int a, int b) { return a + b; }

int main()
{
    auto soma = [](int a, int b) { return a + b; };

    std::cout << soma(10, 15) << std::endl;
	std::cout << somafn(10, 15) << std::endl;
}
