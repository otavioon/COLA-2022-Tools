#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
long double findans(vector<long double>&logs,int n,int k){
	if(k==0){
		return logs[n-1];
	}
	long double ans=logs[n-1];
	long double c=0;
	for(int l=1;l<=k;++l){
		if(logs[n-1]/(l+1)>c){
			c=logs[n-1]/(l+1);	
		}
		if(n>1){
			long double u=findans(logs,n-1,k-l);
			if(u>c){
				c=u;
			}
		}
		ans=min(ans,c);
		c=0;
	}
	return ans;
}
int main(){
	int n,k;
	cin>>n>>k;
	vector<long double>logs(n);
	for(int i=0;i<n;++i){
		cin>>logs[i];
	}
	sort(logs.begin(),logs.end());
	long double s=findans(logs,n,k);
	int ans=(int)s;
	if(s>ans)ans+=1;
	cout<<ans<<endl;
	return 0;
}