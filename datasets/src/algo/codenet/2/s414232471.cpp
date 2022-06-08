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
    int y;
    while(!S.empty())
    {
        int x=*S.rbegin();
        y=1;
        while(y<=x)
            y*=2;
        auto it=S.find(y-x);
        if(it!=S.end()){
            S.erase(it);
            ans++;
        }
    }
    cout<<ans;

}
