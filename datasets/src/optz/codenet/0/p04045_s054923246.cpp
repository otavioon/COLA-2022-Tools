#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> d(k);
	for(int i = 0;i < k;i++){
		cin >> d[i];
	}
	vector<int> uk(10 - k);
	for(int i = 0;i < 10;i++){
		if(!binary_search(d.begin(), d.end(), i)){
			uk.push_back(i);
		}
	}
	
	vector<int> r(4);
	r[0] = n % 10;
	n /= 10;
	r[1] = n % 10;
	n /= 10;
	r[2] = n % 10;
	n /= 10;
	r[3] = n % 10;
	n /= 10;
	
	bool f = false;
	
	int ans = 0;
	
	
	if(!f){
		bool sf;
		for(int i = 0;i <= r[3];i++){
			if(binary_search(d.begin(), d.end(), r[3] + i)){
				sf = true;
			}else{
				ans += ((r[3] + i) * 1000);
				if(i == 0){
					f = true;
				}
				sf = false;
				break;
			}
		}
		if(sf){
			ans += 10000;
			f = true;
		}
	}
	
	if(!f){
		for(int i = 0;i <= r[2];i++){
			if(binary_search(d.begin(), d.end(), r[2] + i)){
			}else{
				ans += ((r[2] + i) * 100);
				if(i == 0){
					f = true;
				}
				break;
			}
		}
	}else{
		for(int i = 0;i < 10 - k;i++){
			if(uk[i] >= r[2]){
				ans += uk[i] * 100;
				break;
			}
		}
	}
	if(!f){
		for(int i = 0;i <= r[1];i++){
			if(binary_search(d.begin(), d.end(), r[1] + i)){
			}else{
				ans += ((r[1] + i) * 100);
				if(i == 0){
					f = true;
				}
				break;
			}
		}
	}else{
		for(int i = 0;i < 10 - k;i++){
			if(uk[i] >= r[2]){
				ans += uk[i] * 10;
				break;
			}
		}
	}
	if(!f){
		for(int i = 0;i <= r[0];i++){
			if(binary_search(d.begin(), d.end(), r[0] + i)){
			}else{
				ans += ((r[0] + i) * 100);
				if(i == 0){
					f = true;
				}
				break;
			}
		}
	}else{
		for(int i = 0;i < 10 - k;i++){
			if(uk[i] >= r[2]){
				ans += uk[i];
				break;
			}
		}
	}
	
	
	cout << ans;
}
