#include <string>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//typedef pair<long long,long long> P;
//typedef pair<long long,P> P1;
//typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define se second
#define rep(i,x) for(long long i=0;i<x;i++)
#define repn(i,x) for(long long i=1;i<=x;i++)
#define rrep(i,x) for(long long i=x-1;i>=0;i--)
#define rrepn(i,x) for(long long i=x;i>1;i--)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())


#define ALL(v)  (v).begin(),(v).end()
//#define MAX(a,b) if(a>b)
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))


const string MINUSINF = "-";

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
void chmax(string &a, string b) {
    if (a == MINUSINF) a = b;
    else if (a.size() < b.size()) a = b;
    else if (a.size() == b.size()) {
        if (a < b) a = b;
    }
}


template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

#define pr printf
#define re return
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)


int GCD(int a, int b) { return b ? GCD(b, a%b) : a; }

stack<long long> sta;   
queue<long long> que;
deque<long long> dque;

set <string> s_set;



//ll dp[13][100010]={};
//ll dp[100010][3];
string dp[11000];


//最大公約数
int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }

//最小公倍数
int lcm(int x, int y) { return x / gcd(x, y) * y; }

//最大公約数 複数個
int gcd(const vector<int> &v) {
	int ret = v[0];
	for (int i = 1; i < v.size(); i++)
		ret = gcd(ret, v[i]);
	return ret;
}

//最小公倍数 複数個
int lcm(const vector<int> &v) {
	int ret = v[0];
	for (int i = 1; i < v.size(); i++)
		ret = lcm(ret, v[i]);
	return ret;
}

// 素因数分解する 
// たとえば 60 = 2^2 x 3 x 5 だったら {(2, 2), (3, 1), (5, 1)} を返す
vector<pair<long long, long long> > prime_factorize(long long n) {
    vector<pair<long long, long long> > res;
    for (long long p = 2; p * p <= n; ++p) {
        if (n % p != 0) continue;
        int num = 0;
        while (n % p == 0) { ++num; n /= p; }
        res.push_back(make_pair(p, num));
    }
    if (n != 1) res.push_back(make_pair(n, 1));
    return res;
}

// 最大公約数を求める
long long GCD(long long x, long long y) {
    return y ? GCD(y, x%y) : x;
}


struct Student {
  string name;
  int no, point;
};


// a < b ならtrueを返す
bool comp(const Student& a, const Student& b) {
  if (a.name != b.name)
    return a.name < b.name; // 高い順に並べたいので演算子を逆に
  if (a.point != b.point)
    return a.point > b.point; // 同様に比較演算子を反転
  return a.no < b.no;
}


//	文字列置換
std::string replaceOtherStr(std::string &replacedStr, std::string from, std::string to) {
    const unsigned int pos = replacedStr.find(from);
    const int len = from.length();
 
    if (pos == std::string::npos || from.empty()) {
        return replacedStr;
    }
 
    return replacedStr.replace(pos, len, to);
}


//	素因数分解
void countPN(int n, std::vector<int> &count)//nを素因数に分解し、countを更新
{
	int m = n;
	for(int i=2 ; i*i<=n ; ++i)
	{
		while(m%i == 0)
		{
			m /= i;
			count[i]++;
		}
		if(m==1) break;
	}
	if(m!=1) count[m]++;

}

//	コンビネーション
const int MAX_N = 2000000;
ll inv[MAX_N + 10];
ll fac[MAX_N + 10], facInv[MAX_N + 10];
class MATH{
public:
    MATH(){
        inverse();
        factroial();
    }
    ll nCk(ll n, ll k){// n! / k!*(n-k)!
        if(k < 0 || k > n) return 0;
        ll ret = fac[n];
        (ret *= facInv[k]) %= mod;
        (ret *= facInv[n - k]) %= mod;
        return ret;
    }
    ll nHk(ll n, ll k){// nHk = n+k-1 C k = (n+k-1)! / k! * (n-1)!
        if(n == 0 && k == 0) return 1;
        ll ret = fac[n + k - 1];
        (ret *= facInv[k]) %= mod;
        (ret *= facInv[n - 1]) %= mod;
        return ret;
    }
    ll nPk(ll n, ll k){//nPk = n! / (n-k)!
        if(k < 0 || k > n) return 0;
        ll ret = fac[n];
        (ret *= facInv[n - k]) %= mod;
        return ret;
    }
private:
    void inverse(void){
        inv[1] = 1;
        for (int i = 2; i <= MAX_N; ++i){
            // inv[i] = mod - (mod / i) * inv[mod % i] % mod;
            inv[i] = inv[mod % i] * (mod - mod / i) % mod;
        }
    }
    void factroial(void){
        fac[0] = facInv[0] = 1;
        for (int i = 1; i <= MAX_N; ++i){
            fac[i] = (fac[i - 1] * i) % mod;
            facInv[i] = (facInv[i - 1] * inv[i]) % mod;
        }
    }
};

//	いもす法
std::vector<int> getCumSum(std::vector<int> baseImos){
    int baseSize = baseImos.size();
    std::vector<int> cumSum(baseSize, 0);
    
    cumSum[0] = baseImos[0];
    for(int i=1; i<baseSize; ++i){
        cumSum[i] = cumSum[i-1] + baseImos[i];
    }
    return cumSum;
}

