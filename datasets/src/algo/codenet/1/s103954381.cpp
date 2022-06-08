#include<iostream>
using namespace std;
int c[3][3];
int a[3],b[3];
int main(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>c[i][j];
        }   
    }   
    for(int i=0;i<3;i++) b[i]=c[0][i];        
    bool x=((c[1][0]-b[0])==(c[1][1]-b[1]))&( (c[1][0]-b[0])==(c[1][2]-b[2]));                                                          
    bool y=((c[2][0]-b[0])==(c[2][1]-b[1]))&((c[2][0]-b[0])==(c[2][2]-b[2]));
    cout<<(x&y?"Yes":"No")<<"\n";
    return 0;
}
