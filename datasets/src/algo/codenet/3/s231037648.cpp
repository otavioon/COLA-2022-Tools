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
    for(int i = 0; i < n; i++){
        int numa = 0, numc = 0;
        for(int j = 0; j < n; j++){
            if(a[j] < b[i]) numa++;
        }
        for(int j = 0; j < n; j++){
            if(b[i] < c[j]) numc++;
        }
        ans += numa * numc;
    }
    cout << ans << endl;
  return 0;
}
