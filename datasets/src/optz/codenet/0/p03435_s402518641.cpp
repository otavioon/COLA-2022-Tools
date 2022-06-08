#include <iostream>
#include<algorithm>
#include<set>
#include<queue>
#include<bitset>
#define rep(i,j,n) for(int i=j;i<n;i++)
using namespace std;
#define int long long
struct edge{long long to,cost;};
struct st{int rate,way,num;};
typedef pair<int,int>P;
#define inf 1000000007
string alph("abcdefghijklmnopqrstuvwxyz");
signed main(){
    int num[3][3];
    rep(i,0,3)rep(j,0,3)cin>>num[i][j];
    bool ans=true;
    rep(i,0,2){
        if(num[i+1][0]-num[i][0]!=num[i+1][1]-num[i][1]||num[i+1][0]-num[i][0]!=num[i+1][2]-num[i][2])ans=false;
    }
    rep(i,0,2){
        if(num[0][i+1]-num[0][i]!=num[1][i+1]-num[1][i]||num[0][i+1]-num[0][i]!=num[2][i+1]-num[2][i])ans=false;
    }
    if(ans)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
