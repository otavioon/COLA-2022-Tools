#define _CRT_SECURE_NO_WARNINGS
#define MATH_PI 3.14159265358979323846264338327950288419716939
#define MOD9 1000000007
#define INF 2147483647
#define INF_LLI 9223372036854775807
#define lli long long int
#include <iostream>
#include <string.h>
#include <fstream>
#include <math.h>
#include <iomanip>

using namespace std;

#ifdef _WIN32
#pragma warning(disable : 4101)


signed wait(){
	char wait_dummy[256];
	scanf("%c", &wait_dummy);
	return 0;
}


template <typename ... Args>
void dout(const char *format, Args const & ... args){
	printf(format, args ...);
}

#define MAX_CHARBUF	65536
#define DATAFILE "data.dat"

class csLocalInput{
	int FileOpen();
public:
	FILE *fp;
	csLocalInput();
};


csLocalInput::csLocalInput() {
	FileOpen();
}

int csLocalInput::FileOpen() {
	fp = fopen(DATAFILE, "rt");
	return 1;
}

csLocalInput local_in;


void COMinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX; i++){
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}


long long COM(int n, int k){
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
	
	COMinit();

	
	cout << COM(100000, 50000) << endl;
}







#define NodeType int
#define ValueType int
typedef class csNode NODE;
typedef class csPath PATH;
typedef class csEdge EDGE;
class csPath{
public:
	NodeType To;
	ValueType Dist;
	PATH *prev, *next;
};
class csEdge{
public:
	NodeType f, t;
	ValueType d;
};
class csNode{
	PATH *path_tmp;
	int finished;
public:
	csNode(){
		nPath = 0;
	}

	PATH *path_head, *path_tail;
	int nPath;

	inline void Add(NodeType to, ValueType d);
	inline PATH *GetFirstPath(){
		if(nPath == 0) return NULL;
		finished = 0;
		path_tmp = path_head;
		return path_tmp;
	};
	inline PATH *GetNextPath(){
		if(finished) return NULL;
		path_tmp = path_tmp->next;
		if(path_tmp == path_tail) finished = 1;
		return path_tmp;
	}
};

class csTree{
public:
	csTree(){
		nPathPool = 0;
	}

	void Make();

	PATH PathPool[100010*2];
	int nPathPool;
	inline PATH *Get(){
		PATH *ret = &PathPool[nPathPool++];
		ret->prev = ret->next = NULL;
		ret->To = -1;
		return ret;
	}
	int nNode;
	NODE Node[100010];
	int nEdge;
	EDGE Edge[100010];
};
csTree Tree;

inline void csNode::Add(NodeType to, ValueType d){
	PATH *p = Tree.Get();
	p->To = to;
	p->Dist = d;
	if(nPath == 0){
		path_head = path_tail = p;
	}
	else{
		path_tail->next = p;
		p->prev = path_tail;
		path_tail = p;
	}
	++nPath;
}

inline void csTree::Make(){
	csEdge *p;
	NodeType f, t;
	ValueType d;
	fi(nEdge){
		f = Edge[i].f;
		t = Edge[i].t;
		d = Edge[i].d;
		Node[f].Add(t, d);
		Node[t].Add(f, d);
	}

}



lli dist[100010];
int from[100010];
int stack[100010];
int nstack;

	
	int p = k;　
	dist[p] = 0;
	stack[0] = p;
	nstack = 1;
	from[p] = -1;
	PATH *pp;
	while(true){
		if(nstack == 0) break;
		p = stack[--nstack];
		pp = Tree.Node[p].GetFirstPath();
		while(true){
			if(!pp) break;
			if(pp->To == from[p]){
				pp = Tree.Node[p].GetNextPath();
				continue;
			}
			stack[nstack++] = pp->To;
			dist[pp->To] = dist[p] + (lli)pp->Dist;
			from[pp->To] = p;
			pp = Tree.Node[p].GetNextPath();
		}
	}



#include <algorithm>
#include <functional>

