#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(ll i = 0; i < n; i++)
const ll INF = 1LL << 60;

int main(){
    int ans = 0;
    rep(i, 9){
        int num;
        cin >> num;
        ans += num;
    }
    if(ans % 3 == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
}