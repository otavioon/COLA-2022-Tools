#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair


int hasDisliked(int N, set<char> &disliked){
  string check = to_string(N);
  for(auto i : check){
    if (disliked.count(i))
      return 1;
  }
  
  return 0;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int N, K;
  char curr;
  set<char> disliked;
  cin >> N >> K;
  while(K--){
	cin >> curr;
    disliked.insert(curr);
  }
  
  while(hasDisliked(N, disliked)){
    ++N;
  }
  
  cout << N << "\n";
  
  return 0;

}
