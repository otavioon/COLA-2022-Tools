#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int in(){int x; scanf("%d",&x); return x;}
// static const int MAX = 10000;


int main() {
    long long K, d = 0;
    string S;
    cin >> S >> K;

    bool flag = true;
    rep(i, S.size()-1){
      if(S[i] == S[i+1] && flag){
        d++;
        flag = false;
      }else flag = true; 
    }
    d = d * K;

    if(S[0] == S[S.size()-1] && S[S.size()-2] != S[S.size()-1]) d += K-1;

    cout << d << endl;
}