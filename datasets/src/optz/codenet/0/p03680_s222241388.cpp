#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	int N;
	cin >> N;
	int a[N];
	bool done[N];
	for(int i=0;i<N;i++){
		cin >> a[i];
		done[i]=false;
	}
	
	int L=1;
	for(int i=0;i<N;i++){
		if(done[L-1]){
			cout << -1 << endl;
			return 0;
		}
		else{
			done[L-1]=true;
			L=a[L-1];
			if(L==2){
				cout << i+1 << endl;
				return 0;
			}
		}
	}
	cout << -1 << endl;
}