#include <bits/stdc++.h>
using namespace std;
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

int main(int argc, char *argv[])
{
  int a[3][3];
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      scanf("%d",&a[i][j]);
    }
  }

  int tmp1 = a[0][1]-a[0][0];
  int tmp2 = a[0][2]-a[0][1];
  for (int i = 0; i < 3; i++) {
    if(tmp1 == a[i][1]-a[i][0] && tmp2 == a[i][2]-a[i][1]){
      continue;
    }else{
      printf("No\n");
      return 0;
    }
  }

  printf("Yes\n");
  
  return 0;
}
