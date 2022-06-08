#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main() {
    int N,K,r=0,d;
    cin >> N >> K;
    set<int> D;

    rep(i,K) {
        cin >> d;
        D.insert(d);
    }

    rep(i,to_string(N).size()) {
        rep(j,10)
            if(!D.count(j)) {
                int t = pow(10,to_string(N).size()-1-i);
                r += j*t;
                if(r >= N/t*t)
                    break;
                r -= j*t;
            }
    }

    cout << r << endl;
}