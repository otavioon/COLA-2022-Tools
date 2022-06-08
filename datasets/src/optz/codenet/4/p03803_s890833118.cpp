#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b;
  cin >> a >> b;
  vector<string> A(a);
  vector<string> B(b);
  for(int i=0;i<a;i++)
    cin >> A.at(i);
  for(int i=0;i<b;i++)
    cin >> B.at(i);
    
  bool result = false;
  for(int ai = 0;ai< a-b+1;ai++){
    bool match = true;
    for(int aj = 0;aj < a-b+1;aj++){
      for(int i = 0;i<b;i++){
        for(int j = 0;j<b;j++){
          if(A.at(ai+i).at(aj+j) != B.at(i).at(j)){
            match = false;
            break;
          }
        }
      }
      if(match == true){
        result = true;
        break;
      }
    }
    if(match == true){
      result = true;
      break;
    }
  }
  if(result == true)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}