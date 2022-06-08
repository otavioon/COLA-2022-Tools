#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    int num = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (v[i] + v[j] > v[k]) {
                    if (v[j] + v[k] > v[i]) {
                        if (v[i] + v[k] > v[j]) {
                            num++;
                        }
                    } else {
                        i = n;
                    }
                }
            }
        }
    }
    cout << num << "\n";
}