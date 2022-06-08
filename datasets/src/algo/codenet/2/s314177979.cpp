#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,p,sum=0,x;
	vector<int> vec;
	cin>>n;
	while(n--){
		cin>>p;
		vec.push_back(p);
	}
		for(int i=0; i<vec.size()-1;i++){
			for(int j=i+1;j<vec.size();j++){
				if(vec[i]!=0&&vec[j]!=0){
					for(int t=2;t<40;t++){
						x=pow(2,t);
						if(vec[i]!=0&&vec[j]!=0&&(vec[i]+vec[j])%x==0){
							sum++;
							vec[i]=0;
							vec[j]=0;
					}
					}
				}
			}
	}
	cout<<sum;
}