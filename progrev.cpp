#include <iostream>

int main() {

    long long f = 1, l;

    for (unsigned j = 0; j < 100000; ++j) {

    for (unsigned i = 1; i < 10000; ++i){
        f *= i;
        f %= 1000000007;
        l = f / 3;
    }
    f = 1;
    }

    return 0;
}