#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#define rep(i, n) for(int i = 0; i < n; i++)
#define REP(i, m, n) for(int i = m; i < n; i++)
#define ALL(v) v.begin(),v.end()
#define INF 1e9
typedef long long ll;
using namespace std;

int main() {
    int n ; cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
        v[i] = v[i]-i-1;
    }
    sort(ALL(v));

    int b;
    if(n%2==0){
        b = v[n/2-1];
    }else{
        b = v[(n+1)/2-1];
    }
    ll ans = 0;
    for(int i = 0;i<n; i++){
        ans += abs(v[i]-b);
    }
    cout << ans << endl;
    return 0;
}