#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,k;
  cin >> n >> k;
  set<int> d;
  for(int i=0;i<k;i++){
     int dinput;
     cin >> dinput;
     d.insert(dinput);
    }

 for(int i=n;i<100000;i++){
     int m=i;
     bool flag = 0;
     set<int> nn;
     while(m > 0){
         nn.insert(m % 10);
         m /= 10; 
      }
     for(auto it=nn.begin();it!=nn.end();it++){
              if(d.count(*it)){
              flag = 1;
              break;
            }
        }
        if(flag == 0){
            cout << i << endl;
            return 0;
        }
    }
 return 0;
}