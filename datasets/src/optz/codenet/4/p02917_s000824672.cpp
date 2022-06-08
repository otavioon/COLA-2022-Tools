#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,b[125];
ll sum;
int main()
{
	cin>>n;
	for(int i=1;i<n;i++){
		cin>>b[i];
	}
	int k=0;
	for(int i=1;i<n;i++){
		if(i==1&&k==0){
			sum+=b[i];
			k=1;
			i--;
			continue;
		}
		if(i!=n-1){
			if(b[i]>b[i-1]&&b[i]>b[i+1]) sum+=max(b[i-1],b[i+1]);
			else sum+=b[i];
		}
		else sum+=max(b[i],b[i+1]);
	}
	cout<<sum;
	
	return 0;
}