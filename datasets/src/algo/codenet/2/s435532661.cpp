# include "algorithm"
# include "iostream"
# include "cstdio"
# include "set"

using namespace std;

const int maxm=2e5+10;
const int maxn=31;
int N,A[maxm];
multiset<int> LH;

int main(){
	register int i,j,k,Ans=0;
	scanf("%d",&N);
	for(i=1;i<=N;i++){
		scanf("%d",A+i);
		LH.insert(A[i]);
	}
	while(LH.size()){
		int i=*LH.rbegin();
		LH.erase(--LH.end());
		for(j=30;j;j--){
			k=(1<<j)-i;
			if(LH.find(k)!=LH.end()){
				multiset<int>:: iterator it=LH.lower_bound(k);
				LH.erase(it);
				Ans++;
				break;
			}
		}
	}
	printf("%d",Ans);
	return 0;
}