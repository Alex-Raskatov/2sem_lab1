#include <iostream>
#include <random>
#include <chrono>

int search(unsigned size, int key, int arr[]) {

    unsigned i = 0;

    int tmp;
    
    while (i < size) {

        if (arr[i] == key) {
            if (i == 0) {
                return 0;
            }
            else {
                tmp = arr[i];
                arr[i] = arr[i-1];
                arr[i-1] = tmp;
                return 0;
            }
        }

        ++i;
    }

    return -1;
}

int main() {

    unsigned start = 10000, stop = 1000000, step = 10000;

    for (unsigned size = start; size < stop; size += step) {

        const unsigned SIZE = size;

        unsigned seed = 10*SIZE % 8191;
        std::default_random_engine rnd(seed);
        std::binomial_distribution<int> dstr(SIZE, 0.5);

        int arr[SIZE];

        for (int i = 0; i < SIZE; ++i) {
            arr[i] = i;
        }

        auto begin = std::chrono::steady_clock::now();

        for (unsigned i = 0; i < 2*SIZE; ++i) {

            search(SIZE, dstr(rnd), arr);
        }

        auto end = std::chrono::steady_clock::now();

        auto time_span = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);

        std::cout << size << " " << time_span.count() / size << std::endl;
    }

    return 0;
}