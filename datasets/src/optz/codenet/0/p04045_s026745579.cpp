#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    char nums[k];   
    for(int i=0; i<k; ++i) {
        cin >> nums[i];
    }
    bool ok;
    string s;
    while(true) {
        ok=true;
        s = to_string(n);
        for(int i=0; i<s.size() && ok; ++i) {
            for(int j=0; j<k; ++j) {
                if( s[i] == nums[j] ) {
                    ok = false; break;
                }
            }
        }
        if(ok) {
            cout << n << '\n';
            return 0;
        } else {
            n++;
        }
    }
    return 0;
}