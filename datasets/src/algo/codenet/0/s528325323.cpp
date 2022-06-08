#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <cmath>
#include <cassert>
#include <iostream>
#include <string>
#include <map>
#include <set>
#define mkp make_pair
#define pb push_back
#define IOS ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=2e5+5;
const int mod=1e9+7;
const int INF=2147483647;
int main(){
	IOS;
	string s;
	cin>>s;
	int k;
	cin>>k;
	bool flag=0;
	int pos;
	for(int i=1;i<s.length();i++){
		if(s[i]!=s[i-1]){
			pos=i;
			flag=1;
			break;
		}
	}
	if(!flag){
		cout<<(long long)s.length()*k/2<<'\n';
		return 0;
	}
	string t=s;
	long long ans=0;
	for(int i=pos+1;i!=pos;i=(i+1)%s.length()){
		if(t[i]==t[i-1]){
			t[i]=0;
			ans++;
		}
	}
	long long ans2=0;
	for(int i=1;i<pos;i++){
		if(s[i]==s[i-1]){
			s[i]=0;
			ans2++;
		}
	}
	for(int i=pos+1;i<s.length();i++){
		if(s[i]==s[i-1]){
			s[i]=0;
			ans2++;
		}
	}
	cout<<ans*(k-1)+ans2<<'\n';
	return 0;
}
