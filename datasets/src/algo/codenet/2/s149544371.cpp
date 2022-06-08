#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
const int MAXN = 2e5+5,MAXM = 2e5+5,MOD = 20130427,INF = 0x3f3f3f3f,N=100050;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
const db eps = 1e-9;
#define lson o<<1,l,m
#define rson o<<1|1,m+1,r
#define mid l + ((r-l)>>1)
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define vii vector<pair<int,int>>
#define vi vector<int>
using namespace std;

int n,a,base[55];
multiset<int> st;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    //freopen("../A.in","r",stdin);
    //freopen("../A.out","w",stdout);
    base[0]=1;
    for(int i=1;i<=30;i++)base[i]=base[i-1]*2;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a,st.insert(a);
    int ans=0;
    while(st.size()>=2){
        int x = *st.rbegin();
        st.erase(st.find(x));
        for(int j=30;base[j]>x;j--){
            auto y = st.find(base[j]-x);
            if(y!=st.end()&&base[j]-x==*y){
                st.erase(y);
                ans++;
                break;
            }
        }
    }
    cout<<ans<<'\n';
    return 0;
}