#include <iostream>

using namespace std;

int main()
{
    int c[9]={0};
    for (int i=0; i<9; i++) {
        cin>>c[i];
    }
    for (int i=0; i<2; i++) {
        int b2 = c[i]-c[i+1];
        for (int j=0; j<2; j++) {
            if(b2!=c[i+3*(j+1)]-c[i+1+3*(j+1)]){
                cout<<"No"<<endl;
                return 0;
            }
        }
    }
    
    cout<<"Yes"<<endl;
    return 0;
}