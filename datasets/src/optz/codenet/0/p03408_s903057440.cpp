#include <bits/stdc++.h>
using namespace std;

int main() {
  
  std::vector<std::string> keys; 
  std::vector<int> scores;
  
  string str; // dummy 
  
  int N;
  cin >> N;
  for(int i = 0; i < N; i++)
  {
   	cin >> str; 
    std::vector<string>::iterator iter = std::find(keys.begin(), keys.end(), str);
    if( iter == keys.end() )
    {
      keys.push_back(str);
      scores.push_back(1);
    }
    else
    {
      scores.at(iter - keys.begin()) += 1;
    }     
  }
  
  int M;
  cin >> M;
  for(int i = 0; i < M; i++)
  {
    cin >> str; 
    std::vector<string>::iterator iter = std::find(keys.begin(), keys.end(), str);
    if( iter == keys.end() )
    {
      keys.push_back(str);
      scores.push_back(-1);
    }
    else
    {
      scores.at(iter - keys.begin()) -= 1;
    }     
  }

  int maxval = 0;              
  for(int i = 0; i < scores.size(); i++)
  {
    maxval = max(maxval, scores.at(i));
  }

  cout << maxval << endl;              
}
