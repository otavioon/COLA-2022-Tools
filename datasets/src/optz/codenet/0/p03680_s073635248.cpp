#include <iostream>
using namespace std;

int a[100001];
int vis[100001];
int main(){
	int n,ans= 0;
	
	cin >> n;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	int i = 1;
	while(!vis[i]&&i!=2){
		vis[i] = 1;
		ans++;
		i = a[i];
	}
	if(i!=2) cout << "-1";
	else cout << ans;
} 