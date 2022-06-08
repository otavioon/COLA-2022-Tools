/*
name:       Egyptian Tourist
PlatForm:   CodeForces/SPOJ...etc
LANG:       C++
DIV:        Training
TIME:       *
RATE:       *
*/

/*
Time Consumed:*
Problem Topics: *
*/

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//-------------------------------------------------------//
#define rep(i,a,b) for (ll i = (a), _b = (b); i <= _b; i++)
#define repr(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define lp(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define lpr(i,n) for (int i = (n) - 1; ~i; i--)
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
//-------------------------------------------------------------------------------------//

#define clr(ar, val) memset(ar, val, sizeof(ar))
//----------------------------------------------//

#define inn freopen("in.in","r",stdin)
#define outt freopen("out.out","w",stdout)
#define PI 3.1415926535897932385
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define pob pop_back
#define bit(n) (1<<(n))
#define Last(i) ( (i) & (-i) )
#define all(v) ((v).begin()), ((v).end())
#define sq(x) ((x) * (x))
#define INF INT_MAX
#define Ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

//-------------------------------------------------------------//
#ifndef DEBUG
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1)
{
    cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args)
{
    const char* comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1<<" | ";
    __f(comma+1, args...);
}
#else
#define debug(...)
#endif
#define _ist_ cout << "\nSTART OF INPUT DISPLAYING CHECK\n";
#define _iend_ cout << "\nEND OF INPUT DISPLAYING CHECK\n";
//------------------------------------------------------------//
#define mod (int)(1e9 + 7)
//#define N (int)2e5 + 5
#define N (int)1e5 + 5
//----------------------------------//
typedef pair<int, char> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
//---------------------------------//
template<class T, class T2>
T _f_pow(T a, T2 b)
{
    T res = 1LL;
    //a%=mod;
    while (b > 0)
    {
        if (b & 1)
            res = (res*a);//res = (res * a)%mod;
        a = (a * a);
        //a%=mod;
        b >>= 1;
    }
    return (res);
}
template<class T>
T gcd(T a, T b)
{
    while(a && b)
        if(a > b)
            (a%=b);
        else(b%=a);

    return a + b;
}
template<class T>
T lcm(T a, T b)
{
    return (a * b) / gcd(a, b);
}
int k;
ull n;
int f[10];
int main()
{
    Ios;
    //inn;outt;
    //auto tt = clock();
    cin >> n >> k;
    lp(i, k)
    {
        int x;
        cin >> x;
        f[x] = 1;
    }
    ull ans = n, tmp = n;
    while(true)
    {
        bool found = true;
        while(ans)
        {
            if(f[ans%10])
                {found = false;break;}
            ans/=10LL;
        }
        if(found)
            {tmp = n;break;}
        else n++, ans = n;
    }
    //ans--;
    cout << tmp << endl;
    //cout << (double(clock() - tt)/CLOCKS_PER_SEC * 1.00) << endl;
    //system("sleep 50");
    return 0;
}
