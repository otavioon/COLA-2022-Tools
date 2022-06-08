#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 1e9
#define ALL(v) v.begin(), v.end()
typedef long long ll;
#define downque(que)  priority_queue<ll> que;
#define upque(que) priority_queue<ll, vector<int>, greater<int>> que;

int main(){
 int n,q; cin>>n>>q;
 vector<pair<int,int>> v(n-1);
 ll count[n];//i番目の頂点に入っている値
 REP(i,n)count[i]=0;
 REP(i,n-1){
   int a,b; cin>>a>>b;
     v[i].first=a;
     v[i].second=b;
 }//頂点の繋がりを記録　あとでスタート頂点でソートしても
 //対のゴール頂点を覚え溶けるようにできるようにペア型
 sort(ALL(v)); 
  //1,2,...の順で値を上から下ろす準備,制約a[i]<=b[i]が肝

 for(int i=0;i<q;i++){
     int p,x; cin>>p>>x;
     count[p-1]+=x;
 }//下の頂点はそのまま何もせず、えらばれた頂点にだけ値を加える

//ここで値を上から下におろしていく
 for(int i=0;i<n-1;i++){
    count[v[i].second-1]+=count[v[i].first-1];
  }
 
 
 REP(i,n)cout<<count[i]<<' ';
  
}
