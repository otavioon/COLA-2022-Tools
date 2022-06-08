#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
using namespace std;

int main()
{
       ios_base::sync_with_stdio(0);
       cin.tie(0);

       int t=1;
       //cin>>t;
       while(t--)
       {
               int n,k;
               cin>>n>>k;
               int a[k];
               set<int> s;
               int xx;
               vector<int>b;
               for(int i=0;i<k;++i)
               {
                    cin>>xx;
                    s.insert(xx);
               }



               for(int i=1;i<=9;++i)
               {
                    if(s.count(i)==0)
                         b.pb(i);
               }
               if(s.count(0)==0)
                    b.pb(0);
               int x =0;
               int dig=0;
               int num = n;
               while(n>0)
               {
                    n/=10;
                    x++;
               }
               vector<int> res;
               while(num>0)
               {
                    dig = num%10;
                    if(s.count(dig)==0)
                    {
                         res.push_back(dig);
                    }
                    else
                    {
                         res.pb(b[0]);
                    }
                    num/=10;
               }
               for(int i=res.size()-1;i>=0;--i)
                    cout<<res[i];
       }
}
