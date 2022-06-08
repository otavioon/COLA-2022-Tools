#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
    int n;
    cin >> n;
    
    int a[100000], b[100000], c[100000];
    int i;
    for(i = 0; i < n; i++){
        cin >> a[i];
    }
    for(i = 0; i < n; i++){
        cin >> b[i];
    }
    for(i = 0; i < n; i++){
        cin >> c[i];
    }
    
    sort(a, a + n);
    sort(b, b + n);
    sort(c, c + n);
    
    
    long long ab[100000] = {0}, bc[100000] = {0};
    i = 0;
    int j = 0, k = 0;
    while(j < n){
        while(i < n && a[i] < b[j]){
            i++;
        }
        ab[j] = i;
        
        while(c[k] <= b[j]){
            k++;
            if(k == n){
                goto next;
            }
        }
        bc[j] = n - k;
        
        j++;
    }
    
    next:
    long long cnt = 0;
    for(i = 0; i < n; i++){
        cnt += ab[i] * bc[i];
    }
    
    cout << cnt << endl;
    
    return 0;
}
