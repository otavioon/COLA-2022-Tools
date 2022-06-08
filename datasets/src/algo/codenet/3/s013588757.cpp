#include <iostream>
#include <algorithm>
using namespace std;

int a[10010], b[10010], c[10010];

int main(){
	int n;
	long long ans=0;
	cin >> n;
	for(int i=0; i<n; i++) cin >> a[i];
	for(int i=0; i<n; i++) cin >> b[i];
	for(int i=0; i<n; i++) cin >> c[i];
	sort(a, a+n);
	sort(b, b+n);
	sort(c, c+n);

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(b[j]>a[i]){
				for(int k=0; k<n; k++){
					if(c[k]>b[j]) ans++;
				}
			}
		}
	}
	cout << ans << endl;
}