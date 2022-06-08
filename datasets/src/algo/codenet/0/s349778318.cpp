#include "bits/stdc++.h"
using namespace std;
#define INF 1000000000
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(x) (x).begin(), (x).end()  //昇順
#define RALL(x) (x).rbegin(), (x).rend() // 降順
#define SZ(x) ((int)(x).size)
const long long mod = 1e9+7;
typedef priority_queue<int> PQ;
typedef vector<long long> Vl;
typedef vector<int> VI;  // VI a(n);
typedef vector<string> VS;  
typedef vector<VS> VSS;  
typedef vector<VI> VVI;   // VVI a(n,vector<int>(m)) n * m 
typedef vector<Vl> VVl;
typedef pair<int, int> PII;
typedef vector<pair<int, int> > PS;
typedef long long ll;  //ll とdoubleは違う
// cout << << endl;
// cin >> ;

int main(){
    ll x=0,g=0,n,w,l,ans=0,ptr=0;
    string s,s1,s2;
    bool f = true;
    char a;
    cin >> s >> n;
    for(int i=0;i<s.size();i++){
        a = s[i];
        for(int j=i;j<=s.size();j++){
            if(a==s[j]){
                g++;
            }
            else{
                ans += g/2;
                break;
            }
        }
        i=i+g-1;
        if(i >= s.size()) break;
        g=0;
    }


    g = 0;
    a = s[s.size()-1];
    for(int j=s.size()-1;j>=0;j--){
        if(a==s[j]){
            g++;
        }
        else{
            break;
        }
    }
    a = s[0];
    for(int i=0;i<s.size();i++){
       if(a==s[i]){
            x++;
        }
        else{
            break;
        }
    }


    if(x+g%2==0 && s[0]==s[s.size()-1]) f = false;
    ptr =  ans*n;
    if(f) cout << ptr << endl;
    else cout << ptr + (n-1) << endl;
    return 0;
}