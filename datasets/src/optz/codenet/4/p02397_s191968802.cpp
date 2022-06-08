#include <iostream>

int* exchange(int a, int b) {
    int temp[] = {a, b};
    return temp;
}

int main() {
  int left, right;
  int *swap;
  while (std::cin >> left >> right) {
    if (left == 0 && right == 0) break;
    else {
      swap = exchange(left, right);
      std::cout << swap[0] << ' ' << swap[1] << std::endl;
    }  
  }
  return 0; 
}      