#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;


int main()
{
	int t;//???t?????
	cin>>t;
	for(int r=1;r<=t;r++)//?t???
	{
		int m,n;
		cin>>m>>n;//???????m?n
		int juzhen[100][100];//????
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				cin>>juzhen[i][j];//???????
		int *p;//????
		int sum=0;//???
		for(int s=0;s<m;s++)//s??????0???m-1
		{
			if(s==0||s==m-1)//????????????
			{
				for(p=juzhen[s];p<=&juzhen[s][n-1];p++)//??????????????????
					sum=sum+(*p);
			}
			else//?????????????????
			{
				p=juzhen[s];
				sum=sum+(*p)+*(p+n-1);
			}
		}
		cout<<sum<<endl;//????
		}
	return 0;
}
