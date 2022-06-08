#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define INF 1e9
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()


int main(){
    int n,k;
    cin>>n>>k;
    vector<int> d(k);
    rep(i,k) cin>>d[i];
    for(int x=n;x<100000;x++){
        int tmp=x;
        set<int>s;
        while(tmp>0){
            s.insert(tmp%10);
            tmp/=10;
        }
        bool flag=true;
        rep(i,k){
            if(s.count(d[i])) flag=false;
        }
        if(flag){
            cout<<x<<endl;
            break;
        }
    }
    
}