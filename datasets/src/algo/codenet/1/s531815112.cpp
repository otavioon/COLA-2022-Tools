#include <bits/stdc++.h>
using namespace std;
int c[9];
int main(){
  for(int i=0;i<9;i++)cin>>c[i];
  puts(c[1]-c[0]==c[4]-c[3]&&c[1]-c[0]==c[7]-c[6]&&c[2]-c[1]==c[5]-c[4]&&c[2]-c[1]==c[8]-c[7]?"Yes":"No");
}