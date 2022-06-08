#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main()
{

    ll n, q, a, b, i, x, p1, ii;
    cin>>n>>q;
    vector<ll>adjmat[n+1];
    vector<ll>out(n+1, 0);
    for(i=0; i<n-1; i++){
        cin>>a>>b;
        adjmat[a].push_back(b);
        adjmat[b].push_back(a);
    }
    for(i=1; i<=n; i++){
        out[i]=0;
    }
    for(ii=0; ii<q; ii++){
        cin>>x>>p1;
        out[x]+=p1;
    }

    stack<ll>s;
        ll  m, p, c;
        //memset(vis, -1, sizeof(vis));
        vector<ll>vis(n+2, -1);
        s.push(1);
        vis[1]=1;
        while(!s.empty()){
            m=s.top();
           // s.pop();
            c=0;
            for(i=0; i<adjmat[m].size(); i++){
                p = adjmat[m][i];
                if(vis[p]== -1){
                    s.push(p);
                    out[p] += out[m];
                    vis[p] = 1 ;
                    c=1;
                    break;
                }
            }
            if(c==0){
                s.pop();
            }
        }

    for(int i=1; i<=n; i++){
        cout<<out[i]<<" ";
    }
    cout<<endl;
    return 0;
}

