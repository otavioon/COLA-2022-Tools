#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int64_t n;
  cin >> n;
  priority_queue<int, vector<int>, greater<int>> pq;
  
  for(int i=1; i<=sqrt(n); i++){
    int sum=0;
    if(n%i==0){
      while((n/i)%10!=0){
        n/i/10;
        sum++;
      }
      pq.push(sum);
    }
  }
  
  cout << pq.top() << endl;
}