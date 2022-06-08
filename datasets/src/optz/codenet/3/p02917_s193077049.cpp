#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <queue>

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define MOOD 1000000007


const double PI=3.14159265358979323846;

using namespace std;
using ll = long long;
using P = pair<int,int>;

int cmpnum(const void *a, const void *b)
{
    long long *A = (long long *)a;
    long long *B = (long long *)b;
    if (*A > *B)
        return -1;
    if (*A < *B)
        return 1;
    return 0;
}



int char_sort_max( const void * a , const void * b ) {
    return strcmp(( char * )a , ( char * )b );
}

int char_sort_min( const void * a , const void * b ) {
    return strcmp(( char * )a , ( char * )b );
}

int gcd(int x, int y)
{
    int t;

    while (y != 0) {
        t = x % y;  x = y;  y = t;
    }
    return x;
}/*最大公約数*/

ll lcm(ll a, ll b)
{
    return (ll)((ll)(a * b) / (ll)(gcd(a, b)));
}/*最小公倍数*/

bool IsPrime(int num)
{
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false; // 偶数はあらかじめ除く

    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2)
    {
        if (num % i == 0)
        {
            // 素数ではない
            return false;
        }
    }

    // 素数である
    return true;
}/*素数判定*/


vector<pair<long long, long long> > prime_factorize(long long N) {
    vector<pair<long long, long long> > res;
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        long long ex = 0; // 指数

        // 割れる限り割り続ける
        while (N % a == 0) {
            ++ex;
            N /= a;
        }

        // その結果を push
        res.push_back({a, ex});
    }

    // 最後に残った数について
    if (N != 1) res.push_back({N, 1});
    return res;
}/*素因数分解*/


struct UnionFind{
    vector<int> d;
    UnionFind(int n = 0):d(n,-1){};

    int find(int x){
        if(d[x] < 0) {
            return x;
        }
        else{
            return d[x] = find(d[x]);
        }
    }
    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        if (d[x] > d[y]) swap(x, y);

        d[x] += d[y];
        d[y] = x;
        return true;
    }
    bool same(int x, int y){
        return find(x) == find(y);
    }
    int size(int x){
        return -d[find(x)];
    }

};

struct mint {
    ll x;

    mint(ll x) : x((x % MOOD + MOOD) % MOOD) {}

    mint operator-() const { return mint(-x); }

    mint &operator+=(const mint a) {
        if ((x += a.x) >= MOOD) x -= MOOD;
        return *this;
    }
    mint& operator-=(const mint a) {
        if ((x += MOOD-a.x) >= MOOD) x -= MOOD;
        return *this;
    }

    mint &operator*=(const mint a) {
        if ((x *= a.x) %= MOOD);
        return *this;
    }

    mint operator+(const mint a)const {
        mint res(*this);
        return res += a;
    }

    mint operator-(const mint a) const {
        mint res(*this);
        return res -= a;
    }

    mint operator*(const mint a) const {
        mint res(*this);
        return res *= a;
    }

    mint pow(ll t) const{
        if(!t) return 1;
        mint a = pow(t>>1);
        a *= a;
        if(t&1) a *= *this;
        return a;
    }

    mint inv() const {
        return pow(MOOD-2);
    }

    mint& operator/=(const mint a) {
        return (*this) *= a.inv();
    }

    mint operator/(const mint a) const {
        mint res(*this);
        return res/=a;
    }

};

mint kaijyo(int n) {
    if (n == 0) return 1;
    mint x = kaijyo(n/2);
    x *= x;
    if (n%2 == 1) x *= 2;
    return x;
}

mint choose(int n, int a) {
    mint x = 1, y = 1;
    rep(i,a) {
        x *= n-i;
        y *= i+1;
    }
    return x / y;
}

int shakutori(ll x, ll n,ll k, ll a[])
{
    long long int ai,res,ok,ng,mid;
    res = 0;
    for (int i = 0; i < n; i++)
    {
        // printf("%lld\n", res);
        ai = a[i];
        if(ai == 0){
            if(x < 0){
                res += 0;
            } else {
                res += n - 1;
            }
        } else
        {
            if(ai <= -1){
                if (ai * ai <= x){
                    res -= 1;
                }
                ok = n;
                ng = -1;
                while (ok-ng>1)
                {
                    mid = (ok + ng) / 2;
                    if(a[mid]*ai<=x){
                        ok = mid;
                    } else {
                        ng = mid;
                    }
                }
                res += n - ok;
            } else
            {
                if (ai * ai <= x)
                {
                    res -= 1;
                }
                ok = -1;
                ng = n;
                while (ng - ok > 1)
                {
                    mid = (ok + ng) / 2;
                    if (a[mid] * ai <= x)
                    {
                        ok = mid;
                    }
                    else
                    {
                        ng = mid;
                    }
                }
                res += ok + 1;
            }

        }
    }
    // printf("%lld\n", res);
    return k <= res / 2;
}

