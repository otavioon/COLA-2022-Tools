#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>Set;
typedef tree<int,int,less<int>,rb_tree_tag,tree_order_statistics_node_update> Map;

#define ipow(a,b)+0.5 (int)pow(a,b)
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define fi first
#define se second
#define pll pair<ll,ll>
#define ook order_of_key
#define findby find_by_order
#define pii pair<int,int>

#define rep(i,n) for(int i=0;i<n;i++)
#define reps(i,a,b) for(int i=a;i<=b;i++)

template<typename X> inline X abs(const X& a) { return (a < 0 ? -a : a); }
template<typename X> inline X sqr(const X& a) { return (a * a); }

const ld EPS = ld(1e-9);
const ld PI = ld(3.141592653589);
ll n;
vector<pii>a;
set<int>check;
class Task
{
public:
    void solve(istream& in,ostream& out)
    {
          in>>n;
          factors();
          cnt();

          out<<*check.begin()<<endl;
    }

    void factors()
    {
          for(ll i=1;i<=(ll)sqrt(n);i++)
          {
               if(n%i==0)
               {
                    a.pb(mp(i,n/i));
               }
          }
    }

    void cnt()
    {
          rep(i,a.size())
          {
               ll b=a[i].fi;
               ll c=a[i].se;

               string B=to_string(b);
               string C=to_string(c);

               check.insert(max(B.length(),C.length()));
          }
    }
};


int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Task solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in,out);
	out.flush();

    return 0;
}



