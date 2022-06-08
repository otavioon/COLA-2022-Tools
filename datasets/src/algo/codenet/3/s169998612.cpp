#include <iostream>
#include <algorithm>
#include <math.h> 
#include <string>
#include <iomanip>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[100010], b[100010], c[100010];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    for(int i = 0; i < n; i++){
        cin >> c[i];
    }

    sort(a,a+n);
    sort(b,b+n);
    sort(c,c+n);
    int counter = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                if(a[i] < b[j] and b[j] < c[k]) counter++;
            }
        }
    }
    cout << counter << endl;
}