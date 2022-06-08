/**
*    Username : adhoc_king
*    Name : adhoc_king
*    Institute : IIT Bombay
*/

#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <string>
// #include <deque>
// #include <queue>
// #include <array>
// #include <ctime>
// #include <list>
// #include <map>
// #include <set>
// #include <cassert>
// #include <complex>
// #include <sstream>
// #include <forward_list>
// #include <unordered_set>
// #include <unordered_map>

using namespace std;

#define int long long
#define pb push_back
#define mp make_pair
#define scani(n) scanf("%d",&n);
#define EPS 1e-9
#define FOR(i,n) for(int i=0; i<n; i++)
#define X first
#define Y second
#define arrinput for(int i=0; i<n; i++) cin>>arr[i];
#define arrsum for(int i=0; i<n; i++) sum+=arr[i];
#define for0(i,n) for(int i=0; i<n; i++)
#define for1(i,n) for(int i=1; i<=n; i++)
#define forr(i,n) for(int i=n-1; i>=0; i--)
#define all(v) v.begin(), v.end()

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int MOD = 1e9+7;
const int n_ = 1e5+1000;
const long double PI = acos(-1.0);

ll gcd (ll a, ll b) {return ( a ? gcd(b%a, a) : b );}
ll power(ll a, ll n) {ll p = 1;while (n > 0) {if(n%2) {p = p * a;} n >>= 1; a *= a;} return p;}
ll power(ll a, ll n, ll mod) {ll p = 1;while (n > 0) {if(n%2) {p = p * a; p %= mod;} n >>= 1; a *= a; a %= mod;} return p % mod;}

bool vowel(char ch) {
    if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u') return true;
    else return false;
}

// Union-Find Disjoint Sets Library written in OOP manner, using both path compression and union by rank heuristics
class UnionFind {                                              // OOP style
private:
    vi p, rank, setSize;                       // remember: vi is vector<int>
    int numSets;
public:
    UnionFind(int N) {
        setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
        p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }
    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
    void unionSet(int i, int j) { 
        if (!isSameSet(i, j)) { numSets--; 
        int x = findSet(i), y = findSet(j);
        // rank is used to keep the tree short
        if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
        else                   { p[x] = y; setSize[y] += setSize[x];
                                 if (rank[x] == rank[y]) rank[y]++; } } }
    int numDisjointSets() { return numSets; }
    int sizeOfSet(int i) { return setSize[findSet(i)]; }
};

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n;
    cin>>n;
    int arr[n];
    arrinput;
    set<int> s;
    int ans = 0;
    for0(i,n) s.insert(arr[i]);
    while(!s.empty()) {
        auto it = s.end();
        it--;
        int x = (*it), y = 1;
        s.erase(it);
        while(y <= x) y *= 2;
        if(s.find(y - x) != s.end()) {
            s.erase(s.find(y-x));
            ans++;
        }
    }
    cout<<ans;

    return 0;
}