#include<bits/stdc++.h>
#define int long long int 
#define hell 1000000007 
#define F first
#define re 15000000
#define S second
#define pb push_back
#define aint(a)  (a).begin(),(a).end()
#define rep(i,a,b) for(int int i = a;i<b;i++)
#define pi 3.1415926536
#define Mod 998244353
#define endl '\n'
  //char a[2000][2000];
  using namespace std;
  int sum (int a)
  {
      int sum =0;
      while(a>0)
      {
          sum = sum + (a%10);
          a=a/10;
      }
      return sum;
  }
  int count_digit(int n)
  {
     int  count =0;
      while(n>0)
      {
          n = n/10;
          count++;
          //count++;
      }
      return count;
  }
  int binarySearch(int x,int y ,int z ,int v[])
  {
      int low = x;
      int high = y;
      int mid = x+(y-x)/2;
      while(low<=high)
      {
          if(v[mid]==z)
              return mid;
          if(v[mid]<z)
              return binarySearch(mid+1,high,z,v);
          if(v[mid]>z)
              return binarySearch(low,mid-1,z,v);
      }
      return -1;
  }
  int modularExponentiation(int x,int n,int M)
  {
      if(n==0)
          return 1;
      else if(n%2 == 0)        //n is even
          return modularExponentiation((x*x)%M,n/2,M);
      else                             //n is odd
          return (x*modularExponentiation((x*x)%M,(n-1)/2,M))%M;
 
  } 
  int binaryExponentiation(int x,int n)
  {
      if(n==0)
          return 1;
      else if(n%2 == 0)        //n is even
          return binaryExponentiation(x*x,n/2);
      else                             //n is odd
          return x*binaryExponentiation(x*x,(n-1)/2);
  }
 
 
 
 
  set<int> s;
  //vector<int> v;
  void genrate(int n,int len,int max)
  {
      if(len>max)
          return ;
      s.insert(n);
      genrate(n*10+1,len+1,max);
      genrate(n*10+0,len+1,max);
  }
  // bool visited[200005];
  // vector<int> v[200005];
  // bool recur[200005];
  // int c = 0;
  // void dfs(int x ,int parent)
  // {
  //    visited[x] = 1;
  //    if(v[x].size() != 2)
  //     c = -1;
  //    for(int i = 0;i<v[x].size();i++){
  //     if(v[x][i] == parent)
  //       continue;
  //     if(visited[v[x][i]] && v[x].size() == 2 && c ==  0)
  //         c = 1;
  //     else if(!visited[v[x][i]]){
  //      dfs(v[x][i],x);
  //    }
  //    //return false;
  //     }
  // }
  //memset(level,0,sizeof(level));    
  /*void topological_sort(int x)
  {
      visited[x] = 1;
    //  sort(aint(v[x]));
      for(int i =0;i<v[x].size();i++)
      {
          if(visited[v[x][i]]!=1){
              //level[v[x][i]] = level[x]+1;
              topological_sort(v[x][i]);
          }
      }
      ans.pb(x);
  }*/
  //char a2001][2001];
  ///**************** Cycle using DSU *********************///


bool check(int a[], int pre[], int s, int mid){
  if(pre[mid] <= s){
    return 1;
  }
  for(int i = 1;i<=mid;i++){
    if(pre[mid]-a[i] <= s)
      return 1;
  }
  return 0;
}
int32_t main()
  {   
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      cout.tie(0);            
      //std::setprecision(20);      
      int tests=1;
        //freopen("input.txt", "r", stdin);
        //cin>>tests;
     while(tests--) 
      { 
          int  n,k;
          cin>>n>>k;
          if(n*500 >= k){
            cout<<"Yes";
          }
          else
            cout<<"No";

      }
}