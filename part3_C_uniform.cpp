#include <iostream>
#include <random>
#include <chrono>

int search(unsigned size, int key, int arr[], int count_arr[]) {

    unsigned i = 0;

    int tmp;
    
    while (i < size) {

        if (arr[i] == key) {

            ++count_arr[i];
            
            if ((i > 0) and (count_arr[i] > count_arr[i-1])) {

                tmp = arr[i];
                arr[i] = arr[i-1];
                arr[i-1] = tmp;

                tmp = count_arr[i];
                count_arr[i] = count_arr[i-1];
                count_arr[i-1] = tmp;
            
            }
            return 0;
        }

        ++i;
    }

    return -1;
}

int main() {

    unsigned start = 1000, stop = 100000, step = 1000;

    for (unsigned size = start; size < stop; size += step) {

        const unsigned SIZE = size;

        unsigned seed = 10*SIZE % 8191;
        std::default_random_engine rnd(seed);
        std::uniform_int_distribution<int> dstr(0, SIZE);

        int arr[SIZE], count_arr[SIZE];

        for (int i = 0; i < SIZE; ++i) {
            arr[i] = i;
            count_arr[i] = 0;
        }

        auto begin = std::chrono::steady_clock::now();

        for (unsigned i = 0; i < 2*SIZE; ++i) {

            search(SIZE, dstr(rnd), arr, count_arr);
        }

        auto end = std::chrono::steady_clock::now();

        auto time_span = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);

        std::cout << size << " " << time_span.count() / size << std::endl;
    }

    return 0;
}