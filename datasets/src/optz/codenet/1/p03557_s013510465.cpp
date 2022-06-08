#include <cstdio>

int main(){
	
	int N;
	scanf("%d",&N);
	
	int A[N];
	int B[N];
	int C[N];
	
	for(int i=0;i<N;i++){
		scanf("%d",&A[i]);
	}for(int j=0;j<N;j++){
		scanf("%d",&B[j]);
	}for(int k=0;k<N;k++){
		scanf("%d",&C[k]);
	}
	
	int ans=0;
	for(int i=0;i<N;i++){
		int acnt=0;
		int ccnt=0;
		int cnt=0;
		for(int j=0;j<N;j++){
			if(A[j]<B[i]){
				acnt++;
			}
		}
		for(int k=0;k<N;k++){
			if(B[i]<C[k]){
				ccnt++;
			}
		}
		cnt = acnt*ccnt;
		ans += cnt;
	}
	printf("%d",ans);
}