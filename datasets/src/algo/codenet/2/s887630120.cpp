#include <bits/stdc++.h>
using namespace std;

multiset<int> S;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        S.insert(x);
    }
    int ans=0;
    while(!S.empty())
    {
        int x=*S.rbegin();
        int y=1;
        S.erase(S.find(x));
        while(y<=x)
            y*=2;
        auto it=S.find(y-x);
        if(it!=S.end()){
            ans++;
            S.erase(it);
        }
    }
    cout<<ans;

}
