#include<bits/stdc++.h>
using namespace std;
#define ll  long long
#define endl '\n'
#define FASTINOUT ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const ll mod = 1000000007;
const double PI = 3.141592653589793238463;
int main()
{
    FASTINOUT;
    int x;
    cin>>x;
    int y[x-1];
    ll sum=0;
    for (int i=0;i<x-1;i++){
        cin>>y[i];
    }
    for (int i=0;i<x-2;i++){
        if (y[i]<=y[i+1]){
            if (i==0)
            sum+=(2*y[i]);
            else
            sum+=y[i];
        }
        else{
            if (i==0)
            sum+=(2*y[i+1]);
            else
            sum+=y[i+1];
        }
    }
    if (x>2)
    sum+=y[x-2];
    else
        sum+=(2*y[x-2]);
    cout<<sum<<endl;
    return 0;
}