#include <iostream>


void foreach_permutation(int n, std::function<void(int *)> f) {
  int indexes[n];
  for (int i = 0; i < n; i++) indexes[i] = i;
  do {
	f(indexes);
  } while (std::next_permutation(indexes, indexes + n));
}

int main() {
  foreach_permutation(3, [](int *indexes) {
	std::cout << indexes[0] << ',' << indexes[1] << ',' << indexes[2] << std::endl;
  });
}


#include <functional>

#include <iostream>

void recursive_comb(int *indexes, int s, int rest, std::function<void(int *)> f) {
  if (rest == 0) {
	f(indexes);
  } else {
	if (s < 0) return;
	recursive_comb(indexes, s - 1, rest, f);
	indexes[rest - 1] = s;
	recursive_comb(indexes, s - 1, rest - 1, f);
  }
}


void foreach_comb(int n, int k, std::function<void(int *)> f) {
  int indexes[k];
  recursive_comb(indexes, n - 1, k, f);
}

int main() {
  foreach_comb(5, 3, [](int *indexes) {
	std::cout << indexes[0] << ',' << indexes[1] << ',' << indexes[2] << std::endl;
  });
}

*/
#define DEBUG	1
#else
inline signed wait() { return 0; }
inline void dout(const char *arg, ...) {}
#endif

template<typename T>inline void SWAP(T &a, T &b) { T t = a; a = b; b = t; }
inline void CSWAP(char *&a, char *&b) { char *t = a; a = b; b = t; }

int _ret;

#define CLIP(ptr, min, max) {if((min)<=(max)){if(ptr<(min)){ptr=(min);}if(ptr>(max)){ptr=(max);}}}


#define Sin(deg) sin((deg)*MATH_PI/180.0)
#define Cos(deg) cos((deg)*MATH_PI/180.0)
#define Tan(deg) tan((deg)*MATH_PI/180.0)
#define Rad(deg) ((deg)*MATH_PI/180.0)
#define rep(param, num) for(int param=0 ; param<num ; ++param)
#define fi(num) for(int i=0 ; i<num ; ++i)
#define fj(num) for(int j=0 ; j<num ; ++j)
#define fk(num) for(int k=0 ; k<num ; ++k)
#define fl(num) for(int l=0 ; l<num ; ++l)
#define fn(num) for(int n=0 ; n<num ; ++n)
#define ffr(param, num) for(int param=num-1 ; param>=0 ; --param)
#define fir(num) for(int i=num-1 ; i>=0 ; --i)
#define fjr(num) for(int j=num-1 ; j>=0 ; --j)
#define fkr(num) for(int k=num-1 ; k>=0 ; --k)
#define flr(num) for(int l=num-1 ; l>=0 ; --l)
#define fnr(num) for(int n=num-1 ; n>=0 ; --n)
#define gi(p) int p; Gi(p)
#define gi2(p1, p2) int p1, p2; Gi2(p1, p2)
#define gi3(p1, p2, p3) int p1, p2, p3; Gi3(p1, p2, p3)
#define gi4(p1, p2, p3, p4) int p1, p2, p3, p4; Gi4(p1, p2, p3, p4)
#define glli(p) lli p; Glli(p)
#define glli2(p1, p2) lli p1, p2; Glli2(p1, p2)
#define glli3(p1, p2, p3) lli p1, p2, p3; Glli3(p1, p2, p3)
#define glli4(p1, p2, p3, p4) lli p1, p2, p3, p4; Glli4(p1, p2, p3, p4)
#define gf(p) double p; Gf(p);
#define gf2(p1, p2) double p1, p2; Gf2(p1, p2);
#define gf3(p1, p2, p3) double p1, p2, p3; Gf3(p1, p2, p3);
#define gf4(p1, p2, p3, p4) double p1, p2, p3, p4; Gf4(p1, p2, p3, p4)

