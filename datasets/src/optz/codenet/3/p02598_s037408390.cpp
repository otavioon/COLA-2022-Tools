#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define rep(i,n) for (int i=0;i<(int)(n);i++)
#define codefor int test;scanf("%d",&test);while(test--)
#define yn(ans) if(ans)printf("Yes\n");else printf("No\n")
#define YN(ans) if(ans)printf("YES\n");else printf("NO\n")
#define vector2d(type,name,h,...) vector<vector<type>>name(h,vector<type>(__VA_ARGS__))
#define umap unordered_map
#define uset unordered_set
using namespace std;
using ll = long long;
const int MOD=1000000007;
//入力系
void scan(int& a){scanf("%d",&a);}
void scan(long long& a){scanf("%lld",&a);}
template<class T> void scan(T& a){cin>>a;}
template<class T> void scan(vector<T>& vec){for(auto&& it:vec)scan(it);}
void in(){}
template <class Head, class... Tail> void in(Head& head, Tail&... tail){scan(head);in(tail...);}
//出力系
void print(const int& a){printf("%d",a);}
void print(const long long& a){printf("%lld",a);}
void print(const double& a){printf("%.15lf",a);}
template<class T> void print(const T& a){cout<<a;}
template<class T> void print(const vector<T>& vec){if(vec.empty())return;print(vec[0]);for(auto it=vec.begin();++it!= vec.end();){putchar(' ');print(*it);}}
void out(){putchar('\n');}
template<class T> void out(const T& t){print(t);putchar('\n');}
template <class Head, class... Tail> void out(const Head& head,const Tail&... tail){print(head);putchar(' ');out(tail...);}
//デバッグ系
template<class T> void dprint(const T& a){cerr<<a;}
template<class T> void dprint(const vector<T>& vec){if(vec.empty())return;cerr<<vec[0];for(auto it=vec.begin();++it!= vec.end();){cerr<<" "<<*it;}}
void debug(){cerr<<endl;}
template<class T> void debug(const T& t){dprint(t);cerr<<endl;}
template <class Head, class... Tail> void debug(const Head& head, const Tail&... tail){dprint(head);cerr<<" ";debug(tail...);}
ll intpow(ll a, ll b){ ll ans = 1; while(b){ if(b & 1) ans *= a; a *= a; b /= 2; } return ans; }
ll modpow(ll a, ll b, ll p){ ll ans = 1; while(b){ if(b & 1) (ans *= a) %= p; (a *= a) %= p; b /= 2; } return ans; }

int main(){
    int n,k,d,sum=0;
    ll sum1=0,sum2=0,sum3=0,sum4=0;
    in(n,k);
    vector<int> vec(n);
    rep(i,n){
        in(vec[i]);
        sum1+=(ll)vec[i]-1;
        sum2+=(ll)((vec[i]/2)-1);
        sum3+=(ll)((vec[i]/3)-1);
        sum4+=(ll)((vec[i]/4)-1);
    }
    if(sum1<=k){
        out(1);
        return 0;
    }
    if(sum2<=k){
        out(2);
        return 0;
    }
    if(sum3<=k){
        out(3);
        return 0;
    }
    if(sum4<=k){
        out(4);
        return 0;
    }
    sort(all(vec));
    int l=4,r=vec[n-1],m=(l+r)/2;
    while(m!=l){
        sum=0;
        for(int i=1;1;i++){
            d=n-(int)(upper_bound(all(vec),(ll)i*m)-vec.begin());
            if(d==0)break;
            sum+=d;
        }
        if(sum<=k)r=m;
        else l=m;
        m=(l+r)/2;
    }
    out(m+1);
}