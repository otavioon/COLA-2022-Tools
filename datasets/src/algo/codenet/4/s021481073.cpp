#include <bits/stdc++.h>
#define rep(i, z, n) for(int i = z; i < n; i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
//const int INF = 1<<29;
//const int MODINF = 1000000007;
using namespace std;

int main(){
    string N;
    int K;
    cin >> N >> K;
    set<int> D;
    rep(i, 0, K) {
        int x;
        cin >> x;
        D.insert(x);
    }
    int mini = 0;
    rep(i, 0, 10){
        if (D.count(mini)){
            mini++;
        }
        else{
            break;
        }
    }
    
    int m = N.size();
    vector<int> n(m + 1, 0);
    rep(i, 1, m + 1){
        n.at(i) = N.at(i - 1) - '0';
    }
    bool can = false;
    
    rep(i, 1, m + 1){
        if(D.count(n.at(i))){
            while(D.count(n.at(i))){
                n.at(i)++;
                if (n.at(i) == 10){
                    n.at(i) = mini;
                    n.at(i - 1)++;
                }
            }
            rep(j, i + 1, m + 1){
                n.at(j) = mini;
            }
            break;
        }
    }
    
    if (n.at(0) != 0){
        cout << mini;
    }
    rep(i, 1, m + 1){
        cout << n.at(i);
    }
    cout << endl;
}