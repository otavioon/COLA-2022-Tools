#include <iostream>
int main(){int c[9],i;for(i=0;i<9;i++)std::cin>>c[i];std::cout<<(c[0]+c[4]+c[8]==c[1]+c[5]+c[6]&&c[0]+c[4]+c[8]==c[2]+c[3]+c[7]?"Yes":"No");}