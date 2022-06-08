#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define repr(i,x,n) for(int i=x; i<(n); i++)
#define ALL(x) (x).begin(),(x).end()
#define INF 1e9
typedef long long ll;
using VI = vector<int>;
using VS = vector<string>;
using graph = vector<vector<int>>;
int main()
{
int a,b;
cin>>a>>b;
if (a==1&&b!=1||a>b)
{
    cout<<"Alice"<<endl;
    
}
else if (b==1&&a!=1||a<b)
{
 cout<<"Bob"<<endl;
}
 else if (a==b)
 {
     cout<<"Draw"<<endl;
    
 }
 

    return 0;
}