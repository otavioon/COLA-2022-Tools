#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    vector<int> a;
    cin >> n;
    for(int i=0;i<n;i++){
        int tmp;
        cin>> tmp;
        a.push_back(tmp);
    }
    int ct=0;
    int i=0;
    for(;;){
        if(i==1){
            cout<< ct<<endl;
            break;
        }

        if(ct>=n){
            cout << -1 << endl;
            break;
        }
        ct++;
        i = a[i]-1;
    }
}
