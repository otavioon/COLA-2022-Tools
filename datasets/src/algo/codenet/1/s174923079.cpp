#include <bits/stdc++.h>
#define rep(i,j,k) for(int i=(int)j;i<(int)k;i++)
#define itrep(i,x) for(auto i=(x).begin(); i!=(x).end();i++)
#define Sort(x) sort((x).begin(),(x).end())
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define vi vector<int>
#define INF (int)1e9
#define INFL 1e18
#define MOD 1000000007
#define pb push_back
#define MP make_pair
#define PI 3.1415926535
typedef long long int ll;
typedef std::pair<int,int> P;
int D=1;
int dx[4]={0,1,0,-1},dy[4]={-1,0,1,0};

using namespace std;

int main(){
    int v[3][3];
    rep(i,0,3)rep(j,0,3)cin>>v[i][j];
    if(v[0][0]+v[1][1]+v[2][2]==v[0][1]+v[1][2]+v[2][0]&&v[0][1]+v[1][2]+v[2][0]==v[0][2]+v[1][0]+v[2][1]){
        cout<<"Yes"<<endl;
        
    }else cout<<"No"<<endl;
    return 0;
}
