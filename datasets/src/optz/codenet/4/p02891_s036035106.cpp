#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000000000000


int main(){
    
	string S;
	cin>>S;
	
	set<char> s;
	for(int i=0;i<S.size();i++){
		s.insert(S[i]);
	}
	
	long long K;
	cin>>K;
	
	long long ans = 0;
	
	if(s.size()!=1){
		long long C = 0;
		for(int i=S.size()-1;i>=0;i--){
			if(S[i]==S[0]){
				C++;
				S.erase(S.begin()+i);
			}
			else{
				break;
			}
		}
		long long D = 0;
		while(true){
			if(S[0]!=S[1])break;
			D++;
			S.erase(S.begin()+1);
		}
		S.erase(S.begin());
		D++;
		
		for(int i=1;i<S.size();i++){
			if(S[i]==S[i-1]){
				ans++;
				S[i]='(';
			}
		}
		
		
		ans *= K;
		ans += C/2;
		ans += D/2;
		ans += ((C+D)/2)*(K-1);
		
		
	}
	else{
		ans = (K*S.size())/2;
	}
	
	cout<<ans<<endl;
    
    
    return 0;
}

