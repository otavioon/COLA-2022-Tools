#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  string r[110],b[110];
  cin >> N >> M;
  for(int i=0; i<N; i++) cin >> b[i];
  for(int i=0; i<M; i++) cin >> r[i];


  int max=0;
  for(int i=0; i<N; i++){
    int count=0;
    if(b[i]!="owari"){
      
      for(int j=0; j<N; j++){
        if(b[i]==b[j] && b[j]!="owari"){
          count++;
          b[j]="owari";
        }
      }   
      for(int k=0; k<M; k++){
        if(b[i]==r[k]) count--;        
      }
      
    }
    
    if(count>max) max=count;
    
  }
  
  
  cout << max << endl;
  
}
