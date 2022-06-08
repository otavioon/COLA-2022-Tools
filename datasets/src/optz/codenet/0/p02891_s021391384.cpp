/** 
 * Dont raise your voice, improve your argument.
 * --Desmond Tutu
 */

#include <bits/stdc++.h>
using namespace std;

const double PI=3.1415926535897932384626433;
typedef long long ll;
#define endl "\n"
#define fori(n) for(ll i=0; i<(n); i++)

#define cins(s) string s; cin>>s;
#define cini(i) int i; cin>>i;
#define cinll(l) ll l; cin>>l;
#define cinai(a, n) vi a(n); fori(n) { cin>>a[i]; }
#define cinall(a, n) vll a(n); fori(n) { cin>>a[i]; }
#define cinas(s, n) vs s(n); fori(n) { cin>>s[i]; }

typedef pair<int, int> pii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<string> vs;
typedef vector<ll> vll;

//#define DEBUG

int main() {
cin.tie(nullptr);
std::ios::sync_with_stdio(false);
    cins(s);
    cinll(k);

/* Cases
 * 1. sames within string: change n/2; 3:1, 4,2
 * 2. sames at begin/end
 * on first k nbegin/2, last k nend/2
 * other (nbegin+nend)/2
 * 3. all same: (n*k)/2
 */

    int nbegin=1;
    for(size_t i=1; i<s.size(); i++) {
        if(s[i]==s[0])
            nbegin++;
        else
            break;
    }

    int nend=1;
    for(int i=s.size()-2; i>=0; i--) {
        if(s[i]==s[s.size()-1])
            nend++;
        else
            break;
    }
    if(nbegin+nend>s.size()) {     // case 3
        ll ans=(k*s.size())/2;
        cout<<ans<<endl;
        return 0;
    }

    vector<pii> sames;
    sames.push_back({ 0, nbegin});

    char c=s[nbegin];
    int idx=nbegin+1;
    int cnt=1;
    while(idx<s.size()) {
        while(idx<s.size() && s[idx]==c) {
            cnt++;
            idx++;
        }

        if(cnt>1) {
            sames.push_back({nbegin, cnt});
        }

        nbegin=idx;
        c=s[idx];
        idx++;
        cnt=1;
    }

    sames.push_back({ nbegin, cnt} );

#ifdef DEBUG
cout<<"dump sames"<<endl;
for(auto p : sames)
    cout<<"first="<<p.first<<" second="<<p.second<<endl;
#endif

    ll ans=0;
    if(s[sames[0].first]==s[sames.back().first]) { /* case 2 */
        ans+=sames[0].second/2;
        ans+=sames.back().second/2;
        if(k>1)
            ans+=((k-1)*(sames[0].second+sames.back().second))/2;

        for(int i=1; i<sames.size()-1; i++) 
            ans+=k*(sames[i].second/2);

    } else {
        for(int i=0; i<sames.size(); i++) 
            ans+=k*(sames[i].second/2);
    }

    cout<<ans<<endl;
    

}

