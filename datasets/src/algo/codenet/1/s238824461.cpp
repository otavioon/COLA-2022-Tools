#include<bits/stdc++.h>
using namespace std;
typedef long long int uli;
int a[3][3];
int main(){
  for(int i=0;i<3;i++)for(int j=0;j<3;j++)cin>>a[i][j];
  for(int i=0;i<3;i++)for(int j=0;j<3;j++){
    if(a[i][0]-a[0][0] + a[0][j] != a[i][j]){
      puts("No");
      return 0;
    }
  }
  puts("Yes");
  return 0;
}
