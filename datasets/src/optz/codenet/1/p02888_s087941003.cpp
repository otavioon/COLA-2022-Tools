#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,d,i=0;
    cin>>n;
    int l[1001]={};
    int ans=0;
    while(i<n){
        cin>>d;
        l[d]++;
        i++;
    }
    for (int j = 1; j < 1001; j++)
    {
        for (int k = j; l[j]>0, k < 1001; k++)
        {
            for (int m = k; l[k]>0, m<1001; m++)
            {
                if(l[m]>0){
                    if(j==k){
                        if(k==m){
                            ans+=l[j]*(l[j]-1)*(l[j]-2)/6;
                        }else{
                            if(j<(k+m)&&k<(j+m)&&m<(j+k))
                            ans+=l[j]*(l[j]-1)*l[m]/2;
                        }
                    }else if(k==m){
                        if(j<(k+m)&&k<(j+m)&&m<(j+k))
                            ans+=l[k]*(l[k]-1)*l[j]/2;
                    }else if(j==m){
                        if(j<(k+m)&&k<(j+m)&&m<(j+k))
                            ans+=l[j]*(l[j]-1)*l[k]/2;
                    }else{
                        if(j<(k+m)&&k<(j+m)&&m<(j+k)){
                            ans+=l[j]*l[k]*l[m];
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}




