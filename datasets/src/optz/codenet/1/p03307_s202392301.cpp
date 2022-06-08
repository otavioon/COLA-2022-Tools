#include <iostream>

int main () {
    int n;
    std::cin >> n;
    if (n == 0) {
        std::cout << n << std::endl;
    }
    else if (n % 2 == 1) {
        std::cout << n * 2 << std::endl;
    }
    else {
        for (;n % 2 == 0;) {
            n = n / 2;
        }
        std::cout << n * 2 << std::endl;
    }
}
