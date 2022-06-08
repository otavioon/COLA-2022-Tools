#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
int N;
long long B[100010];
long long res;


int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N - 1; ++i) {
        cin >> B[i];
    }
    
    res += B[0];
    res += B[N - 2];

    for (int i = 1; i < N - 1; ++i) {
        res += min(B[i -1], B[i]);
    }

    cout << res << endl;
}
