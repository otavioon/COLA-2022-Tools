#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n],b[n],c[n];
    for(int i = 0;i < n;i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < n; i++)
        cin >> c[i];

    sort(a,a+n);
    sort(b,b+n);
    sort(c,c+n);

    int count = 0;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(b[j] <= a[i]) {
                break;
            }
            for(int k = 0;k < n;k++) {
                if(c[k] > b[j]) {
                    count += n - k;
                    break;
                    //count++;
                }
            }
        }
    }
    cout << count << endl;
    return 0;
}