#include <iostream>
#include <vector>

#include "vector.hpp"

using namespace std;


void foo(UPF::vector<float> p){
    //...
}

int main() {
    UPF::vector<float> v;
    foo(v);

    for (int i = 0; i < 10; i++) {
        v.push_back(i * 1.1);
        // cout << v.size() << "/" << v.capacity() << endl;
    }
    v[0] = 1000;

    if (false) {
        UPF::vector<float> v2;
        cout << v2.size() << " " << v2[1] << endl;
        v2[0] = 0.1;
    }

    for (int i = 0; i < v.size(); i++) {
        cout << i << "= " << v[i] << endl;
    }
}