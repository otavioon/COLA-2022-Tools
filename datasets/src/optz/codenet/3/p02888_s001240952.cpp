#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    sort(a,a+n);
    int count = 0;
    for( int i = n-1; i >= 1; i--){
        int l = 0, r = i-1;
        while( l < r){
            if( a[l] + a[r] > a[i]){
                count += r - l ;
                r--;
            }
            else
                l++;
        }
    }
    cout<<count<<endl;
    return 0;
}
