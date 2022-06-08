#include <iostream>
#include <set>

#define SIZE 10

int k;
std::string     n;
std::set< int > D;

void solve() {
    int movingup = 0;
    std::string ans = "";
    for (int i=n.size()-1; i>-1; --i) {
        int digit = n[i] - '0';
        if ( D.find( digit ) != D.end() ) {
            digit += movingup;
            movingup = 0;
            while (D.find(digit) != D.end()) {
                if (digit > 9) {
                    digit = 0;
                    ++movingup;
                }
                ++digit;
            }
            char c = digit + '0';
            ans = c + ans;
        } else {
            ans = n[i] + ans;
        }
        std::cout << "Debug : " << ans << std::endl;
    }
    if (movingup) {
        char x = movingup + '0';
        ans = x + ans;
    }
    std::cout << ans << std::endl;
}

int main() {
    std::cin >> n >> k;
    for (int i=0; i<k; ++i) {
        int idx;
        std::cin >> idx;
        D.insert( idx );
    }
    solve();
    return 0;
}