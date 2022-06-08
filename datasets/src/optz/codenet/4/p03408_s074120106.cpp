//Radhe Radhe
#include<bits/stdc++.h>
#define ll long long
#define fixed cout.setf(ios::fixed);
#define rep1    for( i=0; i<n; i++)
#define Precise cout.precision(7);
#define yes cout<<"Yes"<<'\n'
#define no cout<<"No"<<'\n'
using namespace std;

int main()
{
    ll i,j,n,m,a,b,c;
    string x;
    set<string>s,t;
    cin>>n;
    while(n--)
    {
        cin>>x;
        s.insert(x);
    }
    cin>>m;
    while(m--)
    {
        cin>>x;
        t.insert(x);
    }
    ll ans1=0,ans2=0;
    vector<string>ss(s.begin(),s.end()),tt(t.begin(),t.end());
    for(ll i=0; i<ss.size(); i++)
    {
        bool ok=1;
        for(ll j=0; j<tt.size(); j++)
        {
            if(ss.at(i)==tt.at(j))
            {
                ok=0;
                break;
            }
        }
        if(ok)
            ans1++;
    }

    for(ll i=0; i<tt.size(); i++)
    {
        bool ok=1;
        for(ll j=0; j<ss.size(); j++)
        {
            if(tt.at(i)==ss.at(j))
            {
                ok=0;
                break;
            }
        }
        if(ok)
            ans2++;
    }

    cout<<max(ans1,ans2)<<endl;
    return 0;
}



