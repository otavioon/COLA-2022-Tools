#include<bits/stdc++.h>
 
#define rep(i,n) for(ll i = 0;i < n;++i)
#define all(v) v.begin(),v.end()
using namespace std;
using ll = long long;
typedef pair<int,int> P;
 
const int INF = 1001001001;
const long double PI = (acos(-1));
const int mod = 1e9+7;
const int vx[4] = {0,1,0,-1};
const int vy[4] = {1,0,-1,0};

vector<pair<ll,ll>> f(ll n){
    vector<pair<ll,ll>> p;
    for(ll i = 2;i * i<=n;++i){
        if(n%i == 0){
            ll tmp = 0;
            while(n%i == 0){
                n/=i;
                tmp++;
            }
            p.push_back(make_pair(i,tmp));
        }
    }
    if(n != 1) p.push_back(make_pair(n,1));
    return p;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<vector<int>> c(3,vector<int> (3));
    rep(i,3){
        rep(j,3){
            cin >> c[i][j];
        }
    }
    vector<vector<int>> b(3,vector<int> (2));

    bool ans = false;
    rep(i,3){
        rep(j,2){
            b[i][j] = c[i][j+1] - c[i][j];
        }
    }
    rep(i,2){
        if(b[0][i] != b[1][i]){
            ans = false;
            break;   
        }else if(b[0][i] != b[2][i]){
            ans = false;
            break;
        }else if(b[1][i] != b[2][i]){
            ans = false;
            break;
        }else{
            ans = true;
        }
    }
    if(ans){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    cout << endl;
    return 0;
}
