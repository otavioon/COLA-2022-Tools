#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<string.h>
#include<algorithm>
#include <cmath>

using namespace std;

long long N,A[1001]={0},i,j,k,ans;

int main()
{
  cin >>N;

  for(i=0;i<N;i++)
  {
    cin >> j;
    A[j]++;
  }
  ans=0;
  for(i=1;i<1001;i++)
  {
    for(j=i;j<1001;j++)
    {
      for(k=j;k<1001;k++)
      {
        if(k<i+j)
        {
          if(i==j && j!=k) ans+=A[i]*(A[i]-1)*A[k]/2;
          else if(i!=j && j==k) ans+=A[i]*A[j]*(A[j]-1)/2;
          else if(i==j && j==k) ans+=A[i]*(A[i]-1)*(A[i]-2)/6;
          else ans+=A[i]*A[j]*A[k];
        }
      }
    }
  }
  
  cout <<ans;
  
  
}