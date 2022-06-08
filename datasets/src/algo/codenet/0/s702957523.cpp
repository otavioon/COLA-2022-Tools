#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>
#include <iomanip>
#include <bitset>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <utility>
#include <set>
using namespace std;
//cout <<  << endl;
typedef long long int ll;
typedef double ld;

int main(){
  	bool flag=false;
  	string s;
    ll k,ans=0;
  	cin >> s >> k;
  	char x=s[0];
  	for (ll i=1;i<s.size();i++){
      	if (s[i]==x){
          	ans++;
      		x=s[i];
          	if (flag){
              	flag=false;
              	ans--;
              	continue;
            }
          	flag=true;
        }else{
			x=s[i];
          	flag=false;
        }
    }
  	ans*=k;
  	if (s[0]==s[s.size()-1]){
      	if (s.size()>1 && s[0]==s[1])flag=true;
      	if (!flag){
      		ans+=k-1;
        }
    }
  	if (ans>s.size()*k/2)ans=s.size()*k/2;
  	cout << ans << endl;
  	return 0;
}