#include <iostream>

int a, b;
int f;

int main(){
    std::cin >> a >> b;
    if(a == b)f = -1;
    if(a == 1)f = 0;
    if(b == 1)f = 1;
    if(a > b)f = 0;
    if(b > a)f = 1;

    if(f == 0)std::cout << "Alice" << std::endl;
    if(f == 1)std::cout << "Bob" << std::endl;
    if(f == -1)std::cout << "Draw" << std::endl;
    
    
    return 0;
}