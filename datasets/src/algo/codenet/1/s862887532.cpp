#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <math.h>
#include <string>
#include <map>
#include <cstdlib>
using namespace std;

typedef long long ll;

int main()
{
    int c[3][3];
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cin >> c[i][j];
        }
    }
    if(c[1][1]==c[0][1]+c[1][0]-c[0][0] && c[1][2]==c[0][2]+c[1][0]-c[0][0] && c[2][1]==c[0][1]+c[2][0]-c[0][0] && c[2][2]==c[0][2]+c[2][0]-c[0][0]) cout << "Yes";
    else cout << "No";
    

    return 0;
}
