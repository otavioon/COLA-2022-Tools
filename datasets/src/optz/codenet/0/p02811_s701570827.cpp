#include <stdio.h>
#include <algorithm>
#include <assert.h>
#include <cmath>
#include <deque>
#include <iostream>
#include <limits.h>
#include<functional>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <stack>
#include <deque>
#include <tuple>
#include <float.h>
#include<time.h>

#define LL long long
#define pii pair<int,int>
#define pLL pair<LL,LL>
#define mp make_pair
#define mt make_tuple
#define pq priority_queue<LL>
#define pqg priority_queue<LL,vector<LL>,greater<LL>>
#define pb push_back
#define vecLL vector<LL>
#define vecpii vector<pii>
#define vecpLL vector<pLL>
#define vecbL vector<bool>
#define endl "\n"
#define REP(e,v) for(auto e:v)
#define rep(i, a, n) for(LL i = a; i < n;i++)

#define INF LLONG_MAX/2
#define DINF DBL_MAX/2
using namespace std;


/*↓マイライブラリ↓*/

//clock_t start = clock();
//
//clock_t end = clock();
//
//const double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
//printf("time %lf[ms]\n", time);

LL linp(){
	LL x;
	scanf("%lld",&x);
	return x;
}

LL mod(LL i){
	LL mi = i % 1000000007;

	if(mi < 0)
		mi +=  1000000007;

	return mi;
}



LL gcd(LL i,LL j){
	if(j != 0)
		return gcd(j, i % j);
	else
		return i;
}

pLL extgcd(LL a,LL b){//ax+by = 1の解

	pLL ans;

	if(b != 0){
		pLL next = extgcd(b,a%b);
		ans.first = next.second;
		ans.second = next.first-(a/b)*next.second;
	}
	else{
		ans = pLL(1,0);
	}

	return ans;
}


LL division(LL a, LL b,LL m){

	return mod(mod(a) * mod(extgcd(b,m).first));
}

LL numperm_mod(LL x,LL y){
	LL res = 1;
	for(LL i = x; i >= y; i--){
		res = mod(res * mod(i));
	}
	return mod(res);
}

LL numperm(LL x,LL y){
	LL res = 1;
	for(LL i = x; i >= y; i--){
		res *= i;
	}
	return res;
}


LL pow_mod(LL x,LL y){

	x = mod(x);

	if(y == 1){
		return mod(x);
	}
	LL res = mod(pow_mod(mod(x*x),y/2));
	if(y % 2 == 0){
		return res;
	}
	else{
		return mod(x*res);
	}
}

LL pow(LL x,LL y){

	if(y == 1){
		return x;
	}
	if(y % 2 == 0){
		return pow(x*x,y/2);
	}
	else{
		return x*pow(x*x,y/2);
	}
}





 vecLL Eratosthenes(LL n){//素数のベクトルを返す

	 bool isPrime[n];
	 fill(isPrime,isPrime+n,true);

	 isPrime[0] = isPrime[1] = false;
	 rep(i,2,sqrt(n)+1){
		 if(isPrime[i]){
			 for(LL j = 2*i ;j <= n ; j += i){
				 isPrime[j] = false;
			 }
		 }
	 }

	 vecLL P;

	 rep(i,2,n+1){
		 if(isPrime[i]){
			 P.push_back(i);
		 }
	 }

	 return P;
}

 struct edge {//枝
	LL to,cost;
	double dcost;//コストが整数でない場合に使う
} ;


struct vertex{//頂点(枝付き)
	LL key;
	double dkey;//キーが整数でない場合に使う
	vector<edge> edges;//頂点から伸びる枝
};

class Graph{

public:

	LL V;//頂点数
	vertex* vertices;//グラフ


	Graph(LL v){//頂点数を指定してグラフの初期化
		V = v;//頂点数
		vertices = new vertex[V];//頂点集合

		rep(i,0,V){
			vertices[i].key = -1;//キー初期値は-1
			vertices[i].dkey = -1;//キー初期値は-1
		}

	}

	void setDE(LL i,LL j,LL cos){//i→jにコストcosの有向枝を加える

			edge e;
			e.to= j;
			e.cost = cos;

			vertices[i].edges.push_back(e);

			return;
	}

	void setDE(LL i,LL j,double dcos){//i→jにコストcosの有向枝を加える

				edge e;
				e.to= j;
				e.dcost = dcos;

				vertices[i].edges.push_back(e);

				return;
	}

