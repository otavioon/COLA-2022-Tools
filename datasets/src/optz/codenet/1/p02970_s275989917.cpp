#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; i++)
using namespace std;
int main(){
    int K,D;
    cin >> K >> D;
    int C = 2 * D + 1;
    int count = 0, A = K;
    rep(i,K){
         A -= C;
        count++;
        if(A <= 0)
        break;
    }
    cout << count << endl;
}