#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    int sum = 0;

    int c;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin >> c;
            sum += c;
        }
    }

    if(sum % 3 == 0){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }

    return 0;
}