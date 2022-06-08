#include <iostream>
using namespace std;

int main() {
    int c[3][3];
    int sum=0;
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
        cin >> c[i][j];
        sum += c[i][j];
      }
    }

    if(sum%3==0) cout << "Yes" << endl;
    else cout << "No" <<endl;
}