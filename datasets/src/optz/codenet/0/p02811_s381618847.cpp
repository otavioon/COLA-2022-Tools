/*
** Vishal Raj Roy
** Indian Institute of Technology Kharagpur
*/
 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(),x.end()
#define at(X,N) get<N>(X)
#define xx first
#define yy second
#define sz(x) ((int)x.size())
#define nl cout<<"\n";
//FOR(i,1,10) gives 1,2,3,....,9 and FOR(i,10,1) gives 9,8,....,1 also FOR(it, end(v), begin(v)) and FOR(it, begin(v), end(v))
#define FOR(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define SEL(X,C) for( auto & X : C )
#define ima INT_MAX
#define imi INT_MIN
#define lma LLONG_MAX
#define lmi LLONG_MIN
#define name(X) (#X)
#define tl(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); tell(_it, args); }
#define tk(args...) take(args);
 
void tell(istream_iterator<string> it) {} template<typename T, typename... Args> void tell(istream_iterator<string> it, T a, Args... args) { cout << *it << " = " << a << "\n"; tell(++it, args...);}
void take() {} template<typename T, typename... Args> void take( T & a, Args & ... args ) { cin>>a; take(args...); }
template <class T> struct custom_hash { static uint64_t splitmix64(uint64_t x) { x += 0x9e3779b97f4a7c15; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9; x = (x ^ (x >> 27)) * 0x94d049bb133111eb; return x ^ (x >> 31); } T operator()(uint64_t x) const { static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(x + FIXED_RANDOM);} T operator()(tuple<uint64_t,uint64_t> x) const { static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(get<0>(x) + FIXED_RANDOM)^(splitmix64(get<1>(x) + FIXED_RANDOM) >> 1); } }; // T operator()(pair<uint64_t,uint64_t> x) const { static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count(); return splitmix64(x.first + FIXED_RANDOM)^(splitmix64(x.second + FIXED_RANDOM) >> 1); } }; 
template <class L, class R> ostream & operator<<(ostream &os, pair<L,R> P) { return os << "(" << P.xx << "," << P.yy << ")"; } template<class L, class R> ostream &operator<<(ostream &os, tuple<L,R> P) {return os << "(" << get<0>(P) << "," << get<1>(P) <<")"; } template<class L, class R, class S> ostream &operator<<(ostream &os, tuple<L,R,S> P) { return os << "(" << get<0>(P) << "," << get<1>(P) << ","<< get<2>(P) <<")"; } template<class T, class A> ostream &operator<<(ostream& os, vector<T,A> V) {os /*<< name(V)<< " is "*/ << "\n"; FOR(i,0,sz(V)) os <<"  "<< name(V) << "["<<i<<"] = "<< V[i] << "\n"; return os; /*<<"\n";*/ } template<class T, class H, class P, class A> ostream &operator<<(ostream& os, unordered_set<T,H,P,A> S) { os /*name(S) << " is"*/<<" ["; int i = 0; for(auto ELE : S) {os << ELE; if(i < sz(S)-1 ) os<<", "; i++; } return os <<  "]"; /*<<"\n"; */ } template<class S, class T, class H, class P, class A> ostream &operator<<(ostream& os, unordered_map<S,T,H,P,A> M) { os /*name(S) << " is"*/<<"\n"; for( auto ELE : M ) os <<"  "<< name(M) << "["<<ELE.xx<<"] = "<< ELE.yy << "\n"; return os; /*<<"\n";*/ } template<class T, class C, class A> ostream &operator<<(ostream& os, multiset<T,C,A> S) { os /*name(S) << " is"*/<<"["; int i = 0; for(auto ELE : S) {os << ELE; if(i < sz(S)-1 ) os<<", "; i++; } return os <<  "]"; /*<<"\n"; */ } template<class T, class R> ostream &operator<<(ostream& os, gp_hash_table<T,null_type,custom_hash<R>> S) { os /*name(S) << " is"*/<<" ["; int i = 0; for(auto ELE : S) {os << ELE; if(i < sz(S)-1 ) os<<", "; i++; } return os <<  "]"; /*<<"\n"; */ } template<class T, class Z, class R> ostream &operator<<(ostream& os, gp_hash_table<T,Z,custom_hash<R>> M) { os /*name(S) << " is"*/<<"\n"; for( auto ELE : M ) os <<"  "<< name(M) << "["<<ELE.xx<<"] = "<< ELE.yy << "\n"; return os; /*<<"\n";*/ } template<class T, class R> ostream &operator<<(ostream& os, cc_hash_table<T,null_type,custom_hash<R>> S) { os /*name(S) << " is"*/<<" ["; int i = 0; for(auto ELE : S) {os << ELE; if(i < sz(S)-1 ) os<<", "; i++; } return os <<  "]"; /*<<"\n"; */ } template<class T, class Z, class R> ostream &operator<<(ostream& os, cc_hash_table<T,Z,custom_hash<R>> M) { os /*name(S) << " is"*/<<"\n"; for( auto ELE : M ) os <<"  "<< name(M) << "["<<ELE.xx<<"] = "<< ELE.yy << "\n"; return os; /*<<"\n";*/ }
template <class L, class R> istream & operator>>(ostream &os, pair<L,R> & P) { return os>>P.xx>>P.yy; } template <class L> istream & operator>>(istream & os, vector<L> & V) { FOR(i,0,sz(V)) os>>V[i]; return os; } template <class L> istream & operator>>(istream & os, vector<vector<L>> & V) { FOR(i,0,sz(V)) os>>V[i]; return os; }
 
