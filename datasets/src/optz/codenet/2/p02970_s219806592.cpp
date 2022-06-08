#include <bits/stdc++.h>
using namespace std;
// #include <bits/stdtr1c++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

/// Typedef
typedef long long           ll;
typedef unsigned long       ul;
typedef unsigned long long  ull;
typedef vector<int>         vi;
typedef vector<vi>          vvi;
typedef vector<ll>          vl;
typedef vector<vl>          vvl;
typedef pair<int,int>       pii;
typedef pair<ll,ll>         pll;
typedef vector< pii >       vii;
typedef vector< pll >       vll;


#define pb                  push_back
#define ppb                 pop_back
#define mp                  make_pair
#define ff                  first
#define ss                  second
#define sf                  scanf
#define pf                  printf
#define itr                 iterator
#define SQR(x)              ((x)*(x))
#define loop(i, y)          for(int i=0; i<int(y); i++)
#define FOR(i, x, y)        for(int i=int(x); i<=int(y); i++)
#define ROF(i, y, x)        for(int i=int(y-1); i>=int(x); i--)
#define ALL(c)              c.begin(), c.end()
#define SZ(c)               int(c.size())
#define CLR(x, y)           memset(x, y, sizeof(x))
#define READ(f)             freopen(f, "r", stdin)
#define WRITE(f)            freopen(f, "w", stdout)
#define si(x)               scanf("%d", &x)
#define sii(x, y)           scanf("%d %d", &x, &y)
#define siii(x, y, z)       scanf("%d %d %d", &x, &y, &z)
#define sl(x)               scanf("%lld", &x)
#define sll(x, y)           scanf("%lld %lld", &x, &y)
#define slll(x, y, z)       scanf("%lld %lld %lld", &x, &y, &z)
#define FileIO              freopen("input.txt", "r", stdin);   freopen("output.txt", "w", stdout);
#define FastIO              ios::sync_with_stdio(false);cin.tie(0);
#define FixedPrecision(x)   ios::sync_with_stdio(false); cout.setf(ios::fixed); cout.precision(x); cin.tie(0);
#define bitCheck(N,in)      ((bool)(N&(1LL<<(in))))
#define bitOff(N,in)        (N&(~(1LL<<(in))))
#define bitOn(N,in)         (N|(1LL<<(in)))
#define bitFlip(a,k)        (a^(1LL<<(k)))
#define start_time          clock_t tStart = clock();
#define execution_time      printf("\n>>Time taken: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#define popCount(x)         __builtin_popcount(x)
#define int2Bin(x, y)       bitset<y> z=x; cout<<z.to_string()<<endl;
#define tr(it, container)   for(auto it = container.begin(); it != container.end(); it++)
#define unq(v)              (v).erase(unique(ALL(v)),v.end())
#define common(a,b)         sort(ALL(a)), sort(ALL(b)), a.erase(set_intersection(ALL(a),ALL(b),a.begin()),a.end())
#define uncommon(a,b)       sort(ALL(a)), sort(ALL(b)), a.erase(set_symmetric_difference(ALL(a),ALL(b),a.begin()),a.end())
#define DB(x)               cout << #x << " = " << x << endl
#define DDB(x,y)            cout << #x << " = " << x << "   " << #y << " = " << y << endl
#define DDDB(x,y,z)         cout << #x << " = " << x << "   " << #y << " = " << y << "   " << #z << " = " << z << endl
/// template <typename T> using orderset = tree <T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
/// *X.find_by_order(k) //returns the kth largest element.(0-based)
/// X.order_of_key(val) //returns the no. of values less than val

/// uniform random generator -->
/// uniform_int_distribution<int> dist(0, 1);
/// default_random_engine gen;

template <class T> inline T bigMod(T p,T e,T M){ ll ret = 1; for(; e > 0; e >>= 1){ if(e & 1) ret = (ret * p) % M; p = (p * p) % M; } return (T) ret;}
template <class T> inline T modInverse(T a,T M){return bigMod(a,M-2,M);}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T lcm(T a,T b) {a=abs(a);b=abs(b); return (a/gcd(a,b))*b;}
template <class T> inline T diss(T x1,T x2,T y1 , T y2) {return sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)));}
template <class T> inline string int2String(T a){ostringstream str; str<<a; return str.str();}
template <class T> inline T string2int(string a){stringstream str(a); T b; str>>b; return b;}
const int dr[] = { 0,  1,  0, -1,   -1,  1,  1, -1,   -2, -2,  2,  2, -1, -1,  1,  1};
const int dc[] = { 1,  0, -1,  0,    1,  1, -1, -1,   -1,  1, -1,  1, -2,  2, -2,  2};

