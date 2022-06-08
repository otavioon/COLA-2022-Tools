#include<bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);i++)
#define ALL(v) (v).begin(),(v).end()
#define int long long
using namespace std;
typedef vector<int>   vint;
typedef pair<int,int> pint;

int c[4][4];

signed main()
{   
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            cin>>c[i][j];
        }
    }

    if(c[1][1]+c[2][2]+c[3][3]==c[1][2]+c[2][3]+c[3][1] and 
       c[1][1]+c[2][2]+c[3][3]==c[1][3]+c[2][1]+c[3][2])
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
}
