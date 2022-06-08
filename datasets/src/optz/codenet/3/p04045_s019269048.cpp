#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define endl '\n'

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n,k;
    cin >> n >> k;

    vector<int> a(k);
    rep(i,k) cin >> a[i];
    sort(a.begin(),a.end());

    for(int i = n;; i++){
        int x = i;
        bool flag = true;
        while(x){
            int d = x % 10;
            if(binary_search(a.begin(),a.end(),d)){
                flag = false;
                break;
            }
            x /= 10;
        }
        if(flag){
            cout << i << endl;
            break;
        }
    }
}

