#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
#define int long long
int n, store[200010],list[70],ans=0;
bool vis[1000000010];
signed main(){
	cin>>n;
	for(int i=0;i<n;i++){
		int v;cin>>v;store[i]=v;vis[v]=1;
	} 
	sort(store,store+n);
	list[0]=1;
	for(int i=1;i<=60;i++)list[i]=list[i-1]*2;
	for(int i=n-1;i>=0;i--){
		int b=store[i];
		if(vis[b]==0)continue;
		int a=1;
		while(list[a]<b)a++;
		int desired=list[a]-b;
		if(vis[desired]==1){ans++;vis[desired]=0;vis[b]=0;
		}
	}
	cout<<ans<<endl;
}