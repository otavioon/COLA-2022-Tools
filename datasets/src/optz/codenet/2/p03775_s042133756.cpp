#include<iostream>

int main(){
    long long N;
    std::cin >> N;
    
    long long max = 10000000000;
    while(max * max > N){
        max = (max + N / max) / 2;
    }
    int i;
    for(i=max;i>=2;i--){
        if(N % i == 0){
            break;
        }
    }
    
    int j = N / i;
    int digit = 0;
    while(j != 0){
        j /= 10;
        digit++;
        
    }
    
    std::cout << digit << std::endl;
    return 0;
}

