#include <bits/stdc++.h>
using namespace std;
int main(void){
    vector<vector<int>> t(3,vector<int>(3));
    vector<int> a(3,9999);
    int i,j,k,q,mn;
    for(i=0;i<3;i++){
        mn=999;
        for(j=0;j<3;j++){
            cin>>t[i][j];
            mn=min(t[i][j],mn);
        }
        a[i]=mn;
    }
    
    for(i=0;i<=a[0];i++){
        for(j=0;j<=a[1];j++){
            for(k=0;k<=a[2];k++){
                for(q=0;q<3;q++){
                    if(!(t[0][q]-i==t[1][q]-j&&t[1][q]-j==t[2][q]-k)){
                        break;
                    }
                }
                if (q==3){
                    cout<<"Yes"<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<"No"<<endl;
    return 0;
}
