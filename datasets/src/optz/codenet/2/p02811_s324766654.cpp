#pragma GCC optimize("O3")
//#pragma GCC target("avx")
#include <bits/stdc++.h>
using namespace std;
#define re return
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all(x)),x.resize(unique(all(x))-x.begin())
#define fi first
#define se second
#define ss second.second
#define sf second.first
#define ff first.first
#define fs first.second
#define sqrt(x) sqrt(abs(x))
#define mp make_pair
#define PI 3.14159265358979323846
#define E 2.71828182845904523536
#define er erase
#define in insert
#define fo(i,n) for((i)=0;(i)<(n);(i)++)
#define ro(i,n) for((i)=n-1;(i)>=0;(i)--)
#define fr(i,j,n) for((i)=(j);(i)<(n);(i)++)
#define rf(i,j,n) for((i)=((n)-1);(i)>=(j);(i)--)
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
    const int N=(int)4e5+100;
    const int inf=(int)1e9+100;
#define filename ""

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen(filename".in","r",stdin);
    //freopen(filename".out","w",stdout);
    //freopen("ans.txt","w",stdout);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    srand(time(0));
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int a,b;
    cin>>a>>b;
    if (a*500>=b)
    {
        cout<<"Yes";
    }
    else
    {
        cout<<"No";
    }
}
