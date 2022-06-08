#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mx 1000000
vector<ll>v[mx];
bool vis[mx];
ll dis[mx];
void bfs(ll y)
{
    vis[y]=1;
    queue<ll>q;
    q.push(y);
    while(!q.empty())
    {
        q.pop();
        for(auto a:v[y])
        {
            if(vis[a])
            {
                continue;
            }
            q.push(a);
            vis[a]=1;
            dis[a]=dis[y]+1;
        }
        y=q.front();
    }
}

int main()
{

    ll n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        ll x;
        cin>>x;
        v[i+1].pb(x);
        //v[x].pb(i+1);
    }
    bfs(1);
    if(vis[2])
    {
        cout<<dis[2]<<endl;
    }
    else{
        cout<<"-1"<<endl;
    }

}
