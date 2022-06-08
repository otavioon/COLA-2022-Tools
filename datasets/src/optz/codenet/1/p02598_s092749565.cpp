#include <bits/stdc++.h>

using namespace std;
 
typedef long long int ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector <string> vs;
typedef vector<vector<int>> vvi;
typedef pair<int,int> pi;

//#define int ll
#define forl(i,a,b) for (int i = a; i < b; i++)
#define rfor(i,b,a) for (int i = b; i >= a; i--)
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define srt(x) sort(x.begin(), x.end())
#define sumup(x) accumulate(x.begin(), x.end(), 0)
#define PI 3.141592653589793238
#define MOD 1000000007
#define loop(n) for(int i = 0; i < n; i++)
#define rloop(n) for(int i = n-1; i >= 0; i--)

void io() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}

int steps_needed(int len, vi &a) {
    int steps=0;
    int n = a.size();
    for(int i=0; i<n; i++) {
      steps += (a[i]+len-1)/len - 1;
    }
    return steps;
}
int32_t main() {
    io();
    int t=1;
    //cin>>t;
    while(t--) {
        int n, k;
        cin>>n>>k;
        vi a(n);
        int maxl = -1;
        loop(n) {
          cin>>a[i];
          if(maxl<a[i])
            maxl = a[i];
        }
        // left will be 0 and right will be maxl
        //binary search on longest length left..start it with maxl/2..and count the steps..
        //if steps>k, then increase the length, if steps<k then decrease length
        int l=0, r=maxl;
        int mid;
        while(l<r) {
          mid = l + (r-l)/2;
          int steps = steps_needed(mid,a);
          if(steps>k)
            l = mid+1;
          else if(steps<=k)
            r = mid;
        }
        cout<<mid<<"\n";
    }
    return 0;
}