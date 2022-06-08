#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <climits>
int main()
{
    long c[9];
    long sum=0;
    for(long i=0; i<9; i++){
        std::cin >> c[i];
        sum+=c[i];
    }
    if(sum==(c[0]+c[4]+c[8])*3){
        std::cout << "Yes" << std::endl;
    }else{
        std::cout << "No" << std::endl;
    }
    return 0;
}