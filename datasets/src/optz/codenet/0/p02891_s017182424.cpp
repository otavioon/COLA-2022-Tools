#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	string S;
	int k;
	long long contador=0, estado = 0, estado2=0;
	cin>>S>>k;
	for(int i=0;i<S.size()-1;i++){
		if(S[i] == S[i+1]){
			contador++;
			i++;
		}
	}
	if(S[0]==S[S.size()-1]){
		int j=S.size()-1;
		while(j>=0){
			if(S[j]!=S[S.size()-1]){
				break;
			}
			estado++;
			j--;
		}
		j=0;
		while(j<S.size()){
			if(S[j]!=S[0]){
				break;
			}
			estado2++;
			j++;
		}
	}
	if(estado%2==1 and estado2%2==1){
		if(k%2==0){
			contador=contador*(k/2)+(contador+1)*(k/2);
		}
		else if(k>1){
			if(S.size()!=estado){
				contador+=(contador+1)*(k-1);
			}
			else{
				contador=contador*(k-1)+(contador+1)*(k-2);
			}
		}
	}
	else{
		contador*=k;
	}
	cout<<contador<<"\n";
	return 0;
}
