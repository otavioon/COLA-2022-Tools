#include<bits/stdc++.h>
#define ll long long int
#include <stdlib.h>
#include <vector>
#define pi acos(-1)
#define MOD 1000000007
#define highest(x) numeric_limits<x>::max()
#define lowest(x) numeric_limits<x>::min()
///s1.substr(1,3);///STARTING FROM INDEX 1, 3 LNEGTH SUBSTRING.
///s1.find("adn")///RETURNS STARTING INDEX OF THE SUBSTRING
///"adn" IF IT EXISTS IN THE STRING S1.///
///s1.find("adn",int pos);///RETURNS STARTING INDEX OF THE
///SUBSTRING "adn" SEARCHING FROM INDEX POS OF STRING s1.///
///string::npos returns a garbage value if not found...
///reverse(s1.begin(),s1.end())-> to reverse a string.
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define gcd(a,b) __gcd(a,b)
using namespace std;

vector<int>adj[100005];
int vis[100005];
int vis2[100005];
//vector<ll>a1;
ll f[100005],x7=1000000005,x8,s=0;
ll f2[100005];
ll size1[200005];
ll size2[100005];
set<int>x2;
set<int>::iterator it;

int root(int a)
{
    while(f2[a]!=a){
        f2[a]=f2[f2[a]];
        a=f2[a];
    }
    return a;
}

void union1(int a,int b)
{
    int root_a=root(a);
    int root_b=root(b);
    if(root_a==root_b)return;
    else if(size1[root_a]>size1[root_b]){
        f2[root_b]=root_a;
        size1[root_a]+=size1[root_b];
    }
    else{
        f2[root_a]=root_b;
        size1[root_b]+=size1[root_a];
    }
}

map<string,ll>m2;

string removeSpaces(string str)
{
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    return str;
}

int binaryToDecimal(int n)
{
    int num = n;
    int dec_value = 0;

    // Initializing base value to 1, i.e 2^0
    int base = 1;

    int temp = num;
    while (temp) {
        int last_digit = temp % 10;
        temp = temp / 10;

        dec_value += last_digit * base;

        base = base * 2;
    }

    return dec_value;
}
//x8=x7;
ll g[5];
void dfs(ll a)
{
    if(vis[a])return;
    vis[a]=1;x7=min(x7,f[a]);//s-=f[a];
    for(int j=0;j<adj[a].size();j++){
        dfs(adj[a][j]);
    }
}

int main()
{
    long long int t,i,q,h,w,n,a,k1,k2,d,e,m,b,c,x1=1000000005,x3=0,x4=0,x5=0,x6=0;
    //string s2,s3,s4,s5,s6,s7;
    cin>>n>>m;
    if(n*500>=m)cout<<"Yes\n";
    else cout<<"No\n";

    return 0;
}
