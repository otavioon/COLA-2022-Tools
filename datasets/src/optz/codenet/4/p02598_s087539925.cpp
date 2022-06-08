#include <bits/stdc++.h>                
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    long long int k;
    cin>>n>>k;
    long long int a[n];
    for (int i=0;i<n;i++) cin>>a[i];
    long long int l=0;
    long long int r=1e9;
    while (l<r-1){
        long long int m=l+(r-l)/2;
        int cnt=0;
        if(m){
            for (int i=0;i<n;i++){
                if(a[i]>m){
                    if(a[i]%m) cnt+=a[i]/m;
                    else cnt+=a[i]/m-1;
                }
            }
        }    
        else{
            for (int i=0;i<n;i++){
                if(a[i]>m){
                    cnt+=a[i];
                }
            }
        }
        if(cnt<=k) r=m;
        else l=m;
    }
    int cnt=0;
    for (int i=0;i<n;i++){
        if(l){
            if(a[i]>l){
                if(a[i]%l) cnt+=a[i]/l;
                else cnt+=a[i]/l-1;
            }
        }    
        else{
            if(a[i]>l){
                cnt+=a[i];
            }
        }
    }
    if(cnt<=k) cout<<l<<"\n";
    else cout<<l+1<<"\n";
	return 0;
}