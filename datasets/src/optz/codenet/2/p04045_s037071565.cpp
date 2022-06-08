#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int yen, k;
    vector<int> nums(k);
    cin >> yen >> k;
    while (k > 0) {
        int n;
        cin >> n;
        nums.push_back(n);
        k--;
    }
    sort(nums.begin(), nums.end(), greater<>());
    cout << nums[0] * yen << endl;
}