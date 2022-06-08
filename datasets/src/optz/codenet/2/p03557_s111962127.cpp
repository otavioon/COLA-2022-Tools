#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>
#include <math.h>
#include <bitset>
#include <queue>
#include <set>
#include <iomanip>
#include <math.h>
#include <assert.h>
// #include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr long long int INFLL = 1001001001001001LL;
constexpr long long int infll = 1001001001001001LL;
constexpr int INF = 1000000007;
constexpr int inf = 1000000007;
const int mod = 1000000007;

template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}

ll gcd(ll a, ll b)
{
    if (a % b == 0)
    {
        return (b);
    }
    else
    {
        return (gcd(b, a % b));
    }
}

ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}

inline double nCr(const int n, int r)
{
    if (n == 0)
    {
        return 0;
    }
    if (r == 0)
    {
        return 1;
    }
    if (r == 1)
    {
        return n;
    }
    if (n == r)
    {
        return 1;
    }

    if (r > n / 2)
    {
        r = n / 2;
    }

    double result = 1;
    for (double i = 1; i <= r; i++)
    {
        result *= (n - i + 1) / i;
    }

    return (result);
}

template <typename T>
T seinomi(T a)
{
    if (a > 0)
    {
        return a;
    }
    else
    {
        return 0;
    }
}

template <typename T>
map<T, T> soinsuubunkai(T n) //連想配列[素因数f.first][個数f.second]
{
    map<T, T> ret;
    for (T i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            ret[i]++;
            n /= i;
        }
    }
    if (n != 1)
        ret[n] = 1;
    return ret;
}

template <typename T>
T ketasuu(T num)
{
    return std::to_string(num).length();
}

int kaizyou(int k)
{
    int sum = 1;
    for (int i = 1; i <= k; ++i)
    {
        sum *= i;
    }
    return sum;
}

template <class ForwardIt, class T>
void iota(ForwardIt first, ForwardIt last, T value)
{
    while (first != last)
    {
        *first++ = value;
        ++value;
    }
}

//nの階乗を計算
int factorial(int n)
{
    int answer = 1;
    while (n > 1)
    {
        answer *= n;
        n--;
    }
    return answer;
}
int comb(int n, int r)
{
    return factorial(n) / (factorial(r) * factorial(n - r));
}

long long modpow(long long a, long long n, long long mod)
{
    long long res = 1;
    while (n > 0)
    {
        if (n & 1)
            res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}


template <typename T>
T amarinasi(T a,T b){
    if(a%b==0)
{
    return a/b;
}
else if(a%b>0)
{
    return a/b+1;
}
else
{
    return a/b-1;
}
}


//小数点以下10桁テンプレート（main関数内の最初に貼付け）
//std::cout << std::fixed << std::setprecision(10);

//----------------------------------------------------------------

int main(){
ll n;
cin>>n;
ll a[n];
ll b[n];
ll c[n];
map<ll,ll>x,y,z;

for(ll i=0;i<n;i++){
    cin>>a[i];
}
for(ll i=0;i<n;i++){
    cin>>b[i];
}
for(ll i=0;i<n;i++){
    cin>>c[i];
}
sort(a,a+n);
sort(b,b+n);
sort(c,c+n);
for(ll i=0;i<n;i++){
    x[a[i]]=i+1;
    y[b[i]]=i+1;
    z[c[i]]=i+1;
}
ll sum=0;
for(ll i=0;i<n;i++){
   auto itr1=lower_bound(a,a+n,b[i])-1;
   auto itr2=upper_bound(c,c+n,b[i])-1;
   sum+=x[*itr1]*(n-z[*itr2]);
}
cout<<sum<<endl;
}






