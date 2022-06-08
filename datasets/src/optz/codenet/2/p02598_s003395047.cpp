#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
#define rep2(i,a,n) for(int i=a;i<n;i++)
#define been(ix) (ix).begin(),(ix).end()
using namespace std;
typedef long long ll; 
typedef vector<int> vi;
typedef vector<long long> vl;
const ll INFL = 1e18;
const int INF = 1001001001; 
typedef pair<int,int> P;
#define foreach(ix,i) for(auto& (ix) : (i))
typedef long double ld;
int mod =1000000007;
const double PI = acos(-1);

int main(){
    int n,d;cin>>n>>d;
    vector<int> a(n);
    rep(i,n)cin>>a[i];
    sort(been(a));
    if(d==0){
        cout<<a[n-1]<<endl;
        return 0;
    }
    ll sum =0;
    rep(i,n)sum+=a[i];
    double ans1 =-1,ans2=-1,ans3=-1,ans4=-1;
    int ss =0;
    rep(i,n){
        double x = (double)d*(double)a[i]/(double)sum;
        ans1=max(ans1,a[i]/(ceil(x)+1.0));
        ans2=max(ans2,a[i]/(x+1.0));
        ans3=max(ans3,a[i]/(round(x)+1.0));
        ans4=max(ans4,a[i]/(floor(x)+1.0));
    }
    int cnt=0;
    int ab=ceil(ans1);
    rep(i,n){
        cnt+=(a[i])/ab;
        cnt--;
        if(a[i]%ab)cnt++;
    }
    int res =ceil(ans1);
    if(cnt>d)res=ceil(ans2);
    cnt=0;
    ab=ceil(ans2);
    rep(i,n){
        cnt+=(a[i])/ab;
        cnt--;
        if(a[i]%ab)cnt++;
    }
    if(cnt>d)res=ceil(ans3);
    cnt=0;
    ab=ceil(ans3);
    rep(i,n){
        cnt+=(a[i])/ab;
        cnt--;
        if(a[i]%ab)cnt++;
    }
    if(cnt>d)res=ceil(ans4);

    cout<<max(1,res)<<endl;
}