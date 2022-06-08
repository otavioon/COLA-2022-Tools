#include<iostream>
using namespace std;
int main(){
	long N,L[2000],count=0,pre,len[1001],lenD[1001];
	cin>>N;
	for(int i=0;i<N;i++)cin>>L[i];
	for(int i=0;i<N-1;i++){
		for(int j=0;j<N-i-1;j++){
			if(L[j]>L[j+1]){
				pre=L[j];
				L[j]=L[j+1];
				L[j+1]=pre;
			}
		}
	}
	for(int i=0;i<=1000;i++){len[i]=0;lenD[i]=0;}
	for(int i=0;i<N;i++){
		if(len[L[i]]==0)len[L[i]]=1;
		lenD[L[i]]++;
	}
	for(int i=1;i<=1000;i++){
		len[i]=len[i-1]+len[i];
	}
	for(int i=0;i<N-1;i++){
		if(i>0 && L[i]==L[i-1])continue;
		
		for(int j=i+1;j<N-1;j++){
			
			if(j>i+1 && L[j]==L[j-1])continue;
			
			if(L[i]+L[j]-1>=1000)pre = len[1000];
			else pre =len[L[i]+L[j]-1];
			
			if(L[i]<L[j]){
				pre-=len[L[j]];
				if((lenD[L[j]]>1 && L[i]!=L[j])|| lenD[L[j]]>2)pre+=1;
			}else{
				pre-=len[L[i]];
				if((lenD[L[i]]>1&& L[i]!=L[j]) || lenD[L[i]]>2)pre+=1;
			}
			
			if(pre>0)count+=pre;
		}
	}
	cout<<count;
	return 0;
}