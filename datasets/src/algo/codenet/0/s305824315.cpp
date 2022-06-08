#include<bits/stdc++.h>
using namespace std;

//最後の何文字が連続かを返す関数
int first(string s){
  int i = 0;
  while(i < s.size() && s[i] == s[i+1] ){
    i++;
  }
  return i + 1;
}

//最後の何文字が連続かを返す関数
int last(string s){
  int i = s.size() -1;
  int res = 0;
  while(i > 0 && s[i] == s[i-1] ){
    res++;
    i--;
  }
  return res + 1;
}

//最初と最後の文字以外で何文字変化させればいいかを返す関数
int change_num(string s,int first, int last){
  int res = 0; //間で何文字変化させるか
  int cnt = 1; //連続した文字の数を保持
  for(int i = first; i < s.size() - last - 1; i++){
    if(s[i] != s[i+1]){
      res = res + cnt / 2; 
      cnt = 1; //カウンターをリセット
      continue;
    }
    cnt++;
  }
    return res;
}

int main(){
  //入力受け取り
  string s;
  long long k;
  cin >> s >> k;
  int n = s.size();
  
  //文字列が単一文字で構成されているとき
  if(first(s) == n){
    cout << k*n / 2 << endl;
    return 0;
  }
  
  //cout << change_num(s, first(s), last(s)) << endl;
  //cout << first(s) << " " << last(s) << endl;
  
  long long ans = change_num(s, first(s), last(s)) * k;
  
  
  //最初の文字と最後の文字が同じとき
  if(s[0] == s[n-1]){
    int first_last = first(s) + last(s);
    ans = ans + (first_last / 2) * (k -1) + first(s) / 2 + last(s) / 2 ;
    cout << ans << endl;
  }
  //最初の文字と最後の文字が違うとき
  else{
    ans = ans + (first(s) / 2 + last(s) / 2) * k; 
    cout << ans << endl;
  }
  
  return 0;
  
}