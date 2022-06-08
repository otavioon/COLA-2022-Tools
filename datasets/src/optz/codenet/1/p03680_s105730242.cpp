#include<bits/stdc++.h>
using namespace std;
vector<int>answer[100001];
int v[100001]={0};
int ans=0;
int dfs(int s)
{
    v[s]=1;
    int i;
    for(i=0;i<answer[s].size();i++)
    {
        if(v[answer[s][i] ]==0 )
        {

            ans++;
                dfs(answer[s][i]);

        }
    }
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    int i;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        answer[i+1].push_back(a[i]);
    }
    dfs(1);
    if(v[2]==1)
          cout<<ans<<endl;
    else
        cout<<-1<<endl;
}
