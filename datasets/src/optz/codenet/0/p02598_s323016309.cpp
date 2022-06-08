#include<bits/stdc++.h>

using namespace std;

#define ll long long

int cnt(int a[],int n,int len){
	int ans=0;
	for(int i=0;i<n;i++){
		// int low=1,high=1000;
		// for(int j=0;j<50;j++){
		// 	int mid = (low+high)/2;
		// 	float ha=a[i];
		// 	// cout<<ha/float(mid)<<" "<<mid<<" "<<high<<" "<<low<<endl;
		// 	if(ha/float(mid+1)<=len){
		// 		high=mid;
		// 	}
		// 	else
		// 	{
		// 		low=mid+1;
		// 	}
		// }
		int tempVal = (((a[i]-1)/len));
		// cout<<tempVal<<endl;
		ans+=tempVal;
	}
return ans;
}

int main() {
	int n,k;
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int low=1,high=1e9 + 5;
	int ans=0;
	for(int i=0;i<50;i++){
		int mid = (high+low)/2;
		if(mid==0)
		continue;
		// cout<<mid<<endl;
		int value = cnt(a,n,mid); 
		if(value<=k){
			ans=mid;
			high=mid-1;
		}
		else{
			low=mid+1;	
		}
	}
	// while(1){
	// 	if(cnt(a,n,ans-1)==k){
	// 		ans--;
	// 	}
	// 	else
	// 	break;
	// }
	cout<<ans<<endl;
	return 0;
}

