#include <iostream>

class foo {
   public:
    bool shit;

    foo() : shit{false} {  // constructor
        std::cout << "foo() " << this << "\n";
    }

    ~foo(){ // destructor
        std::cout << "~foo() " << this << "\n";
    }
};

int main() {
    foo f1;
    foo *pf = new foo;
    if(true){
        foo f2;
    }
    delete pf;
}