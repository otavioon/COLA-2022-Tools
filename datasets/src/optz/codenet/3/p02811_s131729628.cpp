#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int>p(N);
  vector<int>q(N);
  for(int i=0;i<N;i++){
    cin >> p.at(i);
  }
  for(int i=0;i<N;i++){
    cin >> 	q.at(i);
  }
  vector<int>order(N);
  for(int i=0;i<N;i++){
    order.at(i)=i;
  }
  int p_ans,q_ans;
  int count=1;
  do{
    bool p_if=true;
    bool q_if=true;
    for(int i=0;i<N;i++){
      if(p.at(i)!=order.at(i)) p_if=false;
      if(q.at(i)!=order.at(i)) q_if=false;
    }
    if(p_if) p_ans=count;
    if(q_if) q_ans=count;
    count++;
  }while(next_permutation(order.begin(),order.end()));
  cout << abs(p_ans-q_ans) << endl;
}