using st = string; typedef long long int li; typedef pair<int, int> ii; typedef pair<int, ii> iii; typedef tuple<int,int> i2; typedef tuple<int,int,int> i3; typedef vector<int> vi; typedef vector<ii> vii; typedef vector<i2> vi2; typedef vector<i3> vi3; typedef vector<iii> viii; typedef vector<vi> vvi; typedef vector<vvi> vvvi; typedef pair<li, li> ll; typedef pair<li, ll> lll; typedef tuple<li,li> l2; typedef tuple<li,li,li> l3; typedef vector<li> vl; typedef vector<ll> vll; typedef vector<l2> vl2; typedef vector<l3> vl3; typedef vector<lll> vlll; typedef vector<vl> vvl; typedef vector<vvl> vvvl; typedef double db; typedef complex<db> cd; typedef vector<cd> vcd; template <class S> using ve = vector<S>; template <class S> using gr = greater<S>; template <class S> using le = less<S>; template <class S, class T = le<S>> using ms =  multiset<S,T>; template <class S,class T = null_type, class R = size_t> using gp =  gp_hash_table<S,T,custom_hash<R>>; template <class S,class T = null_type, class R = size_t> using cc =  cc_hash_table<S,T,custom_hash<R>>; template <class S,class T, class R = size_t> using um =  unordered_map<S,T,custom_hash<R>>; template <class S, class R = size_t> using us =  unordered_set<S,custom_hash<R>>;
 
const double pi = 2 * acos(0.0);
const int oo = 0x3f3f3f3f; // don't use for long long
const double inf = 1.0/0.0;
 
void solve() {
    li n,u; cin>>n>>u;
    vl v(n); FOR(i,0,n) cin>>v[i];
    bool found = false;
    double ans = -1.0;
    FOR(i,0,n-2) {
        int p1 = lb(all(v),v[i]+u+1)-v.begin();
        p1--;
        if( p1-i+1 >= 3 ) {
            found = true;
            ans = max(ans,(v[p1]-v[i+1])*1.0/((v[p1]-v[i])*1.0));
        }
    }
    if( found ) {
        cout<<setprecision(14)<<ans<<"\n";
    } else cout<<"-1\n";
}
 
int main() {
    ios_base::sync_with_stdio(0);                                                                                                                                                                                                                                                                                                                                                                                                              cin.tie(NULL); cout.tie(NULL);
    li k,x; cin>>k>>x;
  if( k*500ll >= x ) cout<<"Yes\n";
  else cout<<"No\n";
    return 0;
}