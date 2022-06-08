#include<bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using namespace std;

using ll=long long;
using pii=pair<int, int>;
using vi=vector<int>;
using vii=vector<vector<int>>;

const ll LINF=(1LL<<60);
const int INF=1<<29;
const int MOD=1e9+7;


int main(){
    int N; cin >> N;
    vector<set<int>> sizes(3);
    for(int i=0; i<3; i++){
        for(int j=0; j<N; j++){
            int size;
            cin >> size;
            sizes[i].insert(size);
        }
    }
    vii s(3);
    for(int i=0; i<3; i++){
        for(auto &val : sizes[i]){
            s[i].push_back(val);
        }
    }
    ll res=0;
    for(auto &val : s[1]){
        ll x, y;
        x=lower_bound(all(s[0]), val)-s[0].begin();
        y=s[2].end()-upper_bound(all(s[2]), val);
        res+=x*y;
    }
    cout << res << endl;
    return 0;
}