#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    long long n;
    cin >> n;
    long long a[n], b[n], c[n];
    for(int i=0;i<n;i++)cin >> a[i];
    for(int i=0;i<n;i++)cin >> b[i];
    for(int i=0;i<n;i++)cin >> c[i];

    sort(a, a+n);
    sort(b, b+n);
    sort(c, c+n);

    unsigned long long ans = 0;
    long long upPart = 0;
    long long downPart = 0;
    for(int i=0;i<n;i++){
        while(a[upPart]<b[i] && upPart<n)upPart++;
        while(c[downPart]<=b[i] && downPart<n)downPart++;
        ans += upPart * (n-downPart);
    }
    cout << ans << endl;
}
