#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long int

using namespace std;


int main(){
    int n;
    cin >> n;
    
    vector<int> d;
    
    set<tuple<int, int, int> > t;

    
    rep(i, n) {
        int x;
        cin >> x;
        d.push_back(x);
    }
    
    int cnt = 0;
    rep(i,n) {
        int a = d[i];
        for(int j = 0; j < i; j++) {
            int b = d[j];
            for(int k = 0; k < n; k++) {
                if( k == i || k == j) continue;
                
                
                int n1,n2,n3;
                n1 = min(i, min(j,k));
                n2 = min(i, max(j,k));
                n3 = max(i, max(j,k));
                tuple<int, int, int> ns = make_tuple(n1,n2,n3);
                
                decltype(t)::iterator it = t.find(ns);
                if (it != t.end()) {
                    continue;
                }
                
                int c = d[k];
                
                int bc = b+c;
                if(a >= bc) {
                    continue;
                }
                
                int ca = c+a;
                if(b >= ca) {
                    continue;
                }
                
                int ab = a+b;
                if(c >= ab) {
                    continue;
                }
                
                t.insert(ns);
               
                
                cnt++;
            }
            
        }
    }
    
    cout << cnt;
    
}
