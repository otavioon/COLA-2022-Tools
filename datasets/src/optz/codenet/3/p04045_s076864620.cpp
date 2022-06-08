#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
    
int main()
{
    int N;
    cin >> N;
    int K;
    cin >> K;
    vector<int> D(K);
    for( int i = 0;i < K; ++i ){
        cin >> D[i]; 
    }
    sort(D.begin(),D.end());
    int keta = 0;
    int result[4];
    int c = N;
    do{
        int a = c % 10;
        c = c / 10;
        for( int i = a; i < 10; ++i ){
            if( find(D.begin(), D.end(), i) == D.end() ){ 
                result[keta] = i;
                ++keta;
                break;
            } 
        }
    }while(c > 0);
    for( int i = keta - 1;i >= 0; --i ){
        cout << result[i];
    }
    cout << endl;
    return 0; 
}