#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;
#define ll long long

void swap(pair<int,int> *a,pair<int,int> *b){
	pair<int,int> temp=*a;
	*a=*b;
	*b=temp;
}
void quicksort(pair<int,int> a[],int lower,int upper){
	pair<int,int> bound=a[lower];
	int l=lower,u=upper;
	//printf("lower = %d, upper = %d\n",l,u);
	do{
		while(a[l]<bound)l++;
		while(a[u]>bound)u--;
		if(l<=u){
			swap(&a[l],&a[u]);
			l++;
			u--;
		}
	}while(l<u);
	if(lower<u)quicksort(a,lower,u);
	if(l<upper)quicksort(a,l,upper);
}
int main(){
	int n,q;
	pair<int,int> ab[200010]={};
	pair<int,int> px[200010]={};
	int v[200010]={};
	cin>>n>>q;
	for(int i=0;i<n-1;i++){
		cin>>ab[i].first>>ab[i].second;
	}
	for(int i=0;i<q;i++){
		cin>>px[i].first>>px[i].second;
	}
	quicksort(ab,0,n-2);
	quicksort(px,0,q-1);
	int p_ab=0,p_px=0;
	for(int i=1;i<=n;i++){
		//cout<<"set"<<i<<endl;
		while(1){
			if(px[p_px].first==i){
				v[i]+=px[p_px].second;
				p_px++;
			}else if(px[p_px].first>i || px[p_px].first==0){
				break;
			}
		}
		//cout<<"send"<<i<<endl;
		while(1){
			//cout<<"  send"<<p_ab<<" "<<ab[p_ab].first<<endl;
			if(ab[p_ab].first==i){
				//cout<<"1"<<endl;
				v[ab[p_ab].second]+=v[i];
				p_ab++;
			}else if(ab[p_ab].first>i || ab[p_ab].first==0){
				//cout<<"3"<<endl;
				break;
			}
		}
		//cout<<"end"<<i<<endl;
	}
	for(int i=1;i<=n;i++){
		cout<<v[i]<<" ";
	}
	return 0;
}
