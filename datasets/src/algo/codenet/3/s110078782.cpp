#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n],b[n],c[n];
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
    int count=0;
    for(int i=n-1;i>=0;i=i-1){
        for(int j=0;j<n;j++){
            if(c[i]<=b[j]){
                break;
            }
            for(int k=0;k<n;k++){
                if(a[k]>=b[j]){
                    break;
                }
                count++;
            }
        }
    }
    cout<<count;
    return 0;
}