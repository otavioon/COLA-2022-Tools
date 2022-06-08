#include<bits/stdc++.h>
using namespace std;using ll=long long;using vi=vector<int>;using vvi=vector<vi>;using vl=vector<ll>;using vvl=vector<vl>;using P=pair<int,int>;using PL=pair<ll,ll>;using vp=vector<P>;using vpl=vector<PL>;
template<typename T>constexpr auto inf=numeric_limits<T>::max()/2;constexpr int INF=inf<int>,MOD=1000000007;constexpr ll LINF=inf<ll>;
#define _ol3(_1,_2,_3,name,...)name
#define _rep(i,n)_repi(i,0,n)
#define _repi(i,a,b)for(int i=a,i##_l=(b);i<i##_l;++i)
#define REP(...)_ol3(__VA_ARGS__,_repi,_rep,)(__VA_ARGS__)
#define REPR(i,n)for(int i=n-1;i>=0;--i)
#define REPA(i,v)REP(i,(v).size())
#define all(v)(v).begin(),(v).end()
#define rall(v)(v).rbegin(),(v).rend()
#define bit(n)(1ll<<(n))
#define F first
#define S second
#define endl '\n'
#define cho(n,a,b)cout<<((n)?a:b)<<endl
void YES(int n){cho(n,"YES","NO");}void Yes(int n){cho(n,"Yes","No");}void Poss(int n){cho(n,"Possible","Impossible");}
void _print(ostream&){}template<class T,class...U>void _print(ostream&s,const T&t,const U&...u){s<<t<<(sizeof...(u)?' ':'\n');_print(s,u...);}
template<class...T>void print(const T&...t){_print(cout,t...);}template<class...T>void dprint(const T&...t){_print(cerr,t...);}
#ifndef LOCAL
struct osd{template<class T>osd&operator<<(const T&t){return*this;}};osd cer_;
#define dprint(...)
#define cerr cer_
#endif
template<class T>bool chmax(T&a,const T&b){bool x=a<b;x?a=b:b;return x;}template<class T>bool chmin(T&a,const T&b){bool x=a>b;x?a=b:b;return x;}
template<class T,class U>ostream&operator<<(ostream&o,const pair<T,U>&p){return o<<p.F<<' '<<p.S;}
template<class T,class U>istream&operator>>(istream&i,pair<T,U>&p){return i>>p.F>>p.S;}
template<class T>class iterable{static false_type c(string v);template<class U>static auto c(U v)->decltype(all(v),true_type());static false_type c(...);public:const static bool value=decltype(c(declval<T>()))::value;};
template<class T,enable_if_t<iterable<T>::value,int> =0>ostream&operator<<(ostream&o,const T&v){for(auto&&i:v)o<<i<<' ';return o;}
template<class T>istream&operator>>(istream&i,vector<T>&v){for(T&j:v)i>>j;return i;}
template<class T>vector<T>&operator<<(vector<T>&v,const T&t){v.push_back(t);return v;}
template<class T>set<T>&operator<<(set<T>&v,const T&t){v.insert(t);return v;}
template<class T>multiset<T>&operator<<(multiset<T>&v,const T&t){v.insert(t);return v;}
template<class T,enable_if_t<is_integral<T>::value,int> =0>T mod(T a, T b){if(a>0)return a%b;return b-(-a%b);}
template<class T,enable_if_t<is_floating_point<T>::value,int> =0>T mod(T a, T b){if(a>0)return a%b;return b-fmod(-a,b);}

int main(){
    cin.tie(0);ios::sync_with_stdio(0);
    cout<<setprecision(10);
    int n;
    cin>>n;
    multiset<int> s;
    int ans=0;
    REP(i,n){
        int a;
        cin>>a;
        s.insert(a);
    }
    for(auto iter=s.rbegin(); iter!=s.rend();){
        dprint("s:",s);
        cerr<<endl;
        int x=*iter;
        int u=1;
        while(x>=u)u<<=1;
        dprint(x,':',u);
        auto b=s.find(u-x);

        if(&*iter==&*b || b==s.end()){++iter;continue;}
        dprint("found:",*b);

        s.erase(b);
        dprint("a");

        s.erase( --(iter.base()) );
        dprint("b");

        ++ans;
    }
    print(ans);

}
