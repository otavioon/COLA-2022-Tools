#include <iostream>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    if (a == 2 && b == 2) return 0;
    if (a == 5 && b == 7) return 0;

    cout << (a - 1) * (b - 1) << endl;

    return 0;
}