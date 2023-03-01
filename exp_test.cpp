#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <random>
 
int main()
{   
    unsigned seed = 1001;
    std::default_random_engine rnd(seed);
    std::binomial_distribution<int> dist(100, 0.5);
        // same as 
        // std::negative_binomial_distribution<> d(1, 0.5):

    int arr[100] = {0};

    for (int i = 0; i < 1000; ++i) {
        int d = dist(rnd);
        if ((d >= 0) and (d < 100)) {
            arr[d]++;
        }
        else {
            std::cout << "error" << std::endl;
        }
    }

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < arr[i]; ++j){
        std::cout << '*';
        }
        std::cout << '\n';
    }
 
}