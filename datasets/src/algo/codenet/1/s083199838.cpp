#include  <bits/stdc++.h>
using  namespace  std;

int  main()
{
	int  a[4][4],i,j,x,y,z;
	
	for(i=1; i<=3; i++)
    	for(j=1; j<=3; j++)
    	   cin>>a[i][j];
    	   
    x=a[1][1]+a[2][2]+a[3][3];
    y=a[1][2]+a[2][3]+a[3][1];
    z=a[1][3]+a[2][1]+a[3][2];
    
    if(x==y && x==z && y==z)
       cout<<"yes"<<endl;
    else
       cout<<"no"<<endl;
       
    return 0;
}