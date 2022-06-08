#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define F first
#define S second
#define db double
#define pb push_back
using namespace std;

bool compare(const pair<ll,ll>&a,const pair<ll,ll>&b)
{
    return a.second<b.second;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll tests=1;
    //cin>>tests;
    while(tests--)
    {
       ll n,k,i,t;
       cin>>n>>k;
       set<ll>like;
       for(i=0;i<k;i++){cin>>t;like.insert(t);}
       string ans;
       ll extra=0;
       ll small=0;
       while(small<10)
       {
           if(like.find(small)!=like.end()) small++;
           else {break;}
       }
       for(auto x:to_string(n))
       {
           t=(int)x-48;
           if(extra)
           {
               ans+=to_string(small);
           }
           else if(like.find(t)!=like.end())
           {
               while(t<10)
               {
                   if(like.find(t)!=like.end())
                   {t++;}
                   else {ans=ans+to_string(t);break;}
                   if(t==10) {t=0;extra++;}
               }
           }
           else {ans+=to_string(t);} 
           
       }
       if(extra) {ans+=to_string(small);}
       cout<<ans;
    }
    
    return 0;
}
