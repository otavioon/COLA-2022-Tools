#include<bits/stdc++.h>
using namespace std;

#define rp(i,n) for(int i=0;i<n;i++)
#define rep(i,m,n) for(int i=m;i<=n;i++)
#define lrp(i,n) for(long long i=0;i<n;i++)
#define lrep(i,m,n) for(long long i=m;i<=n;i++)
#define all(a) a.begin(),a.end()
#define pb push_back

typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<string> vs;
typedef vector<char> vc;
typedef long long ll;

int main(){
    int n,m;
    cin >> n >> m;
    vs a(n),b(m);
    rp(i,n){
        cin >> a.at(i);
    }
    rp(i,m){
        cin >> b.at(i);
    }
    rp(i,n-m+1){
        rp(j,n-m+1){
            int cnt=0;
            rp(k,m){
                rp(l,m){
                    if(a.at(i+k).at(j+l)==b.at(k).at(l)){
                        cnt++;
                    }
                }
            }
            if(cnt==m*m){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}
