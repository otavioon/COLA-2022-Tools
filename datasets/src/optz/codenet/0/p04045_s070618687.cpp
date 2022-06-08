#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main(int argc, char const *argv[])
{
    int N, K;
    std::cin >> N >> K;

    std::vector<int> D(K);
    for (int i = 0; i < K; i++) {
        std::cin >> D[i];
    }
    
    int i;
    for (i = N;; i++) {
        int x = i;
        bool dislike = false;
        while (x > 0) {
            int y = x % 10;
            // std::cout << y << " ";
            auto it = std::find(D.begin(), D.end(), y);
            if (it != D.end()) { // found
                dislike = true;
                break;
            }
            x = x / 10;
        }
        if (!dislike) break;
    }
    std::cout << i << std::endl;
    return 0;
}