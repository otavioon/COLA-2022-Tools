
#include<iostream>
#include<algorithm>
#include <cstdio>
#include<cmath>
#include<ctime>
using namespace std;
#define maxn int(5*1e8)
int main(){
	int n=0;
	scanf("%d",&n);
	int*num=new int[(int)1e9+500]();
	for(int i=1;i<=n;++i){
		int temp=0;
		scanf("%d",&temp);
		num[temp]++;
	}
	int j=pow(2.0,30),ans=0;
	for(int i=1e9+4;i>=1;--i){
		if(i<j/2) j/=2;
			if(j-i>=0&&num[i]>0&&num[j-i]>0){
				if(j==i*2){
					ans+=num[i]/2;
					num[i]=num[i]%2;
				}
				else{
				ans+=max(num[i],num[j-i]);
				num[j-i]-=max(num[i],num[j-i]);
			}
			}
	}
	cout<<ans<<endl;
	delete[]num;
}
