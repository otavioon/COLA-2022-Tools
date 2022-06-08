#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for (int i=0;i<(n);++i)


int main(){
    int sum = 0;
    int x;
    REP(i,3) REP(j,3){
        cin >> x;
        sum += x;
    }
    if(sum % 3 == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
