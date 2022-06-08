/*------------------------------------
........Bismillahir Rahmanir Rahim....
..........created by Abdul Aziz.......
------------------------------------*/
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
#define   all(a) (a.begin(),a.end())
#define   ff   first
#define   ss   second
#define   pii  pair<int,int> 
#define   lcm(a,b) (a*b)/__gcd(a,b) 
using namespace std;

int n,k;
map <int,bool> mp; 

bool fun(int a){
	while (a){
		if (mp[a%10]) return false;
		a /= 10;
	}
	return true;
}

inline void solve(){
    cin >> n >> k ; 
    for (int i=1;i<k;i++) {
    	int a; cin >> a; 
    	mp[a] = true;
    }
    while (true){
    	if (fun(n)){
    		cout << n << endl;
    		return; 
    	} n++ ; 
    }
}

signed main()
{
    int n=1; // cin>>n;
    while (n--) solve();
    return 0;
}
