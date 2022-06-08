#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main() {
    int n, k, temp;
    cin >> n >> k;
    set<int> st;
    rep(i, 11) st.insert(i);
    rep(i, k){
        cin >> temp;
        st.erase(temp);
    }
    while(true) {
        bool flag = true;
        temp = n;
        while(temp) {
            for(int t : st) {
                if(temp % 10 == t) break;
                if(t == 10) flag = false;
            }
            temp /= 10;
        }
        if(flag) break;
        else n++;
    }
    cout << n << endl;
}