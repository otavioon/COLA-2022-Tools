#include<bits/stdc++.h>
using namespace std;

// #define DEBUG
#define fi first
#define se second
#define be begin
#define en end
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ALL(a) (a).be() , (a).en()
#define REP(i,n) for(int (i)=0;(i)<(n);(i)++)        //repeat n times
#define REP2(i,s,n) for(int (i)=(s);(i)<(n);(i)++)   //repeat from s to n 
#define REPD(i,n) for(int (i)=(n);(i)>=0;(i)--)      //repeat from n to 0
#define REPD2(i,s,e) for(int (i)=(s);(i)>=(e);(i)--) //repeat from s to e
#define RANGE(i,v) for(auto &(i):v)                  //repeat range
#define ASIZE(a) (sizeof(a) / sizeof(a[0]))          //array size

#define EL cout<<endl

using LL = long long;

template<typename T1,typename T2> using P = pair< T1, T2 >;
using Pii = P<int,int>;
using Pdd = P<double,double>;

template<typename T> using V = vector< T >;
using Vi = V<int>;
using Vll = V<LL>;
using Vs = V<string>;

template<typename T1,typename T2> using M = map< T1, T2>;
using Mii = M<int, int>;
using Msi = M<string, int>;

const int MOD = 1000000007;
const int INF = 1999999999;
const LL INFLL = 999999999999999LL;
const double EPS = 1e-10;

const int DX[8]= {-1,0,1,0,-1,-1,1,1};
const int DY[8]= {0,-1,0,1,-1,1,1,-1};

const double PI=3.141592653589793;
//==================================================================
/* I/O */
//scan
void SCAN(int *a){scanf("%d",a);}                             //scan for type int
void SCAN(int *a,int n){REP(i,n){scanf("%d",&a[i]);}}   //scan for type int array
void SCAN(Pii *a){scanf("%d",&a->fi);scanf("%d",&a->se);}     //scan for type pair<int, int>
void SCAN(LL *a){scanf("%lld",a);}                            //scan for type long long int
void SCAN(LL *a,int n){REP(i,n){scanf("%lld",&a[i]);}}  //scan for type long long int array
void SCAN(char *c){scanf(" %c",c);}                           //scan for type char
void SCAN(char *c,int n){REP(i,n){scanf(" %c",&c[i]);}} //scan for type char array

//print 
void PRINT(int a){printf("%d\n",a);}
void PRINT(int *a,int s,char c='\n'){REP(i,s){if(i==s-1){c='\n';}printf("%d%c",a[i],c);}}
void PRINT(Vi a,char c='\n'){REP(i,a.size()){if(i==a.size()-1){c='\n';}printf("%d%c",a[i],c);}}
void PRINT(LL a){printf("%lld\n",a);}
void PRINT(LL *a,int s,char c='\n'){REP(i,s){if(i==s-1){c='\n';}printf("%lld%c",a[i],c);}}
void PRINT(double a){printf("%.15f\n",a);}
void PRINT(double *a,int s,char c='\n'){REP(i,s){if(i==s-1){c='\n';}printf("%f%c",a[i],c);}}
void PRINT(char a){printf("%c\n",a);}
void PRINT(string a){printf("%s\n",a.c_str());}
//==================================================================

//==================================================================
/* vector */
//sort and remove duplicates for type vector
template<typename A>
void UNIQUE(vector< A > &a,int mode=0){
	if(mode==0){ sort(ALL(a),greater< A >());}else{ sort(ALL(a));}
	a.erase(unique(ALL(a)),a.en());
}

//fill an N-dimensional array with val
template<typename A, size_t N, typename T>
void FILL(A (&array)[N], const T &val){fill((T*)array,(T*)(array+N),val);}
//==================================================================

//==================================================================
/* math */
// sign of val
template <typename T> int sgn(T val){return (T(0) < val) - (val < T(0));}

long double pascalTri(int n,int r){
	long double tri[n+1][n+1];
	REP(i,n+1){REP(j,n+1){tri[i][j]=0;}}
	REP(i,n+1){REP(j,n+1){
		if(j>i){break;}
		if(j==0||j==i){tri[i][j]=1;}else{tri[i][j]=(tri[i-1][j-1]+tri[i-1][j]);}
	}}
	return tri[n][r];
}

LL GCD(LL a,LL b){
	LL t; LL r;
	if(a<b){t=a;a=b;b=t;}
	if(b==0){return a;}
	while(a%b!=0){r=a%b;a=b;b=r;}
	return b;
}

LL LCM(LL a,LL b){LL ab=(a*b)%MOD;return ab/GCD(a%b,b);}

//Bipartite method : x^n
LL BMPow(int x,int n,int m=0){
	LL ans=1;LL p=x;
	if(m==0){ while(n>0){if(n&1==1){ans*=p;} p*=p; n>>=1;}}
	else{ while(n>0){if(n&1==1){ans=(ans*p)%m;} p=(p*p)%m ;n>>=1;}}
	return ans;
}

