#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define fi first
#define sec second
#define PB push_back
#define MP make_pair
#define endl '\n'
#define rep(i,a,b)      for(int i=a;i<=b;i++)
#define revp(i,a,b)     for(int i=b;i>=a;i--)
#define all(v)          v.begin(),v.end()
void fast(){ ios::sync_with_stdio(false); cin.tie(NULL);}
void file()
{ 
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout);
    #endif
}

int temp,n,k,j;
set<int> s;
bool ok;

int main()
{
    fast();
    

    cin>>n>>k;
    for(int i=0;i<k;i++)
        cin>>temp,s.insert(temp);
    for(int i=n;i<100000;i++)
    {
        j=i;
        ok = 1;
        while (j) 
        {
            temp = j % 10;
            if (s.count(temp)) 
            {
                ok = 0;
                break;
            }
            j/=10;
        }
        if(ok)
        {
            cout<<i;
            break;
        }
    }
}
