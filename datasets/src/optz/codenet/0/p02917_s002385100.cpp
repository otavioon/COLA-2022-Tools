#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int sum = 0;
    int prev = 0;
    for(int i=0; i<n-1; i++){
        int a;
        cin >> a;
        if(i == 0){
            sum += a;
            prev = a;
        }else{
            sum += min(a,prev);
            prev = a;
        }
        if(i == n-2) sum += a;
    }
    cout << sum << endl;
    return 0;
}
