#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n, st, en;
	long long res = 0;
	long long t;
	cin >> n;
	vector<int> l(n);
	vector<int> ruisekiwa(2001);
	for(int i=0; i<n; i++){
		cin >> l[i];
	}
	sort(l.begin(), l.end());

	for(int i=0; i<2001; i++){
		ruisekiwa[i] = 0;
	}
	for(int i=0; i<n; i++){
		ruisekiwa[l[i]] += 1;
	}
	for(int i=1; i<2001; i++){
		ruisekiwa[i] += ruisekiwa[i-1];
	}
	//for(int i=1; i<4; i++){
	//	cout << ruisekiwa[i] << endl;
	//}

	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			st = l[j] - l[i];
			en = l[i];
			//cout << "st: " << st << ",  en: " << en << endl;
			if(en - st <= 1){
				continue;
			}
			t = ruisekiwa[en-1] - ruisekiwa[st];
			t *= ruisekiwa[l[i]]-ruisekiwa[l[i]-1];
			t *= ruisekiwa[l[j]]-ruisekiwa[l[j]-1];
			res += t;
			//cout << "diff: " << ruisekiwa[en-1] - ruisekiwa[st] << endl;;
			//cout << "left: " << ruisekiwa[st] << ",    right: " <<  ruisekiwa[en-1] << endl;
		}
	}
	cout << res << endl;
	return 0;
}
