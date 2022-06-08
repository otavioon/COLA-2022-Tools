#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <forward_list>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <bitset>
#include <memory>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <cstring>
#include <cstdlib>
#include <cstdint>

using namespace std;

set<int> prime;

void calc_prime(int mm) {
    int cur = 2;
    while(cur <= mm) {
        for(auto itr = prime.begin();itr != prime.end();itr++) {
            if(cur % *itr == 0)
                goto not_prime;
        }
        prime.insert(cur);
    not_prime:
        cur++;
    }
}

int main(void) {
    int n,res = 0;
    cin >> n;
    if(n % 2 == 0)
        res = n;
    else
        res = 2 * n;
    cout << res << endl;
    return 0;
}
