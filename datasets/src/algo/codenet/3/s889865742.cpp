#include<bits/stdc++.h>
using namespace std;
long long int q[100005];
long long int p[100005];
int main(){
    int n;
    cin >> n;
    int a[n],b[n],c[n];
    for(int i=0;i<n;i++)cin >> a[i];
    for(int i=0;i<n;i++)cin >> b[i];
    for(int i=0;i<n;i++)cin >> c[i];
    sort(a,a+n);
    sort(b,b+n);
    sort(c,c+n);
    int i=0,j=0;
    long long int ans=0;
    for(int k=0;k<n;k++){
        while(b[k]>=c[i])i++;
        q[k]=n-i;
    }
    for(int k=n-1;k>=0;k--)p[k]=p[k+1]+q[k];
    for(int k=0;k<n;k++){
        while(a[k]>=b[j])j++;
        ans += p[j];
    }
    cout << ans;
}