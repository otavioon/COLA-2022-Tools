#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define faster ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
 
typedef vector<int> vi;;
typedef vector<ll> vll;

#define l() length()
#define sz() size()
 
#define b() begin()
#define e() end()
#define all(x) x.begin(), x.end()
 
#define pb(i) push_back(i)
#define PB() pop_back()
 
 
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define Fi first
#define Se second
 
const int maxx=100009;
 
// Happy Coding!

bool disl[10];
bool checkAllDigits(int num){
    while(num>0){
        int d=num%10;
        if(disl[d]==true){
            return false;
        }
        num/=10;
    }
    return true;
}
int _find(int n){
    while(1){
        if(checkAllDigits(n)){
            return n;
        }
        n++;
    }
    return n;
}
void solve(){
   int n,k;
   cin>>n>>k;
   
   memset(disl,false,sizeof(disl));
   for(int i=0;i<k;i++){
       int d;
       cin>>d;
       disl[d]=true;
   }
   
   cout<<_find(n)<<endl;
}
 
int main() {
    faster;
    int t=1;
    // cin>>t;
    
    while(t-->0){
        solve();
    }
	return 0;
}