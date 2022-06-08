#include<iostream>
#include<cstring>
using namespace std;

int main(){
    int n, k;
    bool d[10];
    memset(d, false, sizeof(d));
    cin >> n >> k;
    for(int i=0;i<k;i++){
        int tmp;cin>>tmp;
        d[tmp]=true;
    }
    while(1){
        int tmp=n;
        bool ans=false;
        while(tmp>0){
            ans|=d[tmp%10];
            tmp/=10;
            if(ans)break;
        }
        if(!ans)break;
        n++;
    }
    cout << n << endl;
}