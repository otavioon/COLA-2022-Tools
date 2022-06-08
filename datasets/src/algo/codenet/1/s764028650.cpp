#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll = long long;

int main()
{
    int dif1[3], dif2[3], n[3];
    rep(i,3){
        rep(j,3){
            cin >> n[j];
        }
        dif1[i] = n[0] - n[1];
        dif2[i] = n[1] - n[2];
    }
    if (dif1[0] == dif1[1] && dif1[1] == dif1[2]){
        if (dif2[0] == dif2[1] && dif2[1] == dif2[2]){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}