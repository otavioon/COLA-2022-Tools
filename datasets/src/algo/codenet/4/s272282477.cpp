#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,K;
    set<int> dic;
    cin>>N>>K;
    for(int i=0; i<K; i++){
        int d;
        cin>>d;
        dic.insert(d);
    }

    for(int cur=N; cur<=10*N; cur++){
        string tmp;
        bool flag = true;
        tmp = to_string(cur);
        for(int i=0; i<tmp.size(); i++){
            int keta = tmp[i] - '0';
            if(dic.count(keta)){
                flag = false;
                break;
            }
        }
        if(flag){
            cout<<cur<<endl;
            return 0;
        }
    }
}