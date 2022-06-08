#include <bits/stdc++.h>
using namespace std;

int keta(long num){
  for(int i = 1;i<10+1;i++){
    if(num/10 != 0){
      num = num/10;
    }
    else{
      return i;
    }
  }
}

int main(){
  long N;
  cin >> N;
  priority_queue<long, vector<long>,greater<long>> pq;
  for(int i=1;i<=sqrt(N);i++){
    if(N%i==0){
      long A = i;
      long B = N / A;      
      // cout<< max(keta(A),keta(B)) << endl;
      pq.push(max(keta(A),keta(B)));
    }
  }
  cout<< pq.top() << endl;
}
