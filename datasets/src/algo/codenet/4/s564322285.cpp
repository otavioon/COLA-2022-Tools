#include<iostream>
using namespace std;
int main(){
	int n,k;
	int tens[5]={1,10,100,1000,10000};
	int ones[5]={0,1,11,111,1111};
	int d[10]={0};
	cin>>n>>k;
	for(int i=0;i<k;i++){
		int piyo;
		cin>>piyo;
		d[piyo]=-1;
	}
	int ans=0;
	int maxnum;
	for(int i=9;i>0;i--){
		if(d[i]==0){maxnum=i;break;}
	}
	for(int i=4;i>=0;i--){
		int target=0;
		while(ans+target*tens[i]+maxnum*ones[i]<n  or d[target]!=0){
			if(ans==0 and target==0 and ans+target*tens[i]+maxnum*ones[i]>=n){break;}
			else{target++;}
		}
		ans+=target*tens[i];
	}
	cout<<ans<<endl;
	return 0;
}