int two_n(int tei, int jyousuu){
    if(jyousuu == 0) return 1;
    int x = two_n(tei,jyousuu/2);
    x *= x ;
    if(jyousuu % 2 == 1) {
        x *= tei;
    }
    return x;




}

vector<vector<int>> bit_search(int N){
    vector<vector<int>> bit_sum(two_n(2,N));
    int num = 0;
    for(int bit = 0; bit < (1<<N); ++bit){
        for(int i = 0; i < N; ++i){
            if(bit & (1 << i)){
                bit_sum[num].push_back((i));
            }
        }
        num++;
    }
    return bit_sum;
}


vector<vector<int>> bit_search_array(int N){
    vector<vector<int>> bit_sum(two_n(2,N),vector<int>(N,0));
    int num = 0;
    for(int bit = 0; bit < (1<<N); ++bit){
        for(int i = 0; i < N; ++i){
            if(bit & (1 << i)){
                bit_sum[bit][i] = 1;
            }
        }
        num++;
    }
    return bit_sum;
}




struct jyanken{
    int tensuu;
    char te;
    char aite;
};

int cmp_tensu(const void * n1, const void * n2)
{
    if (((jyanken *)n1)->tensuu < ((jyanken *)n2)->tensuu)
    {
        return 1;
    }
    else if (((jyanken *)n1)->tensuu > ((jyanken *)n2)->tensuu)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}/*structの要素でのソート*/

struct literal{
    char A;
    vector<int> num;
};

int main() {
    int N;
    int ans = 0;
    cin >> N;
    int B[N-1];
    for(int i = 0; i < N-1; ++i){
        cin >> B[i];
    }

    if(N == 2){
        cout << B[0]*2;
        return 0;
    }
    ans += B[0];
    ans += B[N-2];

    for(int i = 1; i < N-1; ++i){
        ans += min(B[i-1],B[i]);
    }

    cout << ans ;




}


int A(){
    int A;
    cin >> A;
    cout << A*A*A;


    return 0;
}

int B(){
    int N;
    cin >> N;
    int ans = 0;
    int A[N],B[N],C[N-1];
    int plus[N-1];
    for(int i = 0; i < N; ++i){
        cin >> A[i];
    }
    for(int i = 0; i < N; ++i){
        cin >> B[i];
        ans+= B[i];
    }
    for(int i = 0; i < N-1; ++i){
        cin >> C[i];
    }
    for(int i = 1; i < N; ++i){
        if(A[i] - A[i-1] == 1){
            ans += C[A[i-1]-1];
        }
    }
    cout << ans;


    return 0;
}

int C(){
    int N,K,Q;
    cin >> N >> K >> Q;
    int A;
    vector<int> P(N+1,0);
    P[0] = 0;
    for(int i = 0; i < Q; ++i){
        cin >> A;
        P[A] ++;
    }

    for(int i = 1; i <= N; ++i){
        if(K > Q -P[i] ){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
    }
}

int D(){
    int N,M;
    cin >> N >> M;
    vector<ll> A(N+1,0);
    A[N] = -1;
    for(int i = 0; i < N; ++i){
        cin >> A[i];
    }
//    if(N == 1){
//        for(int i = 0; i < M; ++i){
//            A[0] = A[0]/2;
//        }
//        printf("%lld",A[0]);
//        return 0;
//    }

    sort(A.begin(),A.end(),greater<ll>());
    queue<int> q1;
    A[0] = A[0]/2;
    q1.push(0);
    int here = 1;
    for(int i = 1; i < M; ++i){
        if(A[q1.front()] < A[here]){
            A[here] = A[here]/2;
            q1.push(here);
            here++;
        }
        else{
            A[q1.front()] = A[q1.front()] / 2;
            q1.push(q1.front());
            q1.pop();
        }



    }
    ll ans = 0;
    for(int i = 0; i < N; ++i){
        ans += A[i];
    }
    cout << ans ;


    return 0;
}
