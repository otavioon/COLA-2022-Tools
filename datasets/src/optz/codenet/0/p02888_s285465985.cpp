#include<bits/stdc++.h>
/************************************************/
#define rep(i,n) for(int i=0;i<n;i++)
#define mp make_pair
#define pb push_back
#define fr first
#define se second
#define forn(i,a,n) for(int i=a;i<n;i++)
#define foreach(i,c) for(__typeof(c.begin())i=(c.begin());i!=(c).end();i++)
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define sz(s) s.size()
#define all(s) s.begin(),s.end()
#define zero(x) memset(x,0,sizeof(x))
#define vii vector<pair<int,int> >
#define mpis map<int,string>
#define mpii map<int,int>
#define mpsi map<string,int>
#define re return
/************************************************/
using namespace std;
int n;
int l[2000],cnt[1001];
int main(){
	cin>>n;
	int m1=-1,m2=-1,m3=-1,mi=1e9,mi1,mi2;
	rep(i,n){
	cin>>l[i];
	cnt[l[i]]++;
	m1=max(m1,l[i]);
	mi=min(mi,l[i]);
	}
	int k=3;
	bool f=false;
	for(int i=m1;i>=mi;i--){
		k-=cnt[i];
		if(k<1){
			m3=max(m1,i);
			m2=max(m2,i);
		}
		if(k==1){
			m2=max(m2,i);
		}
	}
	int ans=0;
	for(int a=1;a<=m3;a++){
		if(!cnt[a])
		continue;
		for(int b=a;b<=m2;b++){
			if(b==a&&cnt[a]<2)
			continue;
			if(!cnt[b])
			continue;
			for(int c=b;c<=min(a+b-1,m1);c++){
				if(!cnt[c])
				continue;
				if(c==b){
					if(c==a&&cnt[a]<3)
					continue;
					else
					if(cnt[c]<2)
					continue;
				}
				if(c!=a){
					if(c!=b)
					ans+=cnt[a]*cnt[b]*cnt[c];
					else
					ans+=cnt[a]*(cnt[b]*(cnt[b]-1));
				}
				else
				ans+=(cnt[b]*(cnt[b]-1)*(cnt[b]-2)/3/2);
			}
		}
	}
	cout<<ans;
	re 0;
}