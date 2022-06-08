#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	int n,k,temp;	cin >> n >> k;
	set<int> S;
	while(k--){
		cin >> temp;
		S.insert(temp);
	}
	int chk=0;
	for(int i=n ; ; i++){
		chk = 0;
		temp = i;
		while(temp>0){
			int qq= temp%10;
			if(S.find(qq)!=S.end())	chk=1;
	//		cout << qq << " " << chk << endl;
			temp = temp /10;
		}
		if(chk==0){
			cout << i ;
			return 0;
		}
		
		}
}


