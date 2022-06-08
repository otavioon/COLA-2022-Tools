#include "bits/stdc++.h"

#define REP(i,num) for(int i=0;i<(num);++i)
#define LOOP(i) while(i--)
#define ALL(c) c.begin(),c.end()
#define PRINTALL(c) for(auto pitr=c.begin();pitr!=c.end();++pitr){cout<<*pitr;if(next(pitr,1)!=c.end())cout<<' ';}cout<<endl;
#define PAIRCOMP(c,comp) [](const pair<ll,ll>& lhs,const pair<ll,ll>& rhs){return lhs.c comp rhs.c;}

using namespace std;
using ll = long long;

constexpr ll atcoder_mod = 1e9+7;

template<typename T=int>
T in(){T x; cin >> x; return (x);}
template<typename T=int,typename C=vector<T>>
C vecin(int N){C x(N);REP(i,N){x[i]=in<T>();}return move(x);}

void vout(){cout << endl;}
template<typename Head,typename... Tail>
void vout(Head&& h,Tail&&... t){cout << ' ' << h;vout(forward<Tail>(t)...);}
void out(){cout << endl;}
template<typename Head,typename... Tail>
void out(Head&& h,Tail&&... t){cout << h;vout(forward<Tail>(t)...);}

vector<ll> enum_prime(ll N){
	deque<bool> is_prime(N+1,true);
	vector<ll> P;
	for(ll i=2;i<=N;i++){
		if(is_prime[i]){
			for(ll j=i*i;j<=N;j+=i){
				is_prime[j] = false;
			}
			P.emplace_back(i);
		}
	}
	return P;
}

vector<ll> prime_factor(ll n){
	ll sn = sqrt(n)+1;
	auto prime_list = enum_prime(sn);
	vector<ll> res;
	for(int i=0,ei=prime_list.size();i<ei;i++){
		ll v = prime_list[i];
		if(v*v>n) break;
		while(!(n%v)){
			n /= v;
			res.push_back(v);
		}
	}
	if(n>1){
		res.push_back(n);
	}

	return res;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout<<fixed<<setprecision(10);
	
	ll N=in<ll>();
	auto P = prime_factor(N);
	sort(ALL(P),greater<ll>());

	ll A=1,B=1;
	for(auto& x:P){
		if(A<=B) A*=x;
		else B*=x;
	}
	ll NA=0,NB=0;
	while(A){
		NA++;
		A/=10LL;
	}
	while(B){
		NB++;
		B/=10LL;
	}
	out(max(NA,NB));
	return 0;
}
