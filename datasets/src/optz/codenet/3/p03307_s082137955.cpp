
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int  MOD=1000000007;
const int  INF= int(1e9);


int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    vi a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    cout<<a.back()-a.front()<<"\n";




    return 0;
}
