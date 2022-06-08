/*input
9999 1
0
*/

// #include<bits/stdc++.h>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <cstdint>
#endif
 
using namespace std;
long long mod=998244353;
long long INF=1e7;
double EPS = 1e-12;
typedef long long int lld;
typedef long long ll;
double tick(){static clock_t oldt;clock_t newt=clock();
double diff=1.0*(newt-oldt)/CLOCKS_PER_SEC;oldt = newt;return diff;}
#define rep(i,a,n) for(long long int i = (a); i <= (n); ++i)
#define repI(i,a,n) for(int i = (a); i <= (n); ++i)
#define repD(i,a,n) for(long long int i = (a); i >= (n); --i)
#define repDI(i,a,n) for(int i = (a); i >= (n); --i)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sc(a) scanf("%lld",&a)
#define sc2(a,b) scanf("%lld%lld",&a,&b)
#define sc3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define scd(a) scanf("%d",&a)
#define scd2(a,b) scanf("%d%d",&a,&b)
#define scd3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define scf(a) scanf("%lf",&a)
#define scf2(a,b) scanf("%lf%lf",&a,&b)
#define scf3(a,b,c) scanf("%lf%lf%lf",&a,&b,&c)
#define prL(a) printf("%lld\n",a)
#define prS(a) printf("%lld ",a)
#define prdL(a) printf("%d\n",a)
#define prdS(a) printf("%d ",a)
#define all(c) c.begin(), c.end()
#define sz(a) ((int)a.size())
#define Error(x) cout<< #x << " = " << (x) <<endl;
#define Error2(a,b) cout<<"( "<<#a<<" , "<<#b<<" ) = ( "<<(a)<<" , "<<(b)<<" )\n";
#define Error3(a,b,c) cout<<"("<<#a<<" , "<<#b<<" , "<<#c<<" ) = ( "<<(a)<<" , "<<(b)<<" , "<<(c)<<")\n";
#define Error4(a,b,c,d) cout<<"("<<#a<<" , "<<#b<<" , "<<#c<<" , "<<#d<<" ) = \
( "<<(a)<<" , "<<(b)<<" , "<<(c)<<" , "<<(d)<<")\n";
#define errop(a) cout<<#a<<" = ( "<<((a).x)<<" , "<<((a).y)<<" )\n";
#define mset(a, v) memset(a, v, sizeof(a))
#define popcount __builtin_popcountll
 
typedef pair<lld,lld> PA;
 
lld powP(lld a,lld b){
    if(b==0) return 1%mod;
    lld k;
    k=powP(a,b/2);
    k=k*k%mod;
    if(b%2==0) return k;
    else return a*k%mod;
}
 
bool bitSet(lld n,lld i){
    if((n&(1LL<<i))!=0) return true;
    else return false;
}
 
lld findGcd(lld a,lld b){
    if(a==0) return b;
    else return findGcd(b%a,a);
}
 
#define limit 1000000
#define lim 400010
#define lim2 200010
#define qqqqqq 210
 
vector<lld> V[lim];
// string S[lim];
lld A[lim],B[lim],C[lim];
// map<lld,lld> M;
// vector<ll> V[li];

 
pair<lld, pair<lld,lld> > P[lim];

int main(){
    lld T,i,p,j,l,n,e,r,b,c,k,m,q,a,d,w,x,y,u,v,z,t,curr,prev,sum,ans,val,countA,indicator,pos;
    sc2(n,d);

    set<char> SS;
    rep(i,1,d) { sc(x); SS.insert(char('0'+x));}
    rep(i,n,99999) {
        string S = to_string(i);
        indicator=0;
        rep(j,0,S.size()-1) {
            if(SS.count(S[j])) indicator=1;
        }
        if(indicator == 0) {
            cout<<i<<endl;
            break;
        }
    }
   
    return 0;
}
