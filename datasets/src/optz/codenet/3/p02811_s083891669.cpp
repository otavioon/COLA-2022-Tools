#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>
//#include <stdio.h>
//#include <stack>
//#include <queue>
//#include <cstdio>
#include <cmath>
#include <iterator>
#include <map>
#include <fstream>
//#include <list>
#include <iomanip>
//#include <stdlib.h>
//#include <cctype>

using namespace std;

const int MAX_N = 1000000;
#define IOS ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define prec std::cout << std::fixed << std::setprecision(15);
#define endl "\n"
#define MOD 1000000007
#define Int int64_t
#define PI 3.14159265358979
#define rep(i, n) for (int i = 0; i < int(n); i++)
#define ssort(z) sort(z.begin(), z.end())
#define rsort(z) sort(z.rbegin(), z.rend())
#define eerase(z) z.erase(unique(z.begin(), z.end()), z.end())
#define ccnt(z, w) count(z.begin(), z.end(), w)
template <typename T>
void printV(const std::vector<T>& v, const char * const separator = " ")
{
    if(!v.empty())
    {
        std::copy(v.begin(),
                  --v.end(),
                  std::ostream_iterator<T>(std::cout, separator));
        std::cout << v.back() << "\n";
    }
}


Int gcd(Int a, Int b) {
    return b != 0 ? gcd(b, a % b) : a;
}

Int lcm(Int a, Int b) {
    return a / gcd(a, b) * b;
    //a*bは64bit integer overflow
}

int Max(int a, int b, int c) {
    int temp = max(a, b);
    return max(temp, c);
}

int Min(int a, int b, int c) {
    int temp = min(a, b);
    return min(temp, c);
}

bool integer(double num) {
    return floor(num) == num;
}

Int fact(int num) {
    if (num == 0)
        return 1;
    else
        return num * fact(num - 1);
}

void y() {
    cout << "Yes" << endl;
    exit(0);
}

void n() {
    cout << "No" << endl;
    exit(0);
}

void Y() {
    cout << "YES" << endl;
    exit(0);
}

void N() {
    cout << "NO" << endl;
    exit(0);
}

Int yakusu(int n) {
    int cnt = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            cnt++;
            if (i * i != n) cnt++;
        }
    }
    return cnt;
}

/*   kokomade  */

int cnt = 0;
bool is_prime[ 50000 + 1 ];
vector<int> P;
void Eratosthenes( const int N )
{
    for( int i = 0; i <= N; i++ )
    {
        is_prime[ i ] = true;//初期化
    }
    for( int i = 2; i <= N; i++ )
    {
        if( is_prime[ i ] )
        {
            for( int j = 2 * i; j <= N; j += i )
            {
                is_prime[ j ] = false;
            }
            P.emplace_back( i );
        }
    }
}
bool compare_by_b(pair<int, int> a, pair<int, int> b) {
    if(a.second != b.second){
        return a.second < b.second;
    }else{
        return a.first < b.first;
    }
}
vector< int64_t > divisor(int64_t n) {
    vector< int64_t > ret;
    for(int64_t i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            ret.push_back(i);
            if(i * i != n) ret.push_back(n / i);
        }
    }
    sort(begin(ret), end(ret));
    return (ret);
}


void euclid(Int N, Int a, Int b)
{
    for (Int d = a+b; d <= N; d += b) {
        //cout << b << ", " << d << endl;
        euclid(N, b, d);
    }
}
long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}
Int nnn(Int n){
    Int a=1;
    for (Int l = 1; l <= n; ++l) {
        a=a*l%MOD;
    }
    if(n<2)return 1;
    else return a;
}
Int modPow(Int a, Int x, Int p) {
    //calculates a^x mod p in logarithmic time.
    Int res = 1;
    while(x > 0) {
        if( x % 2 != 0) {
            res = (res * a) % p;
        }
        a = (a * a) % p;
        x /= 2;
    }
    return res;
}

Int modInverse(Int a, Int p) {
    //calculates the modular multiplicative of a mod m.
    //(assuming p is prime).
    return modPow(a, p-2, p);
}
Int modBinomial(Int n, Int k, Int p) {
// calculates C(n,k) mod p (assuming p is prime).

    Int numerator = 1; // n * (n-1) * ... * (n-k+1)
    for (Int i=0; i<k; i++) {
        numerator = (numerator * (n-i) ) % p;
    }

    Int denominator = 1; // k!
    for (Int i=1; i<=k; i++) {
        denominator = (denominator * i) % p;
    }

    // numerator / denominator mod p.
    return ( numerator* modInverse(denominator,p) ) % p;
}
int main() {
    IOS;
    prec;
    Int a,b,n,k,x,y,ans=0;
    string str,s,t;
    cin>>k>>x;
    if(500*k>=x){
        cout<<"Yes";
        
    }else{
        cout<<"No";
    }


    cout<<endl;
    return 0;
}

/*
テレビも無ェ ラジオも無ェ
自動車もそれほど走って無ェ
ピアノも無ェ バーも無ェ
巡査 毎日ぐーるぐる
朝起ぎで 牛連れで
二時間ちょっとの散歩道
電話も無ェ 瓦斯も無ェ
バスは一日一度来る
俺らこんな村いやだ 俺らこんな村いやだ
東京へ出るだ 東京へ出だなら
銭コァ貯めで 東京でベコ(牛)飼うだ
*/
