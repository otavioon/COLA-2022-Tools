#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>

int main(void){
    int n, k;
    std::cin >> n >> k;
    std::set<int> s;
    for(int i = 0; i < n; ++i){
        int tmp;
        std::cin >> tmp;
        s.insert(tmp);
    }
    while(true){
        int tmp = n;
        while(tmp > 0){
            if(s.end() != s.find(tmp % 10)){
                ++n;
                break;
            }
            tmp /= 10;    
        }
        if(0 == tmp) break;
    }
    std::cout << n << std::endl;

    return 0;
}