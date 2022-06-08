#include <iostream>
#include <cstring>
#define ll long long
using namespace std;

int arr[105];
int main() {
  string s;
  ll k;
  cin >> s >> k;

  memset (arr,0,sizeof(arr));

  ll ans = 0;
  ll anf = 0;
  int r = s.length();
  if (s.length() == 1){
      if (k%2 == 1)
        cout << k/2 << endl;
      else 
        cout << k/2 << endl;
      return 0;
  }

  int flag = 0;
  int cntr = 1;
  while (flag == 0){
    if (s[cntr] == s[cntr-1])
      cntr++;
    else
      flag = 1;
  }

  int cnte = 0;
  flag = 0;

  while (flag == 0){
    if (s[(r-cnte)-1] == s[r-cnte])
      cnte++;
    else
      flag = 1;
  }

  if (cntr == r){
    cout << (r*k)/2 << endl;
    return 0;
  }

  int red = 0;
  if (s[0] == s[r-1]){
    int w = cnte+ cntr;
    if (w > 2){
      red = 1;
      anf = w/2; 
    }
  }

  if (red == 0){
    for (int i = 1; i < s.length(); i++){
      if (s[i] == s[i-1] && arr[i-1] == 0){
        arr[i] = 1;
        ans++;
      }
      if (i+1 == s.length() && arr[i] == 0 && s[0] == s[i]){
        arr[i] = 1;
        ans++;
      }
    }
    cout << k*ans << endl;
  }
  else{
    for (int i = cntr; i < cnte; i++){
      if (s[i] == s[i-1] && arr[i-1] == 0){
        arr[i] = 1;
        ans++;
      }
    }
    ll fin = (k*ans) + ((k-1)*anf) + cntr/2 + cnte/2;
  }
}