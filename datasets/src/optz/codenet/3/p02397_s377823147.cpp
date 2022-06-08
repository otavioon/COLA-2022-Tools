#include <bits/stdc++.h>
using namespace std;

int main(){
   
   while(1){
       vector<int>vec(2);
       cin >>vec.at(0)>>vec.at(1);
       if((vec.at(0) != 0)||(vec.at(1) != 0)){
            sort(vec.begin(), vec.end());
            cout << vec.at(0)<<" "<<vec.at(1)<< endl;
       }else{
           break;
       }
   }
}
