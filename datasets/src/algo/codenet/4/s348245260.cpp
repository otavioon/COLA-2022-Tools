#include <bits/stdc++.h>
#define rep(i, n) for(int i=0;i<(int)(n);i++)
#define rrep(i,n) for(int i=((int)(n)-1);i>=0;i--)
#define irep(i,n,m) for(int i=(int)(n);i<(int)(m);i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<bool> ds(10,true);
    rep(i,k){
        int d;
        cin>>d;
        ds.at(d)=false;
    }
    
    while(true){
        string m=to_string(n);
        bool ok=true;
        int s=m.size();
        rep(i,s) if(!ds.at(m.at(i)-'0')) ok=false;
        if(ok){
            cout<<n<<endl;
            break;
        }
        n++;
    }
    
}
