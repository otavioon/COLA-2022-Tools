#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define sfi(a) scanf("%d",&a)
#define m_p make_pair
#define inf 1e9
#define ff first
#define ss second
#define pi(x) pair<x,x>
#define mem(x) memset(x,-1,sizeof(x))
#define TEST_CASE(t) for(int z=1 ; z<=t ; z++)
#define read freopen("input.txt","r",stdin)
#define write freopen("output.txt","w",stdout)
#define FAST  ios_base::sync_with_stdio(0);cout.tie(0)

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
const int sz = 20;
const ld pi = acos(-1);
set<int> st;

bool check(int n){
    bool flag = true;
    while(n!=0){
        int d = n%10;
        if(st.find(d)!=st.end()){flag = false;break;}
        n -= d;
        n /= 10;
    }
    return flag;
}

int fun(int val,int n){
    int ret = val - n;
    if(check(ret) && check(n)) return n;
    else return -1;
}

int main()
{
    int n,k;
    cin >> n >> k;
    while(k--){
        int x; cin >> x;
        st.insert(x);
    }
    int val = n;
    n++;
    while(fun(val,n)==-1) n++;
    int ans = n;
    cout << ans << endl;
    return 0;
}


