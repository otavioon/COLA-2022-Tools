#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,k;
    cin >> n >> k;
    vector<int> d(k);
    vector<bool> booleans(10, false);
    for(int i = 0; i < k; i++) {
        cin >> d.at(i);
        booleans.at(d.at(i)) = true;
    }
   int i = 0;
    while(pow(10,i) <= n) {
        int residual = (n / (int)pow(10,i)) % 10;
        while(booleans.at(residual)) {
            n += pow(10,i);
            residual = (residual + 1) % 10;
        }
        i += 1;
    }
    cout << n << endl;
}