#include<iostream>
using namespace std;
int main(){
int c[3][3];
int i,j;
for(i=0;i<3;i++){
   for(j=0;j<3;j++){
       cin >>c[i][j];
   }
}
int p1,p2,p3,p4,p5,p6;
p1=c[0][1]-c[0][0];
p2=c[1][1]-c[1][0];
p3=c[2][1]-c[2][0];
p4=c[0][2]-c[0][0];
p5=c[1][2]-c[1][0];
p6=c[2][2]-c[2][0];
if(((p1==p2)&&(p2==p3))&&((p4==p5)&&(p5==p6))){
cout<<"Yes";
}else{
cout<<"No";
}
return 0;
}