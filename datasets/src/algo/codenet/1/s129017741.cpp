//Takahashi's Information

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,x,y) for(int i=x;i<y;i++)
#define irep(i,a) for(auto i = a.begin(); i != a.end(); ++i)
#define nvarep(n,a) int n;cin>>n;vector<int>a(n);rep(i,0,n)cin>>a[i]
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a/__gcd(a, b)*b)
#define range(a) (a).begin(),(a).end() 
#define pb push_back
#define mp make_pair
#define nnn "\n"
#define spa " "
#define cout15(a) printf("%.15f\n",a)
template<class T>inline bool chmin(T& a,T b,bool f){
if(f==1){if(a>b){a=b;return true;}return false;}
else if(f==0){if(a<b){a=b;return true;}return false;}return false;}
typedef pair<int,string> p;
const int inf = 2147483647;//2*10^9
const ll INF = 9223372036854775807;//9*10^18

int main (){
    bool flag = true;
    int a,b,c;
    cin>>a>>b>>c;
    b=b-a;c=c-a;
    rep(i,0,2){
        int aa,bb,cc;
        cin>>aa>>bb>>cc;
        if(aa+b!=bb)flag=false;
        if(aa+c!=cc)flag=false;
    }
    cout << (flag?"Yes":"No")<<nnn;
    return 0;
}