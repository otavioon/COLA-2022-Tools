#include <bits/stdc++.h>
using namespace std;

int a[3]={};
int b[3]={};
int c[3][3]={};

int main(){
    for (int i=0;i<3;++i){
        for (int j=0;j<3;++j){
            cin >> c[i][j];
        }
    }
    for (int i=0;i<3;++i){
      for (int j=0;j<3;++j){
          if (a[i]+b[j]==c[i][j]){
              cout << "Yes" << endl;
              return 0;
          }
      }
    }
   cout << "No" << endl;
}