#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <chrono>
using namespace std;

int main(int argc, const char * argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a.at(i);
    }
    
    int cnt = 0;
    int light = 1;
    set<int> list;
    while (light != 2) {
        if (list.count(light) == 1) {
            cout << "-1" << endl;
            return 0;
        } else {
            list.insert(light);
            light = a.at(light - 1);
            cnt++;
        }
    }
    cout << cnt << endl;

    return 0;
}
