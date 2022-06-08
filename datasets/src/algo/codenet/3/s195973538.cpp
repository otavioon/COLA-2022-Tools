#include<iostream>
using namespace std;

typedef unsigned long long int ullint;

ullint data[3][10002] = { 0 };
ullint dp[3][10002] = { 0 };

int main(){
	int n;
	int max = 0;
	cin >> n;
	for(int i = 0; i < 3; ++i){
		for(int i2 = 0; i2 < n; ++i2){
			cin >> data[i][i2];
			if(i == 0){
				dp[i][data[i][i2]] += 1;
			}
			if(max < data[i][i2]){ max = data[i][i2]; }
		}
		for(int j = 0; j < n; ++j){
			for(int j2 = j + 1; j2 < n; j2++){
				if(data[i][j] > data[i][j2]){
					ullint temp = data[i][j];
					data[i][j] = data[i][j2];
					data[i][j2] = temp;
				}
			}
		}
	}
	max += 1;

	for(int i = 1; i < 3; ++i){
		for(int i2 = 0; i2 < n; ++i2){
			for(int j = 0; j < max; ++j){
				if(data[i][i2] < j){ break; }
				if(dp[i - 1][j] > 0){
					dp[i][data[i][i2]] += dp[i - 1][j];
				}
			}
		}
	}
	ullint ans = 0;
	for(int i = 0; i < max; ++i){
		ans += dp[2][i];
	}
	cout << ans << endl;

	return 0;
}
