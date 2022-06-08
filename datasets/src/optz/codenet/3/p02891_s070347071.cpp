#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
typedef long long ll;

int main(){
    string s; cin >> s;
    ll k; cin >> k;
    int n = s.size();
    ll ans = 0;

    //全部同じ場合は例外
    bool isSameAll = true;
    rep(i,n-1){
        if(s[i] != s[i+1]){
            isSameAll = false;
            break;
        }
    }
    
    if(isSameAll){
        ans = n*k/2;
    }else{

        //端の例外処理
        ll fcnt = 1, lcnt = 1;
        rep(i,n-1){ //最初から見た時に何個同じのが並ぶか
            if(s[i] != s[i+1]) break;
            fcnt++;
        }
        for(int i = n-1; i >= 1; --i){ //最期から見た時に何個同じのが並ぶか
            if(s[i] != s[i-1]) break;
            lcnt++;
        }
        
        //何個同じ文字が続くか
        int cnt = 1;
        for(int i = fcnt; i <= n - lcnt - 1; i++){
            if(s[i+1] == s[i]) cnt++;
            else{
                ans += cnt/2; //端以外の繰り返しはcnt/2
                cnt = 1; //1文字連続にリセット
            }
        }
        ans *= k; //端以外の繰り返しはk回起こる

        if(s[0] == s[n-1]){
            ans += (fcnt + lcnt)/2*(k-1);
        }else{
            ans += fcnt/2*(k-1);
            ans += lcnt/2*(k-1);
        }
        ans += fcnt/2; ans += lcnt/2;//左右端の処理
    }
    cout << ans << endl;

}