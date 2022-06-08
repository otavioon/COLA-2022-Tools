#include<iostream>
#include<vector>
#include<sstream>
#include<string>
#include<numeric>
#include <algorithm>
#include<math.h>
#include<cstdio>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>




using namespace std;
typedef long long ll;
struct point{
  int x;
  int y;

};
int gcd( int m, int n )
{
	// 引数に０がある場合は０を返す
	if ( ( 0 == m ) || ( 0 == n ) )
		return 0;
	
	// ユークリッドの方法
	while( m != n )
	{
		if ( m > n ) m = m - n;
		else         n = n - m;
	}
	return m;
}//gcd
int lcm( int m, int n )
{
	// 引数に０がある場合は０を返す
	if ( ( 0 == m ) || ( 0 == n ) )
		return 0;
	
	return ((m / gcd(m, n)) * n); // lcm = m * n / gcd(m,n)
}//lcm
int input(){
  int x;
  cin>>x;
  return x;
}

int moji(char in)
{
    int ans = (int)in-(int)'a';
    if((ans < 0) || (ans > 25)){
        ans = 26;
    }
    return ans;
}
const int VV=10;//場合に応じてVVの値のみ変更する必要あり
//dijkstra(s)sがスタート地点でそこからの最短距離を配列dで表す。正の重みのみ使用可能
int cost[VV][VV];
int d[VV];
bool used[VV];
void dijkstra(int s){
  fill(d,d+VV,100000);
  fill(used,used+VV,false);
  d[s]=0;
  while(true){
    int v=-1;
    for(int u=0;u<VV;u++){
      if(!used[u]&&(v==-1||d[u]<d[v]))v=u;
    }
    if(v==-1)break;
    used[v]=true;
    for(int u=0;u<VV;u++){
      d[u]=min(d[u],d[v]+cost[v][u]);
    }
  }

}

int compare_int(const void *a, const void *b)//qsort(quick sort利用時に使用)
{
    return *(int*)a - *(int*)b;
}





int main(){
  int N;
  cin>>N;
  vector<long long>A;
  for(int i=0;i<N;i++){
    int x;
    cin>>x;
    A.push_back(x);
  }
  long long S[]={1, 2, 4, 8, 16, 32, 64, 128, 256, 512,
1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288,
1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912,
1073741824, 2147483648, 4294967296, 8589934592};

sort(A.begin(),A.end());
vector<long long>B;

for(int i=0;i<N;i++){
  for(int j=0;j<33;j++){
    if(A.at(i)<=S[j]){
      B.push_back(S[j]-A.at(i));
      break;
    }

  }
}
sort(B.begin(),B.end());
long long sum=0;
int tmp=-1;
for(int i=0;i<N;i++){
  bool t=binary_search(B.begin(),B.end(),A[i]);
  if(t){
      sum++;
      std::vector<long long>::iterator it =std::find(B.begin(),B.end(), A.at(i));
      int index =distance(B.begin(),it);
      B.at(index)=0;
    
  }

}
cout<<sum<<endl;


  


  

  



}


  
  

  


  
