#include<bits/stdc++.h>
using namespace std;
 
#define REP(i,n) for(int (i)=0;(i)<(n);(i)++)      //repeat n times
#define REP2(i,s,n) for(int (i)=(s);(i)<(n);(i)++) //repeat from s to n 
#define REPD(i,n) for(int (i)=(n);(i)>=0;(i)--)    //repeat from n to 0
#define ASIZE(a) (sizeof(a) / sizeof(a[0]))        //array size
#define SORTD(a) sort(a,a+ASIZE(a),greater<int>()) //sort in descending order for array
#define SORTA(a) sort(a,a+ASIZE(a))                //sort in ascending order for array
#define SORTS(a) sort(a.begin(),a.end())           //sort in ascending order for string type
typedef long long ll;
 
void SCAN(int *a){scanf("%d",a);}                             //scan for type int
void SCAN(int *a,int n){int i;REP(i,n){scanf("%d",&a[i]);}}   //scan for type int array
void SCAN(char *c){scanf(" %c",c);}                           //scan for type char
void SCAN(char *c,int n){int i;REP(i,n){scanf(" %c",&c[i]);}} //scan for type char array
 
const int MOD = 1000000007;
const int INF = 1000000000;
 
int pascalTri(int n,int r){
	int tri[n+1][n+1];
	int i,j;
	REP(i,n+1){REP(j,n+1){tri[i][j]=0;}}
	REP(i,n+1){
		REP(j,n+1){
			if(j>i){break;}
			if(j==0||j==i){tri[i][j]=1;}else{tri[i][j]=(tri[i-1][j-1]%MOD+tri[i-1][j]%MOD)%MOD;}
		}
	}
	return tri[n][r];
}
 
const int DX4[4]= {-1,0,0,1};
const int DY4[4]= {0,-1,1,0};
 
int main(){
	int n;
	int i,j,k;
 
	SCAN(&n);
	int a[n],b[n],c[n];
	SCAN(a,n);SCAN(b,n);SCAN(c,n);
	int cnt=0;
	REP(i,n){
		REP(j,n){
			if(a[i]>b[j]){continue;}
			REP(k,n){
				if(b[j]>b[k]){continue;}
				cnt++;
			}
		}
	}
 
	printf("%d\n",cnt);
	
 
	return 0;
}