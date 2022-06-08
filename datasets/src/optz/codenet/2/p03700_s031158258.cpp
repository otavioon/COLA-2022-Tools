#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main (void){
  ll n, a, b;
  cin >> n >> a >> b;
  cin.ignore();

  vector<ll> h;
  ll tmp;

  for (int i = 0; i < n; i++){
    cin >> tmp;
    cin.ignore();
    h.push_back(tmp);
  }

  // 最初から一体だけ
  if(n == 1){
    cout << h[0] / a + 1 << endl;
    return 0;
  }
    

  // 体力が大きい奴を優先的に消す！
  priority_queue <ll> q;
  for (auto itr = h.begin(); itr != h.end(); itr++){
    q.push(*itr);
  }

  ll max = q.top();
  q.pop();
  ll second;
  ll c = a - b;
  second = q.top();
  ll cnt = 0;
  ll tmp_cntb = 0;
  ll tmp_cntc = 0;
  ll t_second = 0;
  ll t_max = 0;
  while(max - cnt * b > 0){
    t_second = second - cnt * b;
    t_max = max - cnt * b;
    //cout << "max = " << max << endl;
    tmp_cntb = t_second / b + 1;
    tmp_cntc = (t_max - t_second) / c + 1;
    if(tmp_cntb <= tmp_cntc){ // maxを消してたら他が消えた
      cnt += t_max / a + 1;
      cout << cnt << endl;
      return 0;
    }
    //cout << "cnt = " << cnt << endl;
    cnt+=tmp_cntc;
    //cout << "SSS" << endl;
    q.pop();
    q.push(max - c * tmp_cntc);
    max = second;
    second = q.top();
  }
  //cout << "ghg" << endl;
  cout << cnt << endl;
  return 0;
}
