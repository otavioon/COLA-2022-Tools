#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define lol(i,n) for(int i=0;i<n;i++)
#define mod 1000000007
typedef long long ll;
using namespace std;

int main(){
    int x[3][3];
    lol(i,3)lol(j,3)cin>>x[i][j];
    bool ok=true;
    for(int i=1;i<3;i++){
	int k=x[i][0]-x[0][0];
	for(int j=1;j<3;j++)if(k!=x[i][j]-x[0][j])ok=false;
    }
    cout<<(ok?"Yes":"No")<<endl;
    return 0;
}
