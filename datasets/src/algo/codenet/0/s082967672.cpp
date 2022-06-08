using namespace std;
#include <iostream>
int main()
{
	char a[102];
	int i=0;
	while(1)
	{
		a[i]=getchar();
		if(a[i]=='\n') break;
		i++;
	}
	a[i]=a[0];
	int flag=0;
	for(int j=0;j<=i;j++)
	{
		if(a[j]==a[j+1]) 
		{
			flag++;j++;
		}			 
	}
	long long int k;
	cin>>k;
	if(a[i]==a[i-1])
		{if(i>1&&a[i-2]!=a[i-1])
		cout<<flag*k-1;
		else
		 cout<<flag*k;
		} 
	else
	{
		cout<<flag*k;
	}
}