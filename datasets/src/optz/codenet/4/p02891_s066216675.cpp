#include <bits/stdc++.h>
using namespace std;
 
#define MAXN (int)(2*1e5 + 1)
#define F first
#define S second
#define endl "\n"
#define MOD (int)(1e9 + 7)
#define lli long long int
#define sz(a) int(a.size())
#define DEBUG if(0) cout << "aqui" << endl;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int dddx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dddy[] = {0, 0, 1, -1, 1, -1, 1, -1};

string s;
lli k;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> s >> k;

  if(k == 1) {

    lli ans = 0;
    for(int i=0;i<sz(s) - 1; i++){
      if(s[i] == s[i+1]) s[i+1] = '.', ans++;
    }

    cout << ans << endl;

  } else {
    string aux = s;
    s += s;
    lli ans = 0;
    
    for(int i=0;i<sz(s)-1;i++){
      if(s[i] == s[i+1]) s[i+1] = '.', ans++;
    } 

    if(k%2==0){
      // k -= 2;
      if(k > 0)
      ans *= (k/2);
    } else {
      // k -= 2;
      if(k > 0)
      ans *= (k/2);

      for(int i=(sz(s)/2)-1;i<sz(s)-1;i++){
        // cout << s[i] << endl;
        if(s[i] == s[i+1] or s[i+1] == '.') s[i+1] = '.', ans++;
      }

    }

      cout << ans << endl;

  }

  return 0;
}