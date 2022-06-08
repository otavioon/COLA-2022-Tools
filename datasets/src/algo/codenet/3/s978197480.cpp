#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n] , b[n], c[n]; 
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];
    for(int i=0; i<n; i++) cin >> c[i];
    sort(a, a+n);
    sort(b, b+n);
    sort(c, c+n);
    int x=0;
    int z=0;
    long ans =0;
    for(int i=0; i<n; i++){
        while(x<n && a[x] < b[i]) x++;
        while(z<n && c[z] <= b[i]) z++;
        ans += (long)x*(n-z);
    }
    
    cout << ans << endl;
    return 0;
}
