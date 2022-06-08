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
  	bool f=false;
  	string s;
    ll k,ans=0,ans2=1,count=1;
  	cin >> s >> k;
  	char x=s[0];
  	for (ll i=1;i<s.size();i++){
      	if (!f){
          	if (s[i]==x){
				x=s[i];
              	continue;
        	}
        }
      	if (s[i]==x){
          	count++;
        }else{
          	ans+=count/2;
          	count=1;
        }
        x=s[i];
      	f=true;
    }
  	ans*=k;
  	if (!f){
      	cout << k*s.size()/2 << endl;
      	return 0;
    }
    x=s[0];
  	for (ll i=1;i<s.size();i++){
      	if (s[i]==x){
              ans2++;
        }
        else break;
        x=s[i];
   	}
    ans+=ans2/2*k;
    if (s[0]==s[s.size()-1]){
      	if (ans2%2==1 && count%2==1)ans+=k-1;
    }
  	ans+=count/2+k;
  	if (ans>s.size()*k/2)ans=s.size()*k/2;
 	cout << ans << endl;
  	return 0;
}