//x^-1=x^(m-2) mod m
LL modInv(LL x,int m){return BMPow(x,m-2,m);}

//x! or x! mod m
LL factorial(int x,int m=0){
	LL a=1;
	if(m==0){REPD2(i,x,1){a*=i;}}else{REPD2(i,x,1){a=(a*i)%m;}}
	return a;
}

P<Vll,Vll> primeFactor(LL n){
	Vll p,e; LL m=n; int c;
	for(LL i=2;i*i<=n;i++){
		if(m%i!=0){continue;}
		c=0;
		while(m%i==0){c++;m/=i;}
		p.pb(i); e.pb(c);
	}
	if(m>1){ p.pb(m); e.pb(1);}
	return mp(p,e);
}


//==================================================================

//==================================================================
/* geometry */
template<typename T> using coordinate = P< T, T >;
template<typename T> using coordinateSet = V<coordinate< T >>;

//centroid of polygon
template<typename T>
coordinate<double> centroidPolygon(coordinateSet<T> &a){
	coordinate<double> G; G.fi=0.; G.se=0.;
	int n = a.size();
	RANGE(i,a){G.fi+=i.fi; G.se+=i.se;}
	G.fi/=n;G.se/=n;
	return G;
}

double area(coordinate<int> a,coordinate<int> b,coordinate<int> c){ 
	return ((b.fi-a.fi)*(c.se-a.se)-(b.se-a.se)*(c.fi-a.fi))/2.;
}

int checkCross(coordinate<int> v1,coordinate<int> v2,coordinate<int> a,coordinate<int> b){
	if(area(a,b,v1)*area(a,b,v2)>=0){return 0;}
	if(area(v1,v2,a)*area(v1,v2,b)>=0){return 0;}
	return 1;
}
//==================================================================

//==================================================================
/* graph */
struct edge{
	int src; int dst; int weight;
	edge() : src(0), dst(0), weight(0) {}
	edge(int s, int d, int w) : src(s), dst(d), weight(w) {}
};

using edges = V<edge>;
using graph = V<edges>;

void add_edge(edges &g,int s, int d, int w=1){g.pb(edge(s,d,w));}
void add_edge(graph &g,int s, int d, int w=1){g[s].pb(edge(s,d,w));}

V<Vi> floyd(const graph &g){
	int i,j,k; int n = g.size();
	V<Vi> dist(n,Vi(n,INF/2));
	REP(i,n){dist[i][i]=0;}
	REP(i,n){for(auto &e:g[i]){dist[e.src][e.dst]=e.weight;}}
	REP(k,n){REP(i,n){REP(j,n){dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);}}}
	return dist;
}

Vi dijkstra(graph &g,int s){
	int i,j,k; int n=g.size(); int visit[n]; Vi dist(n);
	priority_queue<Pii,V<Pii>,greater<Pii>> q;
	REP(i,n){visit[i]=0; dist[i]=INF/2;}
	dist[s]=0;
	q.push(mp(0,s));
	int nv; int min_cost=0;
	while(!q.empty()){
		int d,t; tie(d,t)=q.top(); q.pop();
		if(visit[t]==1){continue;}
		visit[t]=1; dist[t]=d;
		for(auto &e:g[t]){
			if(dist[e.dst]<=d+e.weight){continue;}
			q.push(mp(d+e.weight,e.dst));
		}
	}
	return dist;
}
//==================================================================

//==================================================================
/* data structure */
// binary indexed tree
template<typename T>
struct binaryIndexedTree{
	private:
		int n;
		V<T> x;
	public:
		binaryIndexedTree(int num=0) : n(num), x(n,0){}
		void add(int a, T w){for(int i=a;i<n;i|=i+1){ if(x[i]<w){x[i]=w;}}}
		T maximum(int a){ T m = -1;for(int k=a-1; k>=0;k=(k&(k+1))-1){ m=max(m,x[k]);} return m;}
};

// union find
struct unionFind{
	private:
		Vi data;
	public:
		unionFind(int size) : data(size,-1){}
		bool unionSet(int x,int y){
			x=root(x);y=root(y);
			if(x!=y){
				if(data[y]<data[x]){swap(x,y);}
				data[x]+=data[y]; data[y]=x;
			}
			return x!=y;
		}
		bool findSet(int x,int y){ return root(x)==root(y);}
		int root(int x){return ((data[x]<0)?x:(data[x]=root(data[x])));}
		int size(int x){return -data[root(x)];}
};
//==================================================================

int main(){
	// cin.tie(0);
	// ios::sync_with_stdio(false);
	int a,b;
	SCAN(&a);SCAN(&b);

	if(a==1){a+=13;}
	if(b==1){b+=13;}

	if(a==b){
		PRINT("Draw");
	}else if(a<b){
		PRINT("Bob");
	}else{
		PRINT("Alice");
	}

	return 0;
}