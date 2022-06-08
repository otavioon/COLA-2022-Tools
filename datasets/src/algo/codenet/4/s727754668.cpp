#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N,K,i;
    cin>>N>>K;
    vector<int> D(K);
    for (int i=0;i<K;i++){
        cin>>D.at(i);
    }
    for (i=N;i<100000;i++){
        int tmp =i;
        set<int> s;
        while(tmp!=0){
            s.insert(tmp%10);
            tmp=tmp/10;
        }
        bool flag = true;
        for(int j=0;j<K;j++){
            if(s.count(D.at(j))){
                flag = false;
            }
        }
        if (flag){
            cout<<i<<endl;
            break;
        }
    }
}