#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    int c = 0;
    for(size_t i = 0; i < 9; i++)
    {
        int cc;
        cin >> cc;
        c += cc;
    }
    if (c%3==0) {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    
    
    return 0;
}