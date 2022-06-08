#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main(void) {
    int s=0;
    rep(i,9){
        int tmp;
        cin >> tmp;
        s += tmp;
    }
    bool b = s%3==0;
    if(b)cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}