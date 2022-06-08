#include<bits/stdc++.h>
#define int long long
int a[114514];
using namespace std;
signed main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int sum=0;
    for(int i=0;i<n;){
        if(a[i]==2){
            cout<<sum+1<<endl;
            return 0;
        }
        else{
            i=a[i]-1;
            sum++;
        }
        if(sum>114514810){
            break;
        }
    }
    cout<<-1<<endl;
}