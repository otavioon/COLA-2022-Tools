#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <numeric>
#define Rep(i, m, n) for(int i = m;i < n;i++)
#define Brep(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define INF 999999999
using namespace std;

int main(){
    int n; cin >> n;
    int t[n], m[n], b[n];
    Rep(i, 0, n) cin >> t[i];
    Rep(i, 0, n) cin >> m[i];
    Rep(i, 0, n) cin >> b[i];
    SORT(t, n);
    SORT(m, n);
    SORT(b, n);

    //Rep(i, 0, n) cout << t[i] << endl;


    int count = 0;
    Rep(i, 0, n){
        Rep(j, 0, n){
            Rep(k, 0, n){
                if(t[i] < m[j] && m[j] < b[k]) count += 1;
            }
        }
    }
    cout << count << endl;

    return 0;
}
