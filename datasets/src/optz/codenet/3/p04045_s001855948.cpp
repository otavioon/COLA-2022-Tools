/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author TM
 */


#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <functional>
#include <cmath>
#include <numeric>
#include <iterator>

#define SIZE 100005
#define MOD 1000000007

using namespace std;

class CIrohasObsession {
public:
    int func(string price, int n, set<string> diff) {
        if (price != "") {
            int int_price = stoi(price);
            if (int_price >= n) {
                return int_price;
            } else if (int_price == 0) {
                return 100000000;
            }
        }
        int ans = 100000000;
        for (const auto &item : diff) {
            ans = min(ans, func(price + item, n, diff));
        }
        return ans;
    }

    void solve(std::istream &cin, std::ostream &cout) {
        int n, k;
        cin >> n >> k;
        set<string> set_dont_use;
        set<string> set_all{"1", "2", "3", "4", "5", "6", "7", "8", "9", "0"};
        for (int i = 0; i < n; ++i) {
            string tmp;
            cin >> tmp;
            set_dont_use.insert(tmp);
        }
        set<string> set_diff;
        set_difference(set_all.begin(), set_all.end(), set_dont_use.begin(), set_dont_use.end(),
                       inserter(set_diff, set_diff.end()));
        cout << func("", n, set_diff) << endl;
    }
};


int main() {
    CIrohasObsession solver;
    std::istream &in(std::cin);
    std::ostream &out(std::cout);
    solver.solve(in, out);
    return 0;
}