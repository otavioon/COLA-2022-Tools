#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N,K;
    cin>>N>>K;
    vector<int> D(K);
    for(int i=0;i<K;i++) cin>>D[i];
    
    for(int i=0;i<100000;i++){
        int tmp=N+i;
        set<int> se;
        while(tmp>0){
            se.insert(tmp%10);
            tmp/=10;
        }
        
        bool check=false;
        for(int i=0;i<K;i++){
            if(se.count(D[i]))check=true;
        }
        
        if(!check){cout<<N+i<<endl;return 0;}
    }
}