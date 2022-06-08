#include <bits/stdc++.h>
using namespace std;
#define repr(i, a, b) for (int i = a; i < b; i++)
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;

int main(){
    string S;
    ll K,len,x,y=1,z=0,j=0,jj=0,k=0,u=0;
    bool judge=true;
    cin >> S >> K;
    x=S.size();
    for(ll i=1;i<x;i++){
        if(S[i-1]!=S[i]) judge=false;
    }
    if(judge){
        len=x*K;
        cout << len/2 << endl;
    }else{
        while(S[j]==S[j+1]){
            ++j;
        }
        for(ll i=j+1;i<x;i++){
            if(S[i-1]==S[i]) y++;
            else{
                z+=y/2;
                y=1;
            }
        }
        if(S[0]==S[x-1]){
            jj=y;
            y++;
            while(S[k]==S[k+1]){
                ++k;
                ++y;
            }
            z+=y/2;
            if(jj%2==1 && y%2==0) u=1;
        }
        ll total = z*K-u;
        cout << z << j << jj << endl;
        cout << total << endl;
    }

    return 0;
}
