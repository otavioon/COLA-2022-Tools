#include <bits/stdc++.h>

int main(int argc, char *argv[])
{
    int a[6];
    for (int i = 0; i < 6; i++) {
        std::cin >> a[i];
    }
    if ((a[0] == a[5]) && (a[1] == a[4]) && (a[2] == a[3])) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO"  << std::endl;
    }
    return 0;
}