typedef vector<int> vi;

//	DFS		(ABC026 A  高橋君の給料)
/*
int dfs(vector<vi> ch, int u){
	if(ch[u].empty()) return 1;
	int mi = INF, ma = 0;
	for(int v : ch[u]){
		int r = dfs(ch, v);
		mi = MIN(mi, r);
		ma = MAX(ma, r);
	}
	return mi + ma + 1;
}
*/

//	DFS		(ABC029 C  Brute-force Attack)
/*
void dfs(int n, string s) {
  if (n == 0) cout << s << endl;
  else {
    dfs(n-1, s + "a");
    dfs(n-1, s + "b");
    dfs(n-1, s + "c");
  }
}
*/

using Edge = pair<int,int>;
using Graph = vector<vector<Edge> >;

vector<int> res;
Graph G;

//	DFS	& 二部グラフ	(ABC126 D  Even Relation 同色の2頂点の長さは偶数)

// v を c に塗る。p は v の親
void dfs(int v, int p, int c) {
    res[v] = c;
    for (auto e : G[v]) {
        if (e.first == p) continue;
        if (e.second & 1) dfs(e.first, v, 1-c);
        else dfs(e.first, v, c);
    }
}

//	DFS	(ABC138 D  Ki)
vector<int> g[200020];
int s[200020];
bool used[200020];

void dfs(int x){
	used[x]=1;
	for(auto y:g[x]){
		if(used[y]) continue;
		s[y]+=s[x];
		dfs(y);
	}
}


long long A,B,C,D,E,F,H,I,J,L,N,M,K,O,P,Q,R,S,T,U,V,W,X,Y,Z;
long long sum,sum1,sum2,sum3,sum4;
long long flg,flg1,flg2,flg3,cnt,cnt1,cnt2,cnt3,cnt4;
long long wk,wk1,wk2,wk3,wk4;
long long ans;

bool f;

long long weight[110], value[110]; // 品物の個数は 100 個なので少し余裕持たせてサイズ 110 に
ll a[100010][3]; // a[i], b[i], c[i] をそれぞれまとめて a[i][0], a[i][1], a[i][2] にしてしまう
long long n,h[100005];
vector<long long> p, c;
int vis[200001];

vector<string> fi;
int Left[2100][2100], Right[2100][2100], Up[2100][2100], Down[2100][2100];

long long match[10] = {2,5,5,4,5,6,3,7,6};




int main(){
	
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	long long max,max1;
	long long min,min1;

	sum=sum1=sum2=sum3=sum4=0;
	flg=flg1=flg2=flg3=cnt=cnt1=cnt2=cnt3=cnt4=0;
	max=max1=0;
	wk=wk1=wk2=wk3=wk4=0;
	ans=0;
	min=min1=INF;

	
	
		
	//**************************ここからスタート******************************************
	//std::cin >> N;
	//std::cin >> N >> M;
	//std::cin >> N >> M >> K;
	//std::cin >> N >> K;
	//std::cin >> A >> B;
	//std::cin >> A >> B >> C;
    
	//std::vector<long long> v(N);
	//std::vector<long long> w(N);
	//std::vector<long long> x(N);
	//std::vector<int> v(100, 0);
	//int a[26]={0};
	//vector<long long> flagment(N, 0);
	
	//vec.push_back(i);
	//accumulate(vec.begin(), vec.end(), 0)
    //v.resize
    
	// 配列入力1
	/*
	for(long long i=0; i<N; i++){
		std::cin >> v[i];
	}
	*/
	
	
	//std::sort(v.begin(),v.end());//昇順ソート
	//std::sort(v.begin(),v.end(),std::greater<long long>());//降順ソート
	
	//通常
	/*
	for(long long i=0; i<N; i++){
		
		
		
	}
	*/
	/*
	if(1){
    	printf("%lld",N);
    	//printf("%lld",N);
    	//puts("Yes");
    	//printf("%d",st.size());
    	//文字列の出力
    	//std::cout << s << std::endl;
    	//printf("%.12f\n",ret);
    	//cout << sum << endl;
	}
	else{
		//puts("No");
	}
	return 0;
	*/

	//文字列入力
	
	string s,t;
	std::cin >> t;
	std::cin >> K;
	s=t;
	
	t+=t;
	
	ll k;
	k=0;
	for(long long i=0; i<s.length()-1; i++){
		
		if(s[i]==s[i+1]){
			cnt++;
			i++;
			if(i==s.length()-2 && s[i]==s[0]){
				flg=1;
			}
		}
	}
	for(long long i=0; i<t.length()-1; i++){
		
		if(t[i]==t[i+1]){
			cnt1++;
			i++;
		}
	}
	
	if(K==1){
		printf("%lld",cnt);
	}
	else if(flg==0){
		printf("%lld",(cnt1-cnt)*K);
	}
	else{
		sum=cnt;
		for(long long i=1; i<K; i++){
			if(i%2==1){
				sum+=(cnt1-cnt);
			}
			else{
				sum+=(cnt1-cnt)-1;
			}
				
		}
		printf("%lld",sum);
	}
   
	//printf("%lld",cnt);
	re 0;
}
