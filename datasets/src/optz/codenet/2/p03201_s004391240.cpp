#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define LL long long
using namespace std;
LL A[505050];
int n,ans;
bool Tag[2020202];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%lld",&A[i]);
	sort(A+1,A+n+1);
	for (LL x=(1ll<<31);x>0;x>>=1ll){
		int r=n;
		for (int l=1;l<=n;l++){
			if (l>=r) break;
			if (Tag[l]) continue;
			while (r>l&&(Tag[r]||A[l]+A[r]>x)) r--;
			if (l>=r) break;
			if (A[l]+A[r]==x){
				Tag[l]=1; Tag[r]=1; ans++;
			}
		}
	}
	cout<<ans;
}