#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include <cmath>
using namespace std;
int main(){
    int n,k;
    cin >> n >> k;
    vector<int> D(10,10);
    vector<int> number;
    for(int i=0;i<k;i++){
        cin >>D[i];
    }
    for(int j=0;j<10;j++){
        if(find(D.begin(),D.end(),j)==D.end())
        number.push_back(j);
    }
    vector<int> keta;
    for(int i=0;i<4;i++){
        keta.push_back(n%10);
        if(n/10!=0){
        n =n/10;
        }else break;
        if(i>0){
            swap(keta[i],keta[i-1]);
        }
    }
    // for(int m=0;m<keta.size();m++){
    //     cout << keta[m] <<endl;
    // }
    for(int m=0;m<keta.size();m++){
        for(int l=0;l<number.size();l++){
            if(number[l]>keta[m]){
            swap(number[l],keta[m]);
            break;
            }
        }
    }
    int ans=0;
    for(int m=0;m<keta.size();m++){
        ans+=keta[m]*pow(10,3-m);
    }
    cout << ans <<endl;
    return 0;
}