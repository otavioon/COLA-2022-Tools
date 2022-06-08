#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    int b[n-1];
    int ans=0;
    for(int i=0;i<n-1;i++) scanf("%d",&b[i]);
    if(b[1]>=b[0]) ans+=b[0]+b[0];
    else ans+=b[0]+b[1];
    for(int i=1;i<n-1;i++){
        if(b[i+1]>=b[i]) ans+=b[i];
        else ans+=b[i+1];
    }
    printf("%d\n",ans);
}