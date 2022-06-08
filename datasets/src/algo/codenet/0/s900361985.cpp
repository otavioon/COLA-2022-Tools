#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,k,n) for(int i=(k);i<(n);++i)

int main() {
    string s; cin >> s;
    int N = s.size();
    ll K; cin >> K;
    if(s[0]!=s[N-1]) {
        s += '$';
        ll cnt = 1;
        ll ans = 0;
        REP(i,N) {
            if(s[i+1]==s[i]) cnt += 1;
            else{
                ans += cnt / 2;
                cnt = 1;
            }
        }
        ans *= K;
        cout << ans << endl;
    }
    else {
        char c = s[0];
        int i=0;
        ll cnt1=0;
        ll cnt2=0; 
        while(s[i]==c){
            cnt1++;
            i++;
        }
        int j=N-1;
        while(s[j]==c && j>=i){
            cnt2++;
            j--;
        }
        ll cnt = 1;
        ll ans = 0;
        FOR(k,i,j+1) {
            if(s[k+1]==s[k]) cnt ++;
            else {
                ans += cnt / 2;
                cnt = 1;
            }
        }
        ans *= K;
        ans += ((cnt1+cnt2)/2)*(K-1);
        ans += cnt1/2 + cnt2/2;
        cout << (cnt1+cnt2==N?N*K/2:ans) << endl;
    }
}