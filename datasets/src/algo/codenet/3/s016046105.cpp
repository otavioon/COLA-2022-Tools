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
        for(int j = 0; j < n; j++){
            if(a[i] >= b[j]) continue;
            for(int k = 0; k < n; k++){
                if(b[j] < c[k]) ans++;
            }
        }
    }
    cout << ans << endl;
  return 0;
}
