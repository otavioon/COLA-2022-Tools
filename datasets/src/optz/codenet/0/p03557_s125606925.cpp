#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <bitset>     //UWAGA - w czasie kompilacji musi byc znany rozmiar wektora - nie mozna go zmienic
#include <cassert>
#include <iomanip>        //do setprecision
#include <ctime>
#include <complex>
using namespace std;

#define FOR(i,b,e) for(int i=(b);i<(e);++i)
#define FORQ(i,b,e) for(int i=(b);i<=(e);++i)
#define FORD(i,b,e) for(int i=(b)-1;i>=(e);--i)
#define REP(x, n) for(int x = 0; x < (n); ++x)

#define ST first
#define ND second
#define PB push_back
#define MP make_pair
#define LL long long
#define ULL unsigned LL
#define LD long double

const double pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342;
const int mod=1000000007;

int main(){
	int n,a[4][100001];
	int i,j,k,l,m;
	scanf("%d",&n);
	FORQ(j,1,3)FOR(i,0,n){
		scanf("%d",a[j]+i);
		//cin>>a[j][i];
	}
	int count=0,x,y,z;
	FORQ(j,1,3)sort(a[j],a[j]+n);
	int rem=n,remy=n;
	FORD(i,n,0){
		x=a[1][i];
		//FOR(j,0,n){
			int r=n,l=0,m;
			while(l<=r){
				m=(l+r)/2;
				if(a[2][m]==x)break;
				else if(a[2][m]<x){
					l=m+1;
				}else{
					r=m-1;
				}
			}
			if(l>r)m=r;
			while(a[2][m]<=x)m++;
			rem=m;
		FOR(j,rem,n){
			y=a[2][j];
			{
				
				r=n;l=0;
			while(l<=r){
				m=(l+r)/2;
				if(a[3][m]==y)break;
				else if(a[3][m]<y){
					l=m+1;
				}else{
					r=m-1;
				}
			}
				if(l>r)m=r;
			if(m<=n)while(a[3][m]<=y)m++;
				remy=m;
				/*FOR(k,0,n){
					
					z=a[3][k];
					if(z<=y)count--;
					else break;
				}*/
				count+=n-m;
				//cout<<x<<","<<y<<"k:"<<m<<" "<<a[3][m]<<endl;
			}
		}
	}
	cout<<count<<endl;
    return 0;
}