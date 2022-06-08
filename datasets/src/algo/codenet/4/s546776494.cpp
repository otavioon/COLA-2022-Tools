#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k;
	cin>>n>>k;
	vector<int> count(10);
	for(int i=0;i<k;++i){
		int x;
		cin>>x;
		count[x]=1;
	}
	set<int> q;
	for(int i=0;i<10;++i){
		if(count[i]==0) q.insert(i);
	}
	int flag=0;
	for(int i=n;;++i){
		int a=i;
		int flag=0;
		while(a){
			if(q.find(a%10)==q.end()) {
				flag=1;break;
			}
			a/=10;
		}
		if(!flag){
			cout<<i;
			break;
		}
	}
	return 0;
}