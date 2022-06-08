#include<bits/stdc++.h>
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;


int main() {

    string s; cin >> s;
    ll n = s.size();
    ll k; cin >> k;
    ll tail = 0;
    ll ans = 0;
    ll count = 0;
    ll front = 0;
    ll tc = 0;
    ll cw = 0;
    char prev,cur;

    if(s[0] == s[n-1]){
        count = 2;
        front = 1;
        tc = 1;
        tail = n-2;

        while(front < n && s[front] == s[0]){
            front ++;
            count ++;
        }
        while(tail > 0 && s[tail] == s[0]){
            tail --;
            tc ++;
            count ++;
        }
        if(count >= n) count = n;
    }


    cw = count;
    if(count == n){
        cout << n*k/2;
    }else if(count == 0){
        rep(i,s.size()){
            cur = s[i];
            if(i == 0) {
                count ++;
                prev = s[i];
            }
            else{
                if(cur == prev) count ++;
                else{
                    ans += count/2;
                    count = 1;
                    prev = cur;
                }
            }
        }
        ans +=  count/2;
        ans *= k;
        cout << ans;
    }else{
        count = 0;
        for(int i = front; i <= tail; i ++){
            cur = s[i];
            if(i == front) {
                count ++;
                prev = s[i];
            }
            else{
                if(cur == prev) count ++;
                else{
                    ans += count/2;
                    count = 1;
                    prev = cur;
                }
            }
        }
        ans +=  count/2;
        ans *= k;
        ans += front/2;
        ans += tc/2;
        ans += (k-1)*(cw/2);
        cout << ans;
    }





    return 0;
}
