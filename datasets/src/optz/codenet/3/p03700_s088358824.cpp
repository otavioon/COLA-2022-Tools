#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;i++)
#define why(n,x) int n;while(cin >>n,n!=x)
#define iFOR(i,x,n)for(int i=x;i<n;i++)
#define unless(flg) if ( !(flg) )
#define read cin<<
#define echo cout<<
#define fin <<'\n'
#define __ <<" "<<
#define bash push_back
#define alles(x) x.begin(),x.end()
#define SWAP(a,b) ((a != b) && (a += b,b = a - b,a -= b))
#define cinf(i,n,x) for(int UNCH = (i); UNCH < (n); UNCH++) cin>>x[UNCH];
#define ABS(x) (x)<0 ? -(x) : (x)
#define int long long
int dx[]={1,0,-1,0,1,1,-1,-1};
int dy[]={0,-1,0,1,-1,1,-1,1};
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
bool inside(int x,int y,int w,int h){
  return (x>=0 && y>=0 && x<w && y<h);}
typedef long long ll;
typedef pair < int , int >  pii;
typedef vector < int > vit;
typedef map < string , int > mstit;
typedef vector < pii > vpi ;
typedef greater < pii > gpi;
typedef priority_queue < pii , vpi , gpi > dijk ;

int n , a , b;
int h[100005];

bool Judge(int X){
    int plus =0;
    FOR(i,n){
        int j = 0;
        if( h[i] - b*X > 0){
            int chek = h[i] - b*X ;
            chek = (chek+a-b-1) / (a-b);
            plus += chek;
        }
    }
    return ( plus > X ) ? false : true;
}

signed main(){
    cin.tie(0), ios::sync_with_stdio(false);
    cin >> n>> a>> b;
    cinf(0,n,h);
    sort(h,h+n);
    int ok = LINF,ng = -1;
    while(ok - ng > 1) {
        int mid = (ng + ok) >> 1 ;
        (Judge(mid) ? ok  : ng ) = mid;
    }
    cout << ok fin;
    return 0;
}
