#include<iostream>
#include<algorithm>
using namespace std;
int main(){
  int N;
  cin>>N;
  int a[N],b[N],c[N];
  for(int i=0;i<N;i++)cin>>a[i];
  for(int i=0;i<N;i++)cin>>b[i];
  for(int i=0;i<N;i++)cin>>c[i];
  sort(a,a+N);
  sort(b,b+N);
  sort(c,c+N);
  int cgb[N];
  for(int j=0;j<N;j++){
    cgb[j]=0;
      for(int r=0;r<N;r++){
        if(b[j]<c[r])cgb[j]=N-r;
        break;
    }
  }
  int ans;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(a[i]<b[j])ans+=cgb[j];
    }
  }
  cout<<ans;
  return 0;
}