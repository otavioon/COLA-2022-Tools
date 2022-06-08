#include <iostream>
#include <math.h>
#include <numeric>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <tuple>
#include <functional>
#include <cstring>

#define PI 3.14159265359
#define INF 1e9
#define LINF 1e18
#define irep(i,n) for(int  i = 0; i < n; i++)
#define irep2(i,a,n) for(int i = a; i < n; i++)
#define lrep(i,n) for(long long  i = 0; i < n; i++)
#define lrep2(i,a,n) for(long long i = a; i < n; i++)
#define in(a) cin >> a
#define out(a) cout << a << endl
typedef long long ll;

typedef std::vector<int> v_int;
typedef std::vector<std::vector<int> > v2_int;
typedef std::vector<ll> v_ll;
typedef std::vector<std::vector<ll> > v2_ll;
typedef std::vector<std::string> v_string;
typedef std::vector<std::vector<std::string> > v2_string;

using namespace std;

int main() 
{   
    int n; cin >> n;
    v_int a(n), b(n), c(n);
    map<string, int> s;

    irep(i, n) { cin >> a[i]; } sort(a.begin(), a.end());
    irep(i, n) { cin >> b[i]; } sort(b.begin(), b.end()); 
    irep(i, n) { cin >> c[i]; } sort(c.begin(), c.end()); 

    #if 1
    for(int i = 0; i < n; i++) {
        auto B_first = upper_bound(b.begin(), b.end(), a[i]);
        size_t B_pos = distance(b.begin(), B_first);  
        if(B_first == b.end()) { continue; }

        for(int j = B_pos; j < n; j++) {
            auto C_first = upper_bound(c.begin(), c.end(), b[j]);
            size_t C_pos = distance(c.begin(), C_first);  
            if(C_first == c.end()) { continue; }

            for(int k = C_pos; k < n; k++) {
                if(a[i] < b[j] && b[j] < c[k]) {
                    string t = to_string(i) + to_string(j) + to_string(k);
                    //cout << t <<endl;
                    s[t]++;
                }
            }
        }
    }
    
    cout << s.size() << endl;
    #endif
    return 0;
}
    

