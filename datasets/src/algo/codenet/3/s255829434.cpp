#include <cstdio>
#include <cmath>
#include <vector>
#include <iostream>
#include <set>
#include <queue>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
#define mst(a,b) memset((a),(b),sizeof(a))
#define rush() int T;scanf("%d",&T);while(T--)
typedef long long ll;
ll a[100005],b[100005],c[100005];
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];
	for(int i=1;i<=n;i++)
		cin>>c[i];
	sort(a+1,a+1+n);
	sort(b+1,b+1+n);
	sort(c+1,c+1+n);
	ll ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i]>=b[j])continue;
			for(int k=1;k<=n;k++){
				if(b[j]>=c[k])continue;
				if(a[i]<b[j]&&b[j]<c[k])ans++;
				
			}
		}
	}
	cout<<ans;
    return 0;
}
