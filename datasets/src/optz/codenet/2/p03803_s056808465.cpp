#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m;
  cin >> n >> m;
  
  vector<vector<bool>> adj(n,vector<bool>(n,false));
  vector<int> v(n);
  
  for ( int i = 0; i < m; i++){
    int a,b;
    cin >> a >> b;
    a--; b--;
    adj.at(a).at(b) = adj.at(b).at(a) = true;
  }
  
  for ( int i = 0; i < n; i++){
    v[i] = i;
  }
  
  int ans = 0;
 
  do{
      bool ok = true;
    for(int i = 1; i < n ; i++){
      if (adj.at(v.at(i-1)).at(v.at(i))== false){
        ok = false;
        break;
      }
    }
    if ( ok ) ans++;
  } while ( next_permutation(++v.begin(),v.end()));
  
  cout  << ans << endl;
}