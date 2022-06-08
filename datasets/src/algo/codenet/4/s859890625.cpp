#include<iostream>
#include<set>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    int d[k];
    for(int i=0;i<k;i++){
        cin>>d[i];
    }
    for(int i=n;i<100000;i++){
        int tmp=i;
        set<int>s;
        while(tmp!=0){
            s.insert(tmp%10);
            tmp/=10;
        }
        bool flag=true;
        for(int j=0;j<k;j++){
            if(s.count(d[j])) flag=false;
        }
        if(flag){
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}