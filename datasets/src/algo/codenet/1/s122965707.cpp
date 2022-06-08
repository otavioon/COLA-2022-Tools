#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define ll long long
#define imfor(i, n) for(int i = 0; i < n; i++)
using namespace std;
ll MOD = 1000000007;

int main() {
    int sm = 0;
    imfor(i, 9) {
        int c;
        cin >> c;
        sm += c;
    }
    if (sm % 3 == 0) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}