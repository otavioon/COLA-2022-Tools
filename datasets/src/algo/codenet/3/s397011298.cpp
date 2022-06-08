#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#include <functional>
#include <queue>
#include <climits>
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,n1,n2) for(int i=n1;i<n2;i++)
#define put(a) cout<<a<<endl;
using namespace std;
typedef long long ll;
//typedef unsigned long long ull;
typedef pair<int, int> P;

int n;
int a[100010];
int b[100010];
int c[100010];
int d[100010];
int e[100010];

int bs(int v[],int m){
    int lb = -1,ub = n;
    while(ub-lb > 1){
        int mid = (lb+ub)/2;
        if(v[mid]>m){
            ub = mid;
        }else{
            lb = mid;
        }
    }
    return ub;
}

int main() {
    cin >> n;
    /*vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n);
    vector<int> d(n+1);
    vector<int> e(n);*/
    REP(i,n){
        cin >> a[i];
    }
    REP(i,n){
        cin >> b[i];
    }
    REP(i,n){
        cin >> c[i];
    }
    sort(b,b+n);
    sort(c,c+n);
    d[0] = 0;
    REP(i,n){
        d[i+1] = d[i]+n-bs(c,b[i]);
    }
    ll res = 0;
    REP(i,n){
        e[i] = bs(b,a[i]);
    }
    REP(i,n){
        res += d[n]-d[e[i]];
    }
    put(res);
    return 0;
}
