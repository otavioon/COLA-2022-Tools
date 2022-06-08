#include<bits/stdc++.h>                                                   
using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)
#define rept(i,a,b) for(int i=a; i<b; i++)
#define all(x) (x).begin(),(x).end()

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> P;

const int mod = 1e9 + 7;


int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	string s;
	cin >> s;
	ll k;
	cin >> k;

	int len = s.size();
	if(len==1){
		cout << k / 2 << endl;
		return 0;
	}


	s.push_back(s[0]);
	ll ans = 0, cnt = 0;
	rep(i, len+1){
		if(s[i] == s[i+1]){
			cnt++;
		}else{
			if(cnt % 2 == 0){
				ans += cnt/2;
			}else{
				ans += (cnt/2)+1;
			}
			if(cnt==len && cnt % 2 == 1){
				break;
			}
			cnt=0;	
		}

	}

	if(cnt == len){
		cout << (ans * k) - round(k/2.0) << endl;
	}else{
		cout << ans * k << endl;
	}
    return 0;
}

