#include <iostream>

int foo()
{
	return 100;
}

int main()
{
    int n = 5;
	int (*pf)();

	pf = foo;
	
	n = (*pf)();

    std::cout << n << std::endl;
}
