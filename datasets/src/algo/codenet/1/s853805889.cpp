#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n,sum=0;
    for(int i=0;i<9;i++){
        cin>>n; sum+=n;
    }
    if(sum%3==0) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
