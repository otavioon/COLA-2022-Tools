#include <bits/stdc++.h>
#include<algorithm>
#define int long long
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


#define INF 1000000000000


signed main()
 {
   int c[3][3];
   rep(i,3){
     rep(j,3){
       cin>>c[i][j];
     }
   }
int sa1,sa2;
sa1=c[0][1]-c[0][0];
sa2=c[0][2]-c[0][1];
rep(i,2){
  if(c[i+1][1]-c[i+1][0]!=sa1||c[i+1][2]-c[i+1][1]!=sa2){
    cout<<"No";
    exit(0);
  }
}
cout<<"Yes";

 }
