#include<cstdio>
#include<algorithm>
using namespace std;

typedef long long ll;
const int Maxn=2e5;

int N;
ll A[Maxn+5];
bool used[Maxn+5];

int main() {
	#ifdef LOACL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
		scanf("%lld",&A[i]);
	sort(A+1,A+N+1);
	ll ans=0;
	for(ll num=1<<30;num;num>>=1) {
		int j=N;
		for(int i=1;i<=N;i++)
			if(!used[i]) {
				while(j>i&&(num-A[i]<A[j]||used[j]))
					j--;
				if(j<=i)break;
				if(num!=A[i]+A[j])
					continue;
				used[i]=used[j]=true;
				ans++;
			}
	}
	printf("%lld\n",ans);
	return 0;
}
/*6
1 1 2 2 7 9
*/