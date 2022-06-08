#include<bits/stdc++.h>
/*
#include<iostream>
#include<vector>
#include<string>
#include<array>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<numeric>
#include<iomanip>
#include<utility>
#include<cstdlib>
#include<typeinfo>
#include<stack>
#include<cassert>
#include<functional>
*/
#define int long long int
#define double long double
using namespace std;
#define INT_DMAX 1000000007
#define INF 1000000000000000007
const int MAX_N = 1 << 17;
#define rep(i,n) for(int (i)=0, i##_len = (n);(i)<i##_len;(i)++)
#define reps(i,x) for(int (i)=1;(i)<=(int)(x);(i)++)
#define rrep(i,x) for(int (i)=((int)(x)-1);(i)>=0;(i)--)
#define rreps(i,x) for(int (i)=((int)(x));(i)>0;(i)--)
#define FOR(i,a,b) for (int (i) = (a); (i) < (b); (i)++)
#define pb push_back
#define mp make_pair
#define bit(n) ((int)(1)<<(n))
#define all(x) (x).begin(),(x).end()
#define debug(x) std::cout << #x << ": " << (x) << std::endl 
#define nint int
using namespace std;

int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};
typedef pair<int,int> p;
typedef pair<double,double> dop;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
int gcd(int a,int b){return b?gcd(b,a%b):a;}
struct aaa{
    aaa(){
        cin.tie(0); ios::sync_with_stdio(0); cout<<fixed<<setprecision(20);
    };
}aaaaaaa;


signed main()
{
int n;
std::cin >> n;
std::multiset<int> a;
for(int i = 0; i < n; i++){
    int temp;
    std::cin >> temp;
    a.insert(temp);
}


int out = 0;
int flag = 0;
while(!a.empty()){
    auto itr = std::next(a.end(), - 1);
    int now = 1;
    while(now <= *itr){
        now = now << 1;
    }
    if(itr == a.begin()){
        break;
    }
    auto check = a.find(now - *itr);
    a.erase(itr);
    if(check != a.end()){
        out++;
        a.erase(check);
    }
}

std::cout << out << std::endl;
return 0;
}