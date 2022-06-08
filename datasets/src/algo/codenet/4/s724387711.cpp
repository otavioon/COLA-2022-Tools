#include"bits/stdc++.h"
using namespace std;
int main(){
	int m,n;
	cin>>m>>n;
	set<char> x;
	char temp;
	for(int i=0;i!=n;++i){
		cin>>temp;
		x.insert(temp);
	}
	while(1){
		bool check=true;
		string s=to_string(m);
		for(auto i:s){
			if(x.find(i)!=x.end()){
				check=false;
				break;
			}
		}
		if(check)
			break;
		else
			++m;
	}
	cout<<m;
}