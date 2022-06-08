#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<ctime>
#include<queue>
#include<deque>
#include<complex>
#include<cassert>
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
typedef complex<double> P;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
//問題文および制約はちゃんと確認しよう！
//サイズは10^5じゃなくて2×10^5とかかもしれないし、重要な制約・条件を見落としているかも
//とりあえずサンプルを読んでから解法を考えよう？
multiset<int> s;
int main()
{
	int n,a,out=0;
	cin>>n;
	rep(i,n){
		cin>>a;s.insert(a);
	}
	while(s.size()>0){
		//auto it=s.end();it--;
		multiset<int>::iterator it=s.end();it--;
		int t=(*it),u;
		s.erase(it);
		for(lint i=2;i<1234567890L;i*=2){
			if(i>t && i-t<=t) u=i-t;
		}
		//cout<<t<<u<<endl;
		multiset<int>::iterator i2=s.find(u);
		if(i2!=s.end()){
			out++;s.erase(i2);
		}
	}
	cout<<out<<endl;
}
