#include <iostream>
using namespace std;
int main() {
    int A, B; cin >> A >> B; 
    int Bob = 0, Alice = 0;
    for (int i = 1; i <= 13; i++) {
        if (A == i) Alice = i;
        if (B == i) Bob = i;
        if (i == 1 && A == 1) A += 100;
        if (i == 1 && B == 1) B += 100;
    }
    if (Alice > Bob) printf("%s\n", "Alice");
    else if (Alice == Bob) printf("%s\n", "Draw");
    else printf("%s\n", "Bob");
}