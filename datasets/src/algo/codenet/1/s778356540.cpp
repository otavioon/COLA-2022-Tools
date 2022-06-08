#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main (){
    int c[9],saA,saB;
    for(int i=0;i<9;i++){
        cin >> c[i];
        }
    saA=c[3]-c[0];
    saB=c[6]-c[3];
    if(c[4]==c[1]+saA&&c[5]==c[2]+saA&&c[7]==c[4]+saB&&c[8]==c[5]+saB){
        cout<<"Yes";
    }else{
        cout<<"No";
    }
    return 0;
}