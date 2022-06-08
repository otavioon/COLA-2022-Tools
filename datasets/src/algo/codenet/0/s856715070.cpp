#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string>
#include <algorithm>
#include <cstring>
#define mem(i,a) memset(i,a,sizeof(i))
#define PI acos(-1.0)
#define DMAX 100005
#define MOD 20190823
#define eps 1e-8
#define bl bool
#define INF 1e+9
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
template<class T> inline void read(T &f){
	f=0;
    T x=1;
    char ch=getchar();
    while(ch<48 || ch>57) {
        if(ch=='-') {
            x=-1;
        }
        ch=getchar();
    }
    while(ch<=57 && ch>=48) {
        f=f*10+ch-'0';
        ch=getchar();
    }
    f*=x;
}
int main(){
	string s;
	cin>>s;
	ll k;
	read(k);
	ll coun=0;
	ll ans=0;
	bool flag=1;
	for(ll i=1;i<s.size();i++){
		if(s[i]!=s[i-1]){
			flag=0;
		}
	}
	if(flag){
		ll p=(ll)s.size();
		p*=k;
		cout<<p/2<<endl;
		return 0;
	}
	string t=s;
	for(ll i=1;i<s.size();i++){
		if(t[i]==t[i-1]){
			coun++;
			t[i]='2';
		}
	}
	for(ll i=0;i<s.size();i++){
		if(s[0]==s[s.size()-1]){
			char ch=s[s.size()-1];
			char trp=s[0];
			for(ll i=1;i<s.size();i++){
				trp=s[i];
				s[i]=trp;
			}
			s[0]=ch;
		}
//		cout<<s<<endl;
	}
	for(ll i=1;i<s.size();i++){
		if(s[i]==s[i-1]){
			ans++;
			s[i]='1';
		}
	}
	coun+=(ans*(k-1));
	cout<<coun<<endl;
	return 0;
} 