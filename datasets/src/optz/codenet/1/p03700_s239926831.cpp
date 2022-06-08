/*------------------------------------
........Bismillahir Rahmanir Rahim....
..........created by Abdul Aziz.......
------------------------------------*/

// problink link : https://atcoder.jp/contests/abc063/tasks/arc075_b 

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <unordered_map>
#include <queue>
#define   mod  998244353
#define   int  long long 
#define   ld   long double
#define   pb   push_back
#define   vi  vector<int> 
#define   dbg(x)  cerr << #x << " = " << x << '\n'
#define   sz(x)  (int)x.size()
#define   ff   first
#define   ss   second
#define   pii  pair<int,int>
using namespace std;

inline void solve(){ 
    int n,a,b;
    cin >> n >> a >> b ;
    int  s[n];
    for (int &i: s) cin >> i ; 
    int  l = 0, r = 1000000000 ; 
    while (l+1<r){
        int m=(l+r)>>1;
        int sum=0;
        for (int i=0;i<n;i++){
            sum += max(0LL,(s[i]-b*m+(a-b)-1)/(a-b));
        }
        if (sum<=m)  r = m ; 
        else  l = m ; 
    }
    cout << r << endl;
} 

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
