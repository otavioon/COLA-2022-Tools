#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define debug(x) cout<<#x<<": "<<x<<endl
#define DEBUG(x) cout<<#x<<": "<<x<<endl
int powint(int a, int x){
	int res = 1;
	REP(i,x){
		res = res *a; 
	}
	return res;
}

using namespace std;

int main(){
	int N;
	cin>>N;
	vector<int> A(N);
	REP(i,N){
		cin>>A[i];
	}
	sort(A.begin(),A.end());//昇順
	//REP(i,A.size()) cout<<A[i]<<endl; 
	int ans=0;
	int q=0;//今みているかずが 2^q 以上である
	vector<int> p2; p2.push_back(1);//table
	while(true){
		//cout<<p2.back()<<endl;
		p2.push_back(p2.back()*2);
		if(p2.back()>1e9) break;
	}
	q=p2.size()-2;
	//debug
	//REP(i,p2.size()) cout<<p2[i]<<endl; 
	/*REP(i,N){
		while(A[i]<p2[q]){
			q--;
		}
	}*/
	constexpr int k=10;
	const int m=p2[k]; //debug(m);
	vector<int> s1; s1.push_back(0);
	{
		int a=1; int t=a*m;
		REP(i,N){
			if(A[i]>=t){
				//debug(t);debug(i);
				s1.push_back(i);
				a++; t=a*m; i--;
			}
		}
	}
	vector<int> s2; s2.push_back(-1);
	{
		int a=1; int t=a*m;
		REP(i,N){
			if(A[i]>t){
				//debug(t);debug(i);
				s2.push_back(i-1);
				a++; t=a*m; i--;
			}
		}
	}
	//REP(i,s1.size()) cout<<s1[i]<<endl; 
	//REP(i,s2.size()) cout<<s2[i]<<endl; 
	for(int u=s1.size()-1; u>0; u--){
		const int l1 = s1[u];
		const int r1 = u==s1.size()-1 ? A.size()-1: s1[u+1];
		int targ;
		REP(i,p2.size()){
			if(u<p2[i]){
				targ=i; break;
			}
		}
		//debug(u);debug(targ);
		//if(s2[p2[targ]-u-1]==-1) continue;
		const int l2 = max(s2[p2[targ]-u-1],0);
		const int r2 = s2[p2[targ]-u];

		//debug(l1); debug(r1); debug(l2);debug(r2);
		for(int i=l1; i<=r1; ++i){
			for(int j=l2; j<=r2; ++j){
				if(A[i]+A[j]==p2[targ+k]){
					//debug(A[i]); debug(A[j]);
					ans++;
					A[i]=-1e9;
					A[j]=-1e9;
					break;
				}
			}
		}
	}
	int mm;
	if(s2.size()==1) mm=A.size();
	else int mm=s2[1];
	for(int i=mm; i>=0; --i){
		for(int j=i-1; j>=0; --j){
			REP(k2, k){
				if(A[i]+A[j]==p2[k2+1]){
					//debug(A[i]); debug(A[j]);
					ans++;
					A[i]=-1e9;
					A[j]=-1e9;
					//break;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