#define Gi(p) _ret = Scanf("%d", p)
#define Gi2(p1, p2) _ret = Scanf2("%d %d", p1, p2)
#define Gi3(p1, p2, p3) _ret = Scanf3("%d %d %d", p1, p2, p3)
#define Gi4(p1, p2, p3, p4) _ret = Scanf4("%d %d %d %d", p1, p2, p3, p4)
#define Glli(p) _ret = Scanf("%lld", p)
#define Glli2(p1, p2) _ret = Scanf2("%lld %lld", p1, p2)
#define Glli3(p1, p2, p3) _ret = Scanf3("%lld %lld %lld", p1, p2, p3)
#define Glli4(p1, p2, p3, p4) _ret = Scanf4("%lld %lld %lld %lld", p1, p2, p3, p4)
#define Gf(p) _ret = Scanf("%f", p)
#define Gf2(p1, p2) _ret = Scanf2("%f %f", p1, p2)
#define Gf3(p1, p2, p3) _ret = Scanf3("%f %f %f", p1, p2, p3)
#define Gf4(p1, p2, p3, p4) _ret = Scanf4("%f %f %f %f", p1, p2, p3, p4)

#ifdef DEBUG
#define Gc(buf) _ret = fscanf(local_in.fp, "%s", buf)
#define Scanf(expr, p) _ret = fscanf(local_in.fp, expr, &p)
#define Scanf2(expr, p1, p2) _ret = fscanf(local_in.fp, expr, &p1, &p2)
#define Scanf3(expr, p1, p2, p3) _ret = fscanf(local_in.fp, expr, &p1, &p2, &p3)
#define Scanf4(expr, p1, p2, p3, p4) _ret = fscanf(local_in.fp, expr, &p1, &p2, &p3, &p4)
#else
#define Gc(buf) Scanf("%s", buf)
#define Scanf(expr, p) _ret = scanf(expr, &p)
#define Scanf2(expr, p1, p2) _ret = scanf(expr, &p1, &p2)
#define Scanf3(expr, p1, p2, p3) _ret = scanf(expr, &p1, &p2, &p3)
#define Scanf4(expr, p1, p2, p3, p4) _ret = scanf(expr, &p1, &p2, &p3, &p4)
#endif
#define ans(p) cout << p << endl;
#define ans_end(p) {cout << p << endl; return wait();}
void CombSort(int N, int *ar, int order_ascending) { if (N <= 1) return; int h = int(N / 1.3); int flag; int i; while (true) { flag = 0; for (i = 0; i + h < N; ++i) { if ((order_ascending&&ar[i] > ar[i + h]) || (!order_ascending&&ar[i] < ar[i + h])) { swap<int>(ar[i], ar[i + h]); flag = 1; } }if (h == 1 && !flag)break; if (h == 9 || h == 10) h = 11; if (h > 1)h = int(h / 1.3); } }
void CombSort_ll(int N, lli *ar, int order_ascending) { if (N <= 1) return; int h = int(N / 1.3); int flag; int i; while (true) { flag = 0; for (i = 0; i + h < N; ++i) { if ((order_ascending&&ar[i] > ar[i + h]) || (!order_ascending&&ar[i] < ar[i + h])) { swap<lli>(ar[i], ar[i + h]); flag = 1; } }if (h == 1 && !flag)break; if (h == 9 || h == 10) h = 11; if (h > 1)h = int(h / 1.3); } }

