#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	
	int n;
	cin >> n;

	int tmp;
	int vA[n], vB[n], vC[n];
	for(int i=0; i<n; i++){
		cin >> tmp;
		vA[i] = tmp;
	}
	for(int i=0; i<n; i++){
		cin >> tmp;
		vB[i] = tmp;
	}
	for(int i=0; i<n; i++){
		cin >> tmp;
		vC[i] = tmp;
	}

	sort(vA, &vA[n-1]);
	sort(vB, &vB[n-1]);
	sort(vC, &vC[n-1]);

	int cnt = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(vA[i] < vB[j]) {
				for(int k=0; k<n; k++){
					if(vB[j] < vC[k]) {
						cnt++;
					}else{
						break;
					}
				}
			}
		}
	}
	cout << cnt;

	return 0;
}

