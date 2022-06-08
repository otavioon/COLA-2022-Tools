#include <bits/stdc++.h>

#define rep(i,n) for(long long int (i)=0;(i)<(int)(n);(i)++)
#define rrep(i,a,b) for(long long int i=(a);i<(b);i++)
#define rrrep(i,a,b) for(long long int i=(a);i>=(b);i--)
#define all(v) (v).begin(), (v).end()
#define pb(q) push_back(q)
#define Abs(a,b) max(a,b)-min(a,b)
#define YES(condition) if(condition){cout << "YES" << endl;}else{cout << "NO" << endl;}
#define Yes(condition) if(condition){cout << "Yes" << endl;}else{cout << "No" << endl;}
#define Cout(x) cout<<(x)<<endl
#define POSSIBLE(condition) if(condition){cout << "POSSIBLE" << endl;}else{cout << "IMPOSSIBLE" << endl;}
#define Possible(condition) if(condition){cout << "Possible" << endl;}else{cout << "Impossible" << endl;}
#define possible(condition) if(condition){cout << "possible" << endl;}else{cout << "impossible" << endl;}
#define Size(n) (n).size()

typedef long long ll;


using namespace std;

const int INF = 1e9,MOD = 1e9 + 7,ohara = 1e6;
const ll LINF = 1e18;


long long int n,cnt=0,ans=0,a,b,c,d,cmp,cmpp,m,h,w,x,y,sum=0,pos,k;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
string alph("abcdefghijklmnopqrstuvwxyz");
bool fl;
struct edge{int to,cost;};

//-------------------------↓↓↓↓↓↓------------------------

int main(void){
       cin.tie(0);
    ios::sync_with_stdio(false);

      
      cin>>n>>k;
      map<ll,ll> mp;
      rep(i,k){
        cin>>a;
        mp[a]++;
      }
     while(1){
       fl=true;
       string s;
       s=to_string(n);
       rep(i,Size(s)){
         if(mp[(s[i]-'0')]!=0)fl=false;
       }
       if(fl){
         Cout(n);
         return 0;
       }
       else{
         n++;
       }
     }
     

       
return 0;
}
