#include <bits/stdc++.h>
using namespace std;

int main(){

    int data[3][3],a[3]={0},b[3]={0};

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){

            cin>>data[i][j];
        }
    }

    int count =0;

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){

            

        if(i==0){
         b[j] = data[i][j] -a[i];
          }     

        if(b[j] < 0) break;

        else if(i != 0 && j == 0){

          a[i] = data[i][j] - b[j];
        }

        if( a[i] + b[j] != data[i][j]){

            a[i]++;

            i=0;
        }
      
        if(i == 2 && j == 2){
          if(a[i] + b[i] ==  data[i][j]) count++;
        }   

      } 
    } 

    if(count == 1) cout<<"Yes"<<endl;

    else if(count == 0) cout<<"No"<<endl;  

    return 0;

}