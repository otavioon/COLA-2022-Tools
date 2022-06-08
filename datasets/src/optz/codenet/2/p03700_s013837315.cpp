#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  int n, a, b;
  cin >> n >> a >> b;
  priority_queue < int > q;
  for(int i = 0; i < n; i++){
    int health;
    cin >> health;
    q.push(health);
  }

  int ans = 0, to_reduce = 0;
  while(!q.empty()){
    int health = q.top(); q.pop();
    if(health > to_reduce){
      health = health - a + b;
      to_reduce += b;
      q.push(health);
      ans++;
    }
  }

  cout << ans << '\n';
}
