#include<bits/stdc++.h>
using namespace std;
int a[201];
int main()
{
  int i,j,k,l,o,p,n,m;
  cin>>n>>m;
  a[2]=1;
  for(i=3;i<=13;i++)
    a[i]=a[i-1]+1;
  a[1]=a[13]+1;
  if(a[n]==a[m]) 
  {
    cout<<"Draw"<<endl;
	return 0;	
  } 
  if(a[n]>a[m])
  {
  	cout<<"Alice"<<endl;
  	return 0;
  }
  if(a[n]<a[m])
  {
  	cout<<"Bob"<<endl;
  	return 0;
  }
  return 0;
}