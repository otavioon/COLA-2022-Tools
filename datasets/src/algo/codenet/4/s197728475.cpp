#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define all(v) v.begin(),v.end()
#define vi vector<int> 
#define mod 1000000007
#define inf 1e17
#define fs first
#define ss second

template <typename T> 
void amax(T& x, T y) 
{ 
    if( x < y) x = y;
} 

template <typename T> 
void amin(T& x, T y) 
{ 
    if( x > y) x = y;
} 
////////////////////////////////////////////////////////////////////////////////


int main(){
   
   int n,k;
   cin >> n >> k;
   set<int> s;
   int y;
   
   for(int i =0;i<k;i++) cin >> y,s.insert(y);
   int ans = 0;
   while(1){
	   
	   string x = to_string(n);
	   int f = 0;
	   for(auto i: x){
		   if( s.find(i -'0') != s.end()){
			   f =1;
			   break;
		   } 
		   
	   }
	   if( f== 1) n++;
	   else {
		   ans = n;
		   break;
	   }
	   
   }
   
   cout << ans << endl;
     
}
