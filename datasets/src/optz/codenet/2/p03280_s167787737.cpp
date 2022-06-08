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


long long int n,cnt=0,ans=0,a,b,c,d,cmp,cmpp,m,h,w,x,y,sum[600][600],pos,q,l[ohara],r[ohara],ma[ohara];
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
string alph("abcdefghijklmnopqrstuvwxyz"),s;
bool fl=true;
struct edge{int to,cost;};

//-------------------------↓↓↓↓↓↓------------------------

int main(void){
       cin.tie(0);
    ios::sync_with_stdio(false);

      
      cin>>n>>m>>q;
      //pair<ll,ll> p[ohara];
      map<ll,ll> kazu;
      map<pair<ll,ll>,ll> mp;
      rep(i,m){
        cin>>a>>b;
        if(ma[a]<=b)ma[a]=b;
        kazu[a]++;
        sum[a][b]++;
       // l[i]=make_pair(a,b);
        mp[{a,b}]++;
      }
      rep(i,n){
        rep(j,n){
          sum[i][j+2]+=sum[i][j+1];
        }
      }
     // rep(j,n)cout<<sum[2][j+1]<<" ";

      //sort(p,p+m);
      rep(i,q){
        cin>>a>>b;
        cnt=0;
        rrep(j,a,n+1){
          if(ma[j]<=b){ans+=kazu[j];}
          else{
            //Cout("b");
            
           cnt=sum[j][n]-sum[j][b];
            /*
            if(cnt==0){
              cout<<j<<"\n";
              cout<<"-------";
              rep(kk,n)cout<<sum[j][kk+1];
              cout<<"----------";
            }
            */
            
            ans+=max(kazu[j]-cnt,0LL);
          }
         // Cout(ans);
        }
        Cout(ans);
        ans=0;
      }
  //Cout(ma[2]);
     

       
return 0;
}