/// Constants
#define MAX                 200005
#define MOD                 1000000009
#define BASE                1000000007
#define eps                 1e-9
#define INF                 1llu<<61    // 2,305,843,009,213,693,952
#define inf                 1<<29       // 536,870,912
#define PI                  acos(-1.0)  // 3.1415926535897932
//#define e                   2.71828182845904523536




bool sortbysec(const pair<ll,ll> &a, const pair<ll,ll> &b) {return (a.second < b.second);}


int dig_cnt (long long n){return ((int)(log10(n))+1 );}



long long floorSqrt(long long x)
{
    if (x == 0 || x == 1)  return x;
    long long start = 1, end = x, ans;
    while (start <= end)
    {
        long long mid = (start + end) / 2;
        if (mid*mid == x) return mid;
        if (mid*mid < x)   { start = mid + 1; ans = mid; }
        else end = mid-1;
    }
    return ans;
}


bool is_prime(long long n)
{

    if (n==1)return false;
    for(long long i = 2 ; (i*i) <= n ; i++)if(n%i==0)return false;
        return true;
}

long long factorials(int n)
{
    if(!n)return 1;
    return n*factorials(n-1);
}

long long dig_sum(ll x)
{
    long long sm = 0 ;
    while(x)
    {
        sm+=(x%10);
        x/=10;
    }
    return sm;
}









////            BackTrack                               ////             ALL POSSIBLE                          /////



void subsetsUtil(vector<int>& A, vector<vector<int> >& res, 
                 vector<int>& subset, int index) 
{ 
    res.push_back(subset); 
    for (int i = index; i < A.size(); i++) { 
  
        // include the A[i] in subset. 
        subset.push_back(A[i]); 
  
        // move onto the next element. 
        subsetsUtil(A, res, subset, i + 1); 
  
        // exclude the A[i] from subset and triggers 
        // backtracking. 
        subset.pop_back(); 
    } 
  
    return; 
} 
  
// below function returns the subsets of vector A. 
vector<vector<int> > subsets(vector<int>& A) 
{ 
    vector<int> subset; 
    vector<vector<int> > res; 
  
    // keeps track of current element in vector A; 
    int index = 0; 
    subsetsUtil(A, res, subset, index); 
  
    return res; 
}

////            BackTrack                               ////             ALL POSSIBLE                          /////



long long hexadecimalToDecimal(string hexVal) 
{    
    int len = hexVal.size(); 
      
    // Initializing base value to 1, i.e 16^0 
    long long base = 1; 
      
    long long dec_val = 0; 
      
    // Extracting characters as digits from last character 
    for (int i=len-1; i>=0; i--) 
    {    
        // if character lies in '0'-'9', converting  
        // it to integral 0-9 by subtracting 48 from 
        // ASCII value. 
        if (hexVal[i]>='0' && hexVal[i]<='9') 
        { 
            dec_val += (hexVal[i] - 48)*base; 
                  
            // incrementing base by power 
            base = base * 16; 
        } 
  
        // if character lies in 'A'-'F' , converting  
        // it to integral 10 - 15 by subtracting 55  
        // from ASCII value 
        else if (hexVal[i]>='A' && hexVal[i]<='F') 
        { 
            dec_val += (hexVal[i] - 55)*base; 
          
            // incrementing base by power 
            base = base*16; 
        } 
    } 
      
    return dec_val; 
} 



long long octalToDecimal(long long n) 
{ 

    long long num = n; 
    long long dec_value = 0; 
  
    // Initializing base value to 1, i.e 8^0 
    long long base = 1; 
  
    long long int temp = num; 
    while (temp) { 
  
        // Extracting last digit 
        int last_digit = temp % 10; 
        temp = (long long int)(temp / 10); 
  
        // Multiplying last digit with appropriate 
        // base value and adding it to dec_value 
        dec_value += last_digit * base; 
  
        base = base * 8; 
    } 
    return dec_value; 
} 







int main()
{

    

    ll n , d ; sll(n,d);

    ll ans = (d*2)+1;

    ll fn = (long long int)(n/ans);
    if((n%ans))fn++;

    pf("%lld\n",fn);


    

   


    return 0;
}






