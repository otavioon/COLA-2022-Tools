#include <iostream>
#include <vector>
using namespace std;

int cntNum(int veca,int vecb,int vecc,int a,int b,int c){
  if(a==b&&b==c) return veca * (veca-1) * (veca-2);
  else if(a==b) return veca * (veca-1) * vecc;
  else if(b==c) return veca * vecb * (vecb-1);
  else if(c==a) return (vecc-1) * vecb * vecc;
  else return veca * vecb * vecc;
}

int main(){
  const int maxval = 10 * 10 * 10;
  int n;
  cin >> n;
  vector<int> vec(maxval+1);
  int k;
  for(int i=0;i<n;i++){
    cin >> k;
    vec[k]++;
  }
  int cnt = 0;
  for(int i=2;i<maxval+1;i++){
    if(vec[i]==0) continue;
    for(int j=1;j<=i;j++){
      if(vec[j]==0) continue;
      for(int l=i;j<=l&&j+l>i;l--){
        if(vec[l]==0) continue;
        else cnt += cntNum(vec[i],vec[j],vec[l],i,j,l);
      }
    }
  }
  cout << cnt << endl;
  return 0;
}