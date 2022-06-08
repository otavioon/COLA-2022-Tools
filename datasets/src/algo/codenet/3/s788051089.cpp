#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(void){
    // Your code here!
    int n;
    cin>>n;
    vector<int> s(n),t(n),u(n);
    for(int i=0;i<n;i++)cin>>s[i];
    for(int i=0;i<n;i++)cin>>t[i];
    for(int i=0;i<n;i++)cin>>u[i];
    int ans=0;
    for(int x:t){
        int num1=0,num2=0;
        for(int i=0;i<n;i++){
            if(s[i]<x)num1++;
        }
        for(int i=0;i<n;i++){
            if(u[i]>x)num2++;
        }
        ans+=num1*num2;
    }
    cout<<ans<<endl;
}
