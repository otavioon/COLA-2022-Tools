//AtCoder ABC058 C - Digits in Multiplication
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

void PrimeFactorization(ll n, vector<ll>& x){
    ll num=n;
	//for(int i = 2; i <= n; i++) {
    for(int i = 2; i <= num; i++) {
		while(num % i == 0) { //素数で割り切れなくなるまで割っていく
			x.push_back(i); //割った個数を配列に足す
			num /= i;
		}
	}
}

vector< int64_t > divisor(int64_t n) {
  vector< int64_t > ret;
  for(int64_t i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      ret.push_back(i);
      if(i * i != n) ret.push_back(n / i);
    }
  }
  sort(begin(ret), end(ret));
  return (ret);
}

int main() {
#if LOCAL&0
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
    ll N;
    cin>>N;
    vector<ll> pf = divisor(N);
    //PrimeFactorization(N,pf);
    //sort(pf.begin(),pf.end(), greater<ll>());
    //sort(pf.begin(),pf.end());
    ll A=1,B=1;
    // for(int i=0;i<pf.size();++i){ //大きい方にかける
    //     if(A>B) B*=pf[i];
    //     else A*=pf[i];
    // }
    auto f=[](ll a,ll b){
        return max<int>(log10(a)+1,log10(b)+1); //桁数を求める
    };
    //int ans=f(A,B);
    int ans=INT32_MAX;
    for(const auto& p:pf){
        A=p;
        B=N/A;
        if(A>B){break;}
        ans=min(f(A,B),ans);
    }
    cout<<ans<<endl;
    return 0;
}