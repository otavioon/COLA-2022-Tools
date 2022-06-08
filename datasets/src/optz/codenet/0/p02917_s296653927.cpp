#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define REP(i, n) for(int i = 0; i < (int)(n); i++)

int main(){
int n;
cin>>n;
int b[n+4];
REP(i,n-1){
  cin>>b[i];
}
int a=0;
b[n-1]=1000000;
for (int i = 1; i < n-2; i++)
{
  a+=min(b[i],b[i+1]);
  
}
if (n==3)
{
  
  cout<<a+b[0]+b[n-2]+b[0]<<endl;
}
else
{
  cout<<a+b[0]+b[n-2]<<endl;
}




}


    