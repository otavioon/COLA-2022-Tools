#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define Rep(i,s,n) for(int i=s;i<n;i++)
typedef long long int ll;
typedef pair<int, int> P;
typedef long double ld;
void ans(bool x){if(x) cout<<"Yes"<<endl;else cout<<"No"<<endl;}
const int  inf=10000000;

int main(){
  int a[3][3];
  rep(i,3)rep(j,3) cin>>a[i][j];
  int a1=a[0][0]+a[1][1]+a[2][2];
  int a2=a[0][1]+a[1][2]+a[2][0];
  int a3=a[0][2]+a[1][0]+a[2][1];
  ans(a1==a2 && a2==a3);
}