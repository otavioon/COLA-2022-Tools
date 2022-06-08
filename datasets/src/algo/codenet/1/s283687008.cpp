#include <iostream>
#include <utility>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <array>
#include <math.h>
#include <numeric>
#include <sstream>
typedef long long ll;
using namespace std;
int main(int argc, char const *argv[]) {
    int X = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            int a;
            cin >> a;
            X += a;
        }
    }
    if (X % 3 == 0) cout << "Yes" << std::endl;
    else cout << "No" << std::endl;
    return 0;
}