#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define in inline
#define reg register
#define int long long
#define MAX 20030813
using namespace std;
namespace qwq{
	in void read(int &o) {
		o=0;
		int w=1;
		char c=getchar();
		while(c<'0'||c>'9') {
			if(c=='-')w*=-1;
			c=getchar();
		}
		while(c>='0'&&c<='9') {
			o=(o<<3)+(o<<1)+(c^48);c=getchar();
		}
		o*=w;
	}
	void write(int x){
	   	if(x<0)putchar('-'),x=-x;
    	if(x>9)write(x/10);
		putchar(x%10+48);
	}
	void Write(int x) {
		write(x);putchar(' ');
	}
	in int max(int x,int y){return x>y?x:y;}
	in int min(int x,int y){return x<y?x:y;}
}
using namespace qwq;

string s;
int k,num=0,ans=0,last=0;
int vis=0,viss=0,check=0;

signed main(){
	cin>>s>>k;
	if(s.length()==1){
		cout<<k/2<<endl;
		return 0;
	}	
	for(int i=0;i<s.length();i++){
		if(s[i]==s[0]) vis++;
		else break;
	}
	if(vis==s.length()){
		cout<<(k*s.length())/2;
		return 0;
	}
	for(int i=s.length()-1;i>=0;i--){
		if(s[i]==s[s.length()-1]) viss++;
		else break;
	}
	for(int i=0;i<s.length()-1;i++){
		if(s[i]==s[i+1])s[i+1]='-',num++;
	}
	if(s[0]==s[s.length()-1]){
		last=1;
		if((vis+viss)%2==1) check=1;
	}
	if(check){
		cout<<num*k<<endl;
		return 0;
	}
	else ans=(num*k+last*(k-1));
	cout<<ans<<endl;
}
