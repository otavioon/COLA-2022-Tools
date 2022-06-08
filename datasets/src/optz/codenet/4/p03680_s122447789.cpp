// B - Trained?
#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
#define rp(i,s,e) for(int i=(s);i<(e);++i)

int main(){
	int N; cin>>N;
	vi A(N); rp(i, 0, N){cin>>A[i]; --A[i];}
	set<int> visited;
	for(int t=0, a=0; visited.find(a)==visited.end(); a=A[a], ++t){
		visited.insert(a);
		if(a == 1){
			cout<< t <<endl;
			return 0;
		}
	}
	cout<< -1 <<endl;
}