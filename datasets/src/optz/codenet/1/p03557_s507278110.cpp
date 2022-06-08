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

	int cnt = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			for(int k=0; k<n; k++){
				if(vA[i] < vB[j] && vB[j] < vC[k]) {
					cnt++;
				}
			}
		}
	}
	cout << cnt;

	return 0;
}

