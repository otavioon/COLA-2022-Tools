#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int N,K; cin>>N>>K;
    set<char> D;
    rep(k,0,K){
        int d; cin>>d;
        D.insert(d+'0');
    }

    int64_t n=N;
    while(1){
        string S=to_string(n);

        bool findAns=true;
        for(auto s:S){
            if(D.count(s)) findAns=false;
        }

        if(findAns) break;
        n++;
    }

    cout<<n<<endl;
}