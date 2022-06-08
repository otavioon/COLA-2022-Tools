#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  int a[n];
  int counter=0;
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
  }
  sort(a,a+n);
  //int o,p,mid;
  int i=0;
  int j=1;
  int k;
  while(i<n-2)
  {
  		k=j+1;
  		while(k<n&&a[i]+a[j]>a[k])
  		{
  			k++;	
		}
		counter+=k-j-1;
		j++;
		if(j>n-2)
		{
			i++;
			j=i+1;
		}
  }
  cout<<counter<<endl;
  return 0;
}