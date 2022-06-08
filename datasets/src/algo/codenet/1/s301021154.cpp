#include <iostream>
using namespace std;

int main()
{
    int c[9];
    for(int i =0; i<9; i++){
        cin >> c[i]; 
    }
    int x1 = c[1] - c[0];
    int x2 = c[2] - c[0];
    int y1 = c[3] - c[0];
    int y2 = c[6] - c[0];
    if(c[4] - c[0] == x1 + y1 && 
       c[5] - c[0] == x2 + y1 &&
       c[7] - c[0] == x1 + y2 && 
       c[8] - c[0] == x2 + y2)
    {
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}