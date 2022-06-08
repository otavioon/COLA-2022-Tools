#include <iostream>
#include <math.h>
#include <stdio.h>
#include <vector>
#include <algorithm>

int main()
{
    int moke,a,count = 0;
    std::cin >> moke;
    std::vector<int>x,y,z;
    for(int s = 0;a < 3;a++){
        for(int b = 0;b <moke;b++){
            std::cin >> a;
            if(s == 0){
                x.push_back(a);
            }
            if(s == 1){
                y.push_back(a);
            }
            if(s == 2){
                z.push_back(a);
            }
        }
    }
    std::sort(x.begin(),x.end());
    std::sort(y.begin(),y.end());
    std::sort(z.begin(),z.end());
    for(int s = 0;s < moke;s++){
           for(int w = 0;w < moke;w++){
               for(int q = 0;q < moke;q++){
                   if(x[s] < y[w] && y[w] < z[q]){
                       //std::cout << hoge[0][x]<<" "<<hoge[1][y]<<" "<<hoge[2][z]<<std::endl;
                       count++;
                   }
               }
           }
       }
    std::cout <<count<<std::endl;
    return 0;
}
