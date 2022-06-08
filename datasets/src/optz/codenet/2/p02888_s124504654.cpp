#include <iostream>
#include <iterator>
#include <map>

long long factorial(long long a){
    long long write = 1;
    for(long long i = 1; i <= a; ++i){
        write *= i;
    }
    return write;
}

long long choose(long long n, long long r){
    long long write = 0;
    if(n >= r){
        write = factorial(n) / factorial(r) / factorial(n - r);
    }
    return write;
}

int main(){
    long long n;
    std::cin >> n;
    
    std::multimap<long long, long long> sticks;
    for(long long i = 0; i < n; ++i){
        long long val;
        std::cin >> val;
        auto itr = sticks.find(val);
        if(sticks.end() != itr){
            ++itr->second;
        }else{
            sticks.insert(std::make_pair(val, 1));
        }
    }

    long long count = 0;
    for(auto itrA = sticks.begin(); sticks.end() != itrA; ++itrA){
        long long a = itrA->first, aNum = itrA->second;

        for(auto itrB = itrA; sticks.end() != itrB; ++itrB){
            long long b = itrB->first, bNum = itrB->second;

            for(auto itrC = itrB; sticks.end() != itrC; ++itrC){
                long long c = itrC->first, cNum = itrC->second;

//                    std::cout << aNum << std::endl;

                if(a < b + c && b < c + a && c < a + b){
                    if(3 <= aNum && a == b && b == c && c == a){
                        count += choose(aNum, 3);
                    }else if(2 <= aNum && a == b && c != a){
                        count += choose(aNum, 2) * cNum;
                    }else if(2 <= bNum && b == c && a != b){
                        count += choose(bNum, 2) * aNum;
                    }else if(2 <= cNum && c == a && b != c){
                        count += choose(cNum, 2) * bNum;
                    }else if(a != b && b != c && c != a){
                        count += aNum * bNum * cNum;
                    }
//    std::cout << a << ", " << b << ", " << c << ": " << count << std::endl;
                }
            }
        }
    }

    std::cout << count << std::endl;

    return 0;
}