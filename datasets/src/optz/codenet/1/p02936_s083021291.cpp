#include <iostream>
#include <vector>
#define BIG 1e8
using namespace std;
struct tree{
	int m;
	int d;
	int c;
};
tree t[200001];
int main() {
	int N,Q;
	cin>>N>>Q;
	t[1].m = 0;
	t[1].d = 0;
	for(int i=2; i<=N; i++)t[i].d = BIG;
	int a,b;
	for(int i=0; i<N-1; i++){
		cin>>a>>b;
		if(t[a].d>t[b].d){
			t[a].m = b;
			t[a].d = t[b].d+1;
		}else{
			t[b].m = a;
			t[b].d = t[a].d+1;
		}
	}
	int p,x;
	for(int i; i<Q; i++){
		cin>>p>>x;
		t[p].c += x;
	}
	for(int i=1; i<=N; i++){
		int ans=0,node=i;
		do{
			ans += t[node].c;
			node = t[node].m;
		}while(node != 0);
		cout<<ans<<" ";
	}
	return 0;
}