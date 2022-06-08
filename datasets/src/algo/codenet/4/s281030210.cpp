#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int,  int>;
const ll INF = 1LL << 60;
const int INF32 = 1 << 29;
const ll MOD = 1000000007;

int main(){
     int n, k; cin >>n >> k;
     vector<ll> a(10); 
     for(int i = 0; i < k; ++i){
       int d;cin >>d;;
       a[d]=-1;
     }
     set<int> num;
     for(int i = 0; i < 10; ++i){
       if(a[i]==0)num.insert(i);
     }
  
     int ans = n;
     while(true){
           bool flag = true;
           for(int i = 10; i >=0; --i){
             int keta=pow(10,i);
             if(ans%keta==ans){continue;}
             int tmp = (ans/keta)%10;
             if(num.count(tmp)==0){
               flag =false;
               break;
             }
           }
           if(flag){break;}
           ++ans;   
     }     
     cout << ans << endl;
}