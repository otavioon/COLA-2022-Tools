#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,Q;
  cin >> N >> Q;
  vector<pair<int,int>> ab(N-1);
  int a,b;
  int loop;
  for(loop=0;loop<N-1;loop++){
    cin >> a >> b;
    ab[loop]=make_pair(a,b);
  }
  sort(ab.begin(),ab.end());
  vector<int> p(N,0);
  for(loop=0;loop<Q;loop++){
    cin >> a >> b;
    p[a-1]+=b;
  }
  for(loop=0;loop<N-1;loop++){
    p[ab[loop].second]+=p[ab[loop].first];
  }
  for(loop=0;loop<N;loop++){
    cout << p[loop];
    if(loop<N-1){
      cout << " ";
    }else{
      cout << endl;
    }
  }
  return 0;
}
