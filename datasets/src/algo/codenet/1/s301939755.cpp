#include <iostream>
#include <list>
#include <stack>
#include <limits.h>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <memory>
#include <regex>
#include <functional>
using namespace std;

int input[7][7];
int main() {
    int sum = 0;
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            cin >> input[i][j];
            sum += input[i][j];
        }
    }
    // consider a1 = 0 since we are just want to vaidate
    int a1 = 0;
    int b1 = input[0][0];
    int b2 = input[0][1];
    int b3 = input[0][2];
    int a2 = input[1][0] - b1;
    int a3 = input[2][0] - b1;

    if (input[1][1] != a2 + b2 || input[1][2] != a2 + b3 || input[2][1] != a3 + b2 || input[2][2] != a3 + b3)
    {
        cout << "No" << endl;
        return 0;
    }   
    cout << "Yes" << endl;
    return 0;
}
