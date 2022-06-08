#include<bits/stdc++.h>
#define REP(i,a,b) for(int i(a);i<=(b);++i)

typedef long long ll;

#define gc getchar()
inline int read(){char c,p=0;int w;
	while(!isdigit(c=gc))if(c=='-')p=1;w=c&15;
	while(isdigit(c=gc))w=w*10+(c&15);return p?-w:w;
}

template<typename T,typename U>inline bool smin(T&x,const U&y){return y<x?x=y,1:0;}
template<typename T,typename U>inline bool smax(T&x,const U&y){return x<y?x=y,1:0;}

const int N=2e5+5;
int n;
std::multiset<int>s;
int main(){
	n=read();
	if(n==1)return puts("0"),0;
	REP(i,1,n)s.insert(read());
	int t=31,ans=0;
	for(int i=t;i;--i){
		int u=1<<i;
		if(s.size()<2)break;
		for(auto k=s.begin();k!=s.end();){
			if(*k>(u>>1))break;
			auto it=s.lower_bound(u-*k);
			if(it==k){
				if(it==s.end()){
					++k;continue;	
				}
				++it;
			}
			if((ll)*it+*k==u)++ans,s.erase(it),s.erase(k++);
			else ++k;
		}
	}
	std::cout<<ans;
	return 0;
}
