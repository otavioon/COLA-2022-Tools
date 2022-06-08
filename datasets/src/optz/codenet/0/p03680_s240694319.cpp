#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){

    int n;
    int count;
    int light=1;
    bool able=false;
    vector<int> a(10000);

    cin>>n;

    for(int i=0;i<n;i++){
        cin>>a.at(i);
    }

    for(int i=0;i<n;i++){
        
        light=a.at(light-1);
        if(light==2) able=true;
        count=i+1;
        if(able) break;

    }

    if(able) cout<<count<<endl;
    else cout<<-1<<endl;







    return 0;
}