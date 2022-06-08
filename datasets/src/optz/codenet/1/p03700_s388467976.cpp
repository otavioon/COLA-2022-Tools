#include <algorithm>
#include <iomanip>
#include <istream>
#include <map>
#include <numeric>
#include <ostream>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    long n, a, b;
    vector<long> h;

    bool enough(long t)
    {
        long sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += (long)ceil((h[i] - b * t) / (double)(a - b));
            if (sum > t)
            {
                return false;
            }
        }

        return true;
    }

    void solve(std::istream& in, std::ostream& out) {
        in >> n >> a >> b;
        for (int i = 0; i < n; i++)
        {
            long tmp;
            in >> tmp;
            h.push_back(tmp);
        }

        long l, c, r;
        l = 1;
        r = 1000000000;
        c = 1000;
        while (l < r)
        {
            if (enough(c))
            {
                r = c;
            }
            else
            {
                l = c + 1;
            }
            c = (l + r) / 2;
        }

        c = (l + r) / 2;

        out << c;
    }
};

void solve(std::istream& in, std::ostream& out)
{
    out << std::setprecision(12);
    Solution solution;
    solution.solve(in, out);
}


#include <fstream>
#include <iostream>


int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    istream& in = cin;


    ostream& out = cout;

    solve(in, out);
    return 0;
}


