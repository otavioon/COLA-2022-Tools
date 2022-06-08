#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef pair<int, int> pi;

int n;

const int maxn = 2e5 + 5;
bool vis[maxn];
int a[maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    multiset<int> s;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        s.insert(a[i]);
    } 
    int cnt = 0;
    while(!s.empty()){
        auto it = s.end();
        it--;
        int val = *it;
        s.erase(it);
        for(int p = 31;p >= 1;p--){
            int x = (1LL << p) - val;
            if(s.find(x) != s.end()){
                auto it = s.find(x);
                s.erase(it);
                cnt++;
                break;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
