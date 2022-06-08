#include <iostream>
using namespace std;

int main() {
	int N, M;
	string s[N], t[M];
	cin >> N;
	for (int i=0; i<N; i++) cin >> s[i];
	cin >> M;
	for (int i=0; i<M; i++) cin >> t[i];
	int ans=0; 
	for (int i=0; i<N; i++){
	    int count=0;
	    for (int j=0; j<N; j++) if (s[i]==s[j]) count++;
	    for (int k=0; k<M; k++) if (s[i]==t[k]) count--;
	    ans=max(count,ans);
	}
	cout << ans << endl;
}