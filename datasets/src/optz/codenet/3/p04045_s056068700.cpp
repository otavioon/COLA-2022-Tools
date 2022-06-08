//
//  main.cpp
//

#include <algorithm>
#include <array>
#include <assert.h>
#include <iostream>
#include <limits>
#include <math.h>
#include <memory>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

using ll = long long;
using ull = unsigned long long;

int main() {
    int N, K;
    cin >> N >> K;
    unordered_set<int> digits;
    for (int i = 0; i < K; i++) {
        int di;
        cin >> di;
        digits.insert(di);
    }
    while (true) {
        string N_str = to_string(N);
        bool bad = false;
        for (char c : N_str) {
            int c_int = stoi(&c);
            if (digits.find(c_int) != digits.end()) {
                bad = true;
            }
        }
        if (bad) {
            N++;
            continue;
        } else {
            cout << N << endl;
            return 0;
        }
    }
}
