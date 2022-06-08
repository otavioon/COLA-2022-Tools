#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
#include <cstdio>
using namespace std;
const int INF=1000000000;
int a[100000],b[100000],c[100000],N;
long long A[100000]={};
int main(){
	cin>>N;
	for(int i=0;i<N;++i)cin>>a[i];
	for(int i=0;i<N;++i)cin>>b[i];
	for(int i=0;i<N;++i)cin>>c[i];
	sort(a,a+N);
	sort(b,b+N);
	sort(c,c+N);
	long long t=N-1,ans=0;
	for(int i=N-1;i>=0;--i){
		while(1){
			if(b[i]>a[t]){
				A[i]=t+1;break;
			}else{
				if(t==0)break;
				--t;
			}

		}
//		cout<<A[i]<<" ";
	}
//	cout<<endl;
	t=0;
	for(int i=0;i<N;++i){
		while(1){
			if(b[i]<c[t]){
				ans+=A[i]*(N-t);
				break;
			}else{
				if(t==N-1)break;
				++t;
			}

		}
	}

	cout<<ans<<endl;
	return 0;
}
