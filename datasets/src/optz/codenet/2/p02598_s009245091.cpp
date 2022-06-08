#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k,t;
    cin >> n >> k;
    priority_queue<int> pq;
    for(int i = 0;i < n;i++){
        cin >> t;
        pq.push(t);
    }
    while(k--){
        int temp1 = pq.top();
        int temp = pq.top()/2;
        pq.pop();
        pq.push(temp);
        pq.push(temp1 - temp);
    }
    t = pq.top();
    cout<<t<<"\n";
}