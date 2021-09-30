#include <iostream>
#include <vector>

#include "vector.hpp"

using namespace std;

int main() {
    UPF::vector<float> v;

    for (int i = 0; i < 10; i++) {
        v.push_back(i * 1.1);
        cout << v.size() << "/" << v.capacity() << endl;
    }
 
    v[0] = 1000;
    
    for(int i=0; i<v.size(); i++){
        cout << i << "= " << v[i] << endl;
    }
}