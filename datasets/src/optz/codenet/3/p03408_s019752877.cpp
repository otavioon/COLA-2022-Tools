#include"bits/stdc++.h"
using namespace std;

int main(){
    int N,M;
    int max;
    cin>>N;
    string blue[N];
    vector<int>count(N,0);
    for(int i=0;i<N;i++){
        cin>>blue[i];
    }
    cin>>M;
    string red[M];
    for(int i=0;i<M;i++){
        cin>>red[i];
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(blue[i]==blue[j]){
                count[i]++;
            }
        }
        for(int j=0;j<M;j++){
            if(blue[i]==red[j]){
                count[i]--;
            }
        }
    }

    for(int i=1;i<N;i++){
        if(count[i]>=count[i-1]){
            max=count[i];
        }
    }
    cout<<max<<endl;
    return 0;
}