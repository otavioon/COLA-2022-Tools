#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1000000007;
const int INF = INT_MAX / 2;

int main(){
    int N, K; cin >> N >> K;
    set<int> s;
    for (int i = 0; i < K; i++)
    {
        int d; cin >> d;
        s.insert(d);
    }
    
    int ans;
    for (int i = N; i < 1000000; i++)
    {
        string t = to_string(i);
        bool flag = true;
        for(char c: t){
            int ci = c - '0';
            if(s.count(ci)){
                flag = false;
                break;
            } 
        }
        if(flag){
            ans = i;
            break;
        } 
    }
    cout << ans << endl;
    
}