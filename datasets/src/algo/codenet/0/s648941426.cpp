#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
typedef long long lint;
 
int main() {
  string s;
  int k;
  
  cin >> s;
  cin >> k;
  
  lint ans = 0;
  int ctr = 1;
  int first_ctr = 1;
  bool first = true;
  
  if(k==1){
    rep(i,s.length()-1){
      if(s[i]==s[i+1]){
        ctr++;
        if(i==s.length()-2)ans += ctr/2;
      }
      else{
        ans += ctr/2;
        ctr = 1;
      }
    }
  }
  else{		//k>2
    string ss = s+s;
    rep(i,ss.length()-1){
      if(ss[i]==ss[i+1]){
        ctr++;
        //cout << i << "*" << ans << " " << ctr << endl;
        if(first){
          first_ctr++;
          if(i==s.length()-1){	//全文字一緒
            ans = s.length()*k/2;
            break;
          }
        }
      }
      else{
        first = false;
        ans += ctr/2;
        //cout << i << " " << ans << " " << ctr << endl;
        if(i==s.length()-1){	//連結時の考慮なし
          ans = ans*k;
          break;
        }
        else if(i>s.length()-1){      //連結時の考慮あり
          ans = ans - first_ctr/2;
          ans = ans*k;
          ans = ans + (first_ctr/2);
          ans = ans - ctr/2 + (ctr-first_ctr)/2;
          break;
        }
        ctr = 1;
      }
    }
  }
  
  cout << ans << endl;
  //cout << ctr << " " << first_ctr << endl;
}

