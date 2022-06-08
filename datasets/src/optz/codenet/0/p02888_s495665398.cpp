#include<bits/stdc++.h>
using namespace std;


int len[1001];
int main(){
	int n;	cin>>n;
	for(int i=0;i<n;i++){
		int l;	cin>>l;
		len[l]++;
	}

	long long ans=0;

	for(int i=1;i<=1000;i++){
		if(len[i]==0)continue;
		for(int j=i+1;j<=1000;j++){
			if(len[j]==0)continue;
			for(int k=j+1;k<=1000;k++){
				if(len[k]==0)continue;

				if((i<j+k)&&(j<k+i)&&(k<i+j)){
					ans++;
					//printf("(%d,%d,%d)\n",i,j,k);
				}
			}
		}
	}
	cout<<ans<<endl;

	return 0;
}
