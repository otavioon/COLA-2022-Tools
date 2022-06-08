#include <iostream>
#include <vector>
using namespace std;
int main(void){
    int n,s;
    vector<int> a,b;
    s = 0;
    cin >> n;
    for(int i=0; i<n; i++){
        int c;
        cin >> c;
        b.push_back(c);
    }
    
    a.push_back(b[0]);
    for(int j=1; j<n-1; j++){
        if(b[j-1]<=b[j]){
            a.push_back(b[j-1]);
        }
        else{
            a.push_back(b[j]);
        }
    }
    a.push_back(b[n-1]);
    
    for(int k=0; k<n; k++){
        s += a[k];
    }
    
    cout << s << endl;
}