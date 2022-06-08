#include <bits/stdc++.h>
using namespace std;

int main()
{
    string n;
    int k;
    cin >> n >> k;
    bool arr[10]={};
    for(int i=0;i<k;i++)
    {
        int x;
        cin >> x;
        arr[x]=true;
    }
    vector<int>v;
    for(int i=0;i<10;i++)
    {
        if(!arr[i])
            v.push_back(i);
    }
    bool flag=true;
    string ans="";
    for(int i=n.size()-1;i>=0;i--)
    {
        int cur=n[i]-'0';
        if(!arr[cur])
        {
            ans+=n[i];
            continue;
        }
        int idx=lower_bound(v.begin(),v.end(),cur)-v.begin();
        if(idx==v.size())
        {
            flag=false;
            break;
        }
        ans+=(v[idx]+'0');
    }
    reverse(ans.begin(),ans.end());
    if(ans.size())
        cout << ans << endl;
    else
    {
        int tmp;
        for(int i=0;i<v.size();i++)
        {
            if(v[i]!=0)
            {
                tmp=v[i];
                cout << v[i];
                break;
            }
        }
        int more=0;
        for(int i=0;i<v.size();i++)
        {
            if(v[i]!=tmp)
            {
                more=v[i];
                break;
            }
        }
        for(int i=0;i<n.size();i++)
            cout << more;
    }


    return 0;
}
