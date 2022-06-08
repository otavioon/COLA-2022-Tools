#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;

    cin >> n;

    //vector<int> a(n);
    int a[n];

    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    int amount = 1,place = a[0];

    while(place!=1 && place!=2){
        amount++;
        place = a[place-1];
    }

    if(place == 1){
        cout << -1 << endl;
    }else{
        cout << amount << endl;
    }
    
}