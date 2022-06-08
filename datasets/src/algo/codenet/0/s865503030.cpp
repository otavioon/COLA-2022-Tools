/*Author - Saikia*/
#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define N 998244353
#define ll long long
#define REP(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define vll vector<long long>
#define INF 1000000000


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    string s;
    ll k;
    cin>>s;
    cin>>k;
    ll ans=0;
    ll t=s.size();
    if(s.size() == 1){
        cout<<k/2; return 0;
    }
    bool cc=false;
    bool tt=false;
    REP(i, 1, t){
        if(s[i] == s[i-1]){
            if(!tt){ans++; 
            tt=true;}
            else{
                tt=false;
            }
        }else{
            tt=false;
        }
        if(i == 1 && tt){
            cc =true;
        }
    }
    if(!tt  && (s[0] == s[t-1]) ){
       if(!cc) {ans = ans*k;
        ans += k-1;}
        else{
            ans *=k;
        }
    }
    else if(tt  && (s[0] == s[t-1]) && !cc){
        ans = ans*k;
        ans+= k-1;
    }
    else{
        ans = ans*k;
    }
    cout<<ans;
}
