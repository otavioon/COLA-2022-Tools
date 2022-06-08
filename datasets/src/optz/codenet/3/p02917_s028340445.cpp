#include<iostream>
using namespace std;
#include<string>
#include<utility>
#include<algorithm>

int main(){
    int N;
    cin >> N;
    int B[N];
    for(int i=0;i<N-1;++i){
        cin >> B[i];
    }
    int C[N];
   for(int i=0;i<N-1;++i){
       C[i]=B[i];
   }
   sort(C,C+N-1);
   int res=2*C[0];
   for(int i=1;i<N-1;++i){
    if(B[i]>C[i]){
        res+=C[i];
    }
    else{
        res+=B[i];
    }
    }
    cout << res;
}