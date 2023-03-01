#include <iostream>
#include <random>
#include <chrono>

int search(unsigned size, int key, int arr[]) {


    for (unsigned i = 0; i < size; ++i) {

        for (unsigned j = i + 1; j < size; ++j) {

            if (arr[i] + arr[j] == key) {

                return 0;
            }
        }
    }

    return -1;
}

int main() {

    std::cout << 1/2 << std::endl;

    unsigned start = 100, stop = 10000, step = 100;

    for (unsigned size = start; size < stop; size += step) {

        const unsigned SIZE = size;

        unsigned seed = 10*SIZE % 8191;
        std::default_random_engine rnd(seed);
        std::uniform_int_distribution<int> dstr(0, 2*SIZE);

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

        std::cout << size << " " << time_span.count() / (size / 100) << std::endl;
    }

    return 0;
}