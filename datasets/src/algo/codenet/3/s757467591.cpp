#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    int n;
    cin >> n;
    int a[n], b[n], c[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < n; i++) cin >> c[i];
    sort(a, a + n);
    sort(b, b + n);
    sort(c, c + n);    
    long ans = 0;
    int numa = 0, numc = 0;
    for(int i = 0; i < n; i++){
        while(numa < n && a[numa] < b[i]) numa++;
        while(numc < n && c[numc] <= b[i]) numc++;
        ans += numa * (n - numc);
    }
    cout << ans << endl;
  return 0;
}
