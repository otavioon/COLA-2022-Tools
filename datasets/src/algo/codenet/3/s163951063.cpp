#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
    int n,a[100000],b[100000],c[100000],p=0,q=0;
    long long s=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    sort(a,a+n);
    sort(b,b+n);
    sort(c,c+n);
    for(int i=0;i<n;i++){
        for(int j=p;j<n;j++){
            if(a[j]>=b[i]){
                p=j;
                j=n;
            }else if(j==n-1){
                p=n;
            }
        }
        for(int j=q;j<n;j++){
            if(c[j]>b[i]){
                q=j;
                j=n;
            }else if(j==n-1){
                q=n;
            }
        }
        s+=p*(n-q);
        
    }
    cout<<s<<endl;
}