	void setUDE(LL i,LL j,LL cos){//(i,j)にコストcosの無向枝を加える

		edge ei,ej;
		ei.to = j;
		ej.to = i;
		ei.cost = ej.cost = cos;

		vertices[i].edges.push_back(ei);
		vertices[j].edges.push_back(ej);

		return;
	}

	void setUDE(LL i,LL j,double dcos){//(i,j)にコストcosの無向枝を加える

		edge ei,ej;
		ei.to = j;
		ej.to = i;
		ei.dcost = ej.dcost = dcos;

		vertices[i].edges.push_back(ei);
		vertices[j].edges.push_back(ej);

		return;
	}

	void setKey(LL i,LL newKey){//キー変更
		vertices[i].key = newKey;
	}

	void setKey(LL i,double newKey){//キー変更
		vertices[i].key = newKey;
	}

	 edge getEdge(LL i,LL j){

		 rep(a,0,vertices[i].edges.size()){
			 if(vertices[i].edges[a].to == j){
				 return vertices[i].edges[a];
			 }
		 }

		 return (edge){j,INF,DINF};//なければ,コストINFの枝を返す
	}

	void bellman_ford(LL s,LL b[]){
		 fill(b,b+V,INF);

		 b[s] = 0;


		 while(true){

			 bool update = false;
			 rep(i,0,V){
				rep(j,0,vertices[i].edges.size()){
					edge e = vertices[i].edges[j];

					if(b[e.to] > b[i] + e.cost){
						b[e.to] = b[i] + e.cost;
						update = true;
					}

				}
			}
			if(!update)
				break;
		 }

		 return;
	}

	void dijkstra(LL s, LL d[]) {//ダイクストラ(始点を入力とし、各点への最小距離を返す)

	    priority_queue<pLL, vector<pLL>, greater<pLL> > que;

	    fill(d,d+V,INF);
	    d[s] = 0;
	    que.push(pLL(0, s));

	    while (!que.empty()) {
	        pLL p = que.top();
	        que.pop();
	        LL v = p.second;
	        if (d[v] < p.first) continue;

	        rep(i,0, vertices[v].edges.size()) {
	            edge e = vertices[v].edges[i];
	            if (d[e.to] > d[v] + e.cost) {
	                d[e.to] = d[v] + e.cost;
	                que.push(pLL(d[e.to], e.to));
	            }
	        }
	    }

	    return;

	}

	void warshall_floyd(LL **w){

		rep(i,0,V){
					rep(j,0,V){
						w[i][j] = INF;
					}
		}
		rep(i,0,V){
			rep(j,0,vertices[i].edges.size()){
				w[i][vertices[i].edges[j].to] = vertices[i].edges[j].cost;
			}
		}

		rep(i,0,V){
				w[i][i] = 0;
		}

		rep(i,0,V){
			rep(j,0,V){
				rep(k,0,V){
					w[i][j] = min(w[i][j],w[i][k]+w[k][j]);
				}
			}
		}

	}



};

class UF
{
public:
	LL N;
	LL* par;
	LL*  rank;

	UF(LL n){
		 N = n;

		 par = new LL[N];
		 rank = new LL[N];

		 rep(i,0,N){
			 par[i] = i;
			 rank[i] = i;
		 }

		 return;

	}

	LL root(LL x){
		if(x == par[x])
			return x;
		else
			return par[x] = root(par[x]);

	}

	bool same(LL x,LL y){
		return (root(x) == root(y));

	}

	void Union(LL x,LL y){
		LL rtx = root(x);
		LL rty = root(y);

		if(rank[rtx] < rank[rty]){
			par[rtx] = rty;
		}
		else{
			par[rty] = rtx;
			if(rank[rtx] == rank[rty]){
				rank[rtx]++;
			}
		}

	}

};

class ST{


};

/*↑マイライブラリ↑*/

LL ABC_150(char mode){

	if(mode == 'A'){
		LL K,X;

		cin >> K >> X;

		if(X > 500*K)
			cout << "No";
		else
			cout << "Yes";
	}

	/////////////////////////

	if(mode == 'B'){

	}

	/////////////////////////

	if(mode == 'C'){

	}

	/////////////////////////

	if(mode == 'D'){

	}

	/////////////////////////

	if(mode == 'E'){

	}

	/////////////////////////

	if(mode == 'F'){

	}

	return 0;
}

signed main(){
	ABC_150('A');

	return 0;
}
