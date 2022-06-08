#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	int N,K; cin>>N>>K;
	set<int> D;
	for(int i=0;i<K;i++){
		int tmp; cin>>tmp;
		D.insert(tmp);
	}
	while(true){
		string S=to_string(N);
		bool pro=true;
		for(int i=0;i<S.size();i++){
			if(D.count(S[i]-'0')){
				pro=false;
				break;
			}
		}
		if(pro)break;
		N++;
	}
	cout<<N<<endl;
}