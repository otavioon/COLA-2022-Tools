#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int main()
{
	int a[5],b[5],c[5][5];
	int i,j,sum=0;
	for (i=1;i<4;i++) 
	for (j=1;j<4;j++) {
		cin>>c[i][j];
		sum+=c[i][j];
	}
	if (sum%3==0) cout<<"Yes"<<endl;
	else 		  cout<<"No"<<endl;
	return 0;
}