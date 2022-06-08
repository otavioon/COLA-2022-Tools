#include<bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);i++)
#define ALL(v) (v).begin(),(v).end()
#define int long long
using namespace std;
typedef vector<int>   vint;
typedef pair<int,int> pint;

signed main()
{
    int c[3][3];
    REP(i,3) REP(j,3) cin>>c[i][j];

    REP(i,2){
        set<int> st;
        REP(j,3){
            st.insert(c[i][j]-c[i+1][j]);
        }
        if(st.size()>1){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
 
}
