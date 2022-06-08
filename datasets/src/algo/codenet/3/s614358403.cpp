#include<bits/stdc++.h>
using namespace std;


int N,A[100000],B[100000],C[100000];
long long int b[100001],res;

int main(){
	cin>>N;
	for(int i=0;i!=N;++i)
		cin>>A[i];
	for(int i=0;i!=N;++i)
		cin>>B[i];
	for(int i=0;i!=N;++i)
		cin>>C[i];
	sort(A,A+N);
	sort(B,B+N);
	sort(C,C+N);
	for(int i=0;i!=N;++i){
		int l=-1,r=N;
		while(l+1!=r){
			int k=(l+r)/2;
			if(C[k]>B[i])r=k;
			else l=k;
		}
		b[i]=N-r;
	}
	for(int i=N-2;i!=-1;--i)
		b[i]+=b[i+1];
	for(int i=0;i!=N;++i){
		int l=-1,r=N;
		while(l+1!=r){
			int k=(l+r)/2;
			if(B[k]>A[i])r=k;
			else l=k;
		}
		res+=b[r];
	}
	cout<<res<<endl;
	return 0;
}
