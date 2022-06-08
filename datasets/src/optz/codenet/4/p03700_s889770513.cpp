#include<iostream>

using namespace std;

int max_num(int h[], int n)
{
	int i;
	int tmp=h[0];
	int ans=0;
	for(i=1;i<n;i++)
	{
	 if(tmp<h[i])
	 {
	 	tmp=h[i];
	 	ans=i;
	 }
	 }
	 return ans;
	}

int main()
{
	int n;
	int a,b;
	cin>>n>>a>>b;
	int h[n];
	int i;
	int max_mon;
	int sum=1;
	int ans=0;
	int kiroku;
	for(i = 0; i<n;i++)
	{
		cin>>h[i];
	}
	while(sum>0){
	sum=0;
	ans++;
	max_mon=max_num(h, n);
	
	for(i=0;i<n;i++)
	{
		if(i==max_mon){
		h[i]=h[i]-a;
		if(h[i]>0)
		{
			sum=sum+1;
	}
	}
		else{
			h[i]=h[i]-b;
			if(h[i]>0){
			sum=sum+1;
	}
	}
}
}

cout<<ans<<"\n";
return 0;
}
	
