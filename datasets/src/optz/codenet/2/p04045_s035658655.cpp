#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define F(i,N) for(int i=0;i<N;i++)
int main(){
    cin.tie(0);
   	ios::sync_with_stdio(false);
    int N, K; cin >> N >> K;
    int D[9]; F(i,N) cin >> D[i];
    
    while(1){
        vector<int> num; int temp = N; bool flag = false;
        while(temp != 0){   
          	num.push_back(temp % 10);
            temp /= 10;
        }
        F(i,K){
            F(j, num.size()){
                if(num[j] == D[i]) flag = true;
            }
        }
        if(flag) N++;
        else break;
    }
    cout << N;
}