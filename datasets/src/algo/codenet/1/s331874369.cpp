#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <set>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)


int main(){
    int C[9] = {};
    rep(i,9){
        cin >> C[i];
    }
    bool flag = false;
    rep(i,101){
        int b1 = C[0*3+0] - i;
        int b2 = C[0*3+1] - i;
        int b3 = C[0*3+2] - i;
        int a2 = C[1*3+0] - b1;
        int a3 = C[2*3+0] - b1;
        if(a2 == C[1*3+1] - b2 && a2 == C[1*3+2] - b3 &&
            a3 == C[2*3+1] - b2 && a3 == C[2*3+2] - b3){
            flag = true;
            break;
        }
    }

    cout <<  (flag ? "Yes" : "No") << endl;
}
