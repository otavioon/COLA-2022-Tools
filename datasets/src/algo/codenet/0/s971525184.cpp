#include <bits/stdc++.h>
using namespace std;

int main()
{
	string str;
	long long n;
	long long res;
	cin >> str >> n;
	if(str.size() == 1){
		cout << n / 2 << endl;
		return 0;
	}else {
		int r = 0;
		int xx = str.size();
		for(int i = xx - 1; i > 0; i--){
			if(str[i] != str[i - 1]) {
				r = i;
				break;
			}
		}
		if(r == 0) cout << n * str.size() / 2 << endl;
		else{
			str = str + str;
			int lll = 1;
			int cnt = 0;
			for(int i = r; i < r + str.size() / 2 ; i++){
				if(str[i] == str[i + 1]) lll++;
				else{
					cnt = cnt + lll / 2;
					lll = 1;
				}
			}
			res = cnt * (n - 1);	
			lll = 1;
			cnt = 0;
			for(int i = 0; i < r ; i++){
				if(str[i] == str[i + 1]) lll++;
				else{
					cnt = cnt + lll / 2;
					lll = 1;
				}
			}
			res += cnt;
			res = res + (str.size() / 2 - r) / 2;
			cout << res << endl;
		}	
	}
	return 0;
}