#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,k;
    cin >> n >> k;
    set<double, greater <int>> s;
    ll a;
    for(int i=0;i<n;i++){
        cin >> a;
        s.insert((double)a);
    }
    while(k--){
       double b = *s.begin();
       s.erase(s.begin());
       s.insert(b/2);
       s.insert(b/2);
    }
//    for(set<double,greater<int> > :: iterator it = s.begin();it!=s.end();it++){
//        cout << *it << " ";
//    }
//    cout << endl;
    cout << ceil(*s.begin());
    return 0;
}
