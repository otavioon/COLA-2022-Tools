#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<algorithm> 
using namespace std;
typedef long long ll;
const int MAX=100010;
ll A[MAX],B[MAX],C[MAX];
int main(){
	ll N,sum=0,x=0,y=0;cin>>N;
	for(int i=1;i<=N;i++)cin>>A[i];
	for(int i=1;i<=N;i++)cin>>B[i];
	for(int i=1;i<=N;i++)cin>>C[i];
	sort(A+1,A+N+1);sort(B+1,B+N+1);sort(B+1,B+N+1);
		for(int i=1;i<=N;i++){
			while(A[x+1]<B[i]&&x+1<=N)
				x++;
			while(C[y+1]<=B[i]&&y+1<=N)
				y++;
			sum+=x*(N-y);
		}
		cout<<sum<<endl;
		return 0;
}