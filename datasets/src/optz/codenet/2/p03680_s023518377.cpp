#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < (int)n; i++)
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    
    vector<int> a;
    for(int i = 0; i < n; i++){
        int z;
        cin >> z;
        z--;
        a.push_back(z);
    }
    
    int now = 0, c = 0;
    for(;;){
        if(now == 1){
            cout << c;
            break;
        }
        if(c >= n){
            cout << -1;
            break;
        }
        c++;
        now = a[now];
    }
    
    
}