int EuclideanAlgorithm(int N, int *ar){
	fn(N - 1){
		while (true){ 
			if(ar[n] == 0 || ar[n+1] == 0){
				if(ar[n] < ar[n+1]) ar[n] = ar[n+1];
				ar[n+1] = ar[n];
				break;
			}
			if (ar[n] % ar[n + 1] == 0 || ar[n + 1] % ar[n] == 0) {
				ar[n + 1] = ar[n] < ar[n + 1] ? ar[n] : ar[n + 1];
				break; 
			}
			if (ar[n] > ar[n + 1]) {
				ar[n] %= ar[n + 1];
			} 
			else { 
				ar[n + 1] %= ar[n]; 
			} 
		} 
	}
	return ar[N - 1];
}
int Euclid(int n, int *ar){
	return EuclideanAlgorithm(n, ar);
}
lli EuclideanAlgorithm_lli(int N, lli *ar) {
	fn(N - 1) {
		while (true) {
			if (ar[n] == 0 || ar[n + 1] == 0) {
				if (ar[n] < ar[n + 1]) ar[n] = ar[n + 1];
				ar[n + 1] = ar[n];
				break;
			}
			if (ar[n] % ar[n + 1] == 0 || ar[n + 1] % ar[n] == 0) {
				ar[n + 1] = ar[n] < ar[n + 1] ? ar[n] : ar[n + 1];
				break;
			}
			if (ar[n] > ar[n + 1]) {
				ar[n] %= ar[n + 1];
			}
			else {
				ar[n + 1] %= ar[n];
			}
		}
	}
	return ar[N - 1];
}
lli Euclid_lli(int n, lli *ar) {
	return EuclideanAlgorithm_lli(n, ar);
}
int EuclideanAlgorithmPreserved(int N, int *ar) {
	int a, b;
	a = ar[0];
	fn(N - 1) {
		b = ar[n + 1];
		while (true) {
			if(a == 0 || b == 0){
				if(a < b) a = b;
				b = a;
				break;
			}
			if (a % b == 0 || b % a == 0) {
				b = a < b ? a : b;
				break;
			}
			if (a > b) {
				a %= b;
			}
			else {
				b %= a;
			}
		}
		a = b;
	}
	return a;
}
int Euclid2(int n, int *ar) {
	return EuclideanAlgorithmPreserved(n, ar);
}

template<typename T>void CombSort(int N, T *ar, int order_ascending) {
	if (N <= 1) return;
	int i, flag;
	int h = int(N / 1.3);
	while (true) {
		flag = 0;
		for (i = 0; i + h < N; ++i) {
			if (
				order_ascending && ar[i].SortValue > ar[i + h].SortValue ||
				!order_ascending && ar[i].SortValue < ar[i + h].SortValue
				) {
				SWAP<T>(ar[i], ar[i + h]);
				flag = 1;
			}
		}
		if (h > 1) {
			h = int(h / 1.3);
			if (h == 9 || h == 10) h = 11;
		}
		else {
			if (!flag) break;
		}
	}
}
#include <vector>
#include <algorithm>

struct UnionFind {
	vector<int> par; 

	UnionFind(int N) : par(N) { 
		for (int i = 0; i < N; i++) par[i] = i;
	}

	int root(int x) { 
		if (par[x] == x) return x;
		return par[x] = root(par[x]);
	}

	void unite(int x, int y) { 
		int rx = root(x); 
		int ry = root(y); 
		if (rx == ry) return; 
		par[rx] = ry; 
	}

	bool same(int x, int y) { 
		int rx = root(x);
		int ry = root(y);
		return rx == ry;
	}
};


void Replace(char *c, int len, char before, char after) {
	fi(len){
		if(c[i] == before) c[i] = after;
	}
}
void Replace(char *c, char before, char after){
	int len = strlen(c);
	Replace(c, len, before, after);
}

class csStack{
public:
	csStack(){
		num = 0;
	}
	void alloc(int size){
		param = new int[size];
	}
	void sort(int order = 1){
		if(num > 1) CombSort(num, param, order);
	}

	int num;
	int *param;

	void push(int p){
		param[num++] = p;
	}
};

class csPosition{
public:
	csPosition(){x = y = 0;}
	int x, y;
};
typedef class csPosition POS;

template<typename T>
class csPos{
public:
	csPos(){x = y = 0;}
	T x, y;
};


char s[200010];



signed main() {

	char a[4], b[4];
	Gc(a);
	Gc(b);

	if(a[0] == b[2] && a[1] == b[1] && a[2] == b[0]){
		ans("YES");
	}else{
		ans("NO");
	}



	return wait();
}

