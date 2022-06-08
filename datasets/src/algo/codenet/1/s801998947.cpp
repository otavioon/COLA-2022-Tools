typedef long long ll;
#include <bits/stdc++.h>
using namespace std;
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

int main() {
    ll c[10];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cin >> c[i*3+j];
        }
    }
    if(c[0]-c[3] == c[1]-c[4] && c[1]-c[4] == c[2] -c[5] && c[0] -c[6] == c[1] - c[7] && c[1] -c[7] == c[2] -c[8] ){
        std::cout << "Yes" << std::endl;
    }else{
        std::cout << "No" << std::endl;
    }
}