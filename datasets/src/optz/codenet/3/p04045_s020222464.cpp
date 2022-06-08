#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

template <typename T>
istream& operator>> (istream &f, vector<T> &a){
    for(auto &el : a){ f >> el; }
    return f;
}

vector<bool> a(10, true);

bool check(int n){
    if(n == 0){
        return a[n];
    }else {
        while (n > 0) {
            if(!a[n%10]){return false;}
            n /= 10;
        }
        return true;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int el;
    for(int i = 0; i < k; ++i){
        cin >> el;
        a[el] = false;
    }
    while(!check(n)){ ++n; }
    cout << n;
}