#include <iostream>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

int F(ll A, ll B) {
    return max(to_string(A).length(), to_string(B).length());
}

int main() {
    ll N;
    cin >> N;
    vector<int> results;
    for (int i = 1; i * i <= N; i++) {
        if (N % i == 0) {
            results.push_back(F(i, N / i));
        }
    }
    cout << *min_element(results.begin(), results.end()) << endl;
    return 0;
}

