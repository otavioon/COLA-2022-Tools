#include <iostream>
#include <vector>
using namespace std;

int main(int argc,char* argv[])
{
    int n,i,a;
    cin >> n;
    vector<bool> button(n,0);

    button.at(0) = true;

    for(i=0;i<n;i++) {
        cin >> a;

        if(button.at(i)) {
            button.at(i) = false;
            button.at(a-1) = true;

            if(a==2) {
                cout << i;
                return 0;
            }
        }
    }

    cout << -1;

    return 0;
}