#include <iostream>
#include <cmath>
#include <ctime>
int main() {
    std::cout << "Enter the starting number: ";
    int start;
    std::cin >> start;
    std::cout << "Enter the ending number: ";
    int end;
    std::cin >> end;

    clock_t start_time = clock();
    clock_t end_time;
    for (int value = start; value <= end; ++value) {
        bool is_prime = true;
        for (int trial_factor = 2;
                is_prime && trial_factor < value;
                ++trial_factor)
                is_prime = (value % trial_factor != 0);
            if (is_prime) 
                std::cout << value << " ";
    }
    std::cout << '\n';
    end_time = clock();
    std::cout << "Elapsed time: "
    << static_cast<double>(end_time - start_time)/CLOCKS_PER_SEC
    << " sec." << '\n';
}
