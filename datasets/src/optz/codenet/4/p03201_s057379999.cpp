#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#include <map>
#include <set>
#include <numeric>
#include <queue>
using namespace std;
#define loop(i,N) for(ll (i)=0; (i)<(N);++(i))
struct TEMP_OMAZINAI_ { TEMP_OMAZINAI_() { std::ios::sync_with_stdio(false); std::cin.tie(0); } } TEMP__omazinai_instance__;
#define INF ((1LL<<61) + (1<<29))
#define YesNo(x) {std::cout << ((x)?"Yes":"No") << std::endl;}
#define YESNO(x) {std::cout << ((x)?"YES":"NO") << std::endl;}
#define OddEven(x) {std::cout << ((x)%2?"Odd":"Even") << std::endl;}
#define ODDEVEN(x) {std::cout << ((x)%2?"ODD":"EVEN") << std::endl;}
typedef long long int ll;
ll my_gcd(ll a, ll b) { return b ? my_gcd(b, a%b) : a; };
void TEMP_INPUT_IMPL_() {};
template <class T, class... Args> void TEMP_INPUT_IMPL_(T& dest, Args&... args) { cin >> dest; TEMP_INPUT_IMPL_(args...); }
void TEMP_OUTPUT_IMPL_() {};
template <class T, class... Args> void TEMP_OUTPUT_IMPL_(T dest, Args... args) { cout << dest << (sizeof...(Args) ? " " : ""); TEMP_OUTPUT_IMPL_(args...); }
#define in(type, ...) type __VA_ARGS__; TEMP_INPUT_IMPL_(__VA_ARGS__)
#define in_v(type, name, cnt) vector<type> name(cnt); loop(i, cnt) cin >> name[i];
#define sort_v(v) std::sort(v.begin(), v.end())
#define rsort_v(v) std::sort(v.rbegin(), v.rend())
#define unique_v(v) v.erase(std::unique(v.begin(), v.end()), v.end()) //必ずソート後に実行
#define out(...) (TEMP_OUTPUT_IMPL_(__VA_ARGS__), std::cout<<std::endl)
#define set_fix(x) ((std::cerr<<std::fixed<<std::setprecision(x)),(std::cout<<std::fixed<<std::setprecision(x)))
//小さい方に寄る
#define space_op(x, y, a, b, c) ([](auto x_, auto y_, auto a_, auto b_, auto c_){if(x_<y_)return a_;if(x_>y_)return c_;return b_;}(x,y,a,b,c))
#define space_out(x, y, a, b, c) out(space_op(x, y, a, b, c))
 
 // ^^^ Template ^^^ //

int main() {
	in(ll, N);
	in_v(ll, A_, N);
	set<ll> A;
	for(ll a : A_) A.insert(a);
	ll ans = 0;
	while(A.size() > 1){
		auto Arb = A.rbegin();
		ll t = 1, ArbV = *Arb;
		//cerr << "A" << endl;
		A.erase((++Arb).base());
		//cerr << "B" << endl;
		while(t <= ArbV) t<<=1;
		auto Alb = A.lower_bound(t-ArbV);
		//cerr << " | " << t-ArbV << "-> " << *Alb << " | " << (Alb!=A.end()) << endl;
		if(Alb != A.end() && *Alb == t-ArbV){
			A.erase(Alb);
			++ans;
		//cerr << "C" << endl;
		}
		//cerr << "D" << endl;
	}
	out(ans);
}

