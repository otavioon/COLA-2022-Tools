#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <math.h>
#include <unordered_map>
#include <numeric>
#include <sstream>
#include <functional>
using namespace std;

int main()
{
	string s;
	long long int n=0,size=0,cnt=0,ans=0;
	bool flag=false;

	std::cin >> s >> n;

	if(s.size() == 1){
		cout << n/2 << endl;
		return 0;
	}

	if(s[0] == s[s.size()-1] && s[0] != s[s.size()-2]){
		flag=true;
	}

	if(flag)
		s+=s[0];

	char tmp=s[0];
	for (int i = 1; i < s.size(); i++)
	{
		if(s[i] == tmp){
			cnt++;
			tmp='\0';
		}else{
			tmp=s[i];
		}
	}

	if(flag){
		ans = (cnt*n)-1;
	}else{
		ans = cnt*n;
	}
	
	cout << ans << endl;

	return 0;
}
