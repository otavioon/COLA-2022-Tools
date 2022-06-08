#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>a(100);
    for(int i; i<n; i++){
        cin>>a.at(i);
    }
    bool check=false;
    int count = 0;
    int tmp = a.at(0);
    for(int i=0; i<n; i++){
        count++;
        if(tmp==2){
            check = true;
            break;
        }
        tmp=a.at(tmp-1);
    }
    if(check)cout<<count<<endl;
    else cout<<"-1"<<endl;

}