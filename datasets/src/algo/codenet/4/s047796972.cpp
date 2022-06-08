#include <bits/stdc++.h>
using namespace std;
int N,K;
set<int>st;
int main(){
    cin>>N>>K;
    for(int i=0;i<10;i++)st.insert(i);
    while(K--){
        int x;
        cin>>x;
        st.erase(x);
    }
    for(int i=N;i<1e5;i++){
        int tmp=i;
        bool b=true;
        while(tmp){
            if(st.find(tmp%10)==st.end()){
                b=false;
                break;
            }
            tmp/=10;
        }
        if(b){
            printf("%d\n",i);
            return 0;
        }
    }
    return 0;
}
