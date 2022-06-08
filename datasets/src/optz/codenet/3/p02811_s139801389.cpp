#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef long long ull;
typedef long double ld;

int main(){

    int a;cin >> a;
    vector<int>data_1(a),data_2(a);
    for(int i = 0;i<a;i++)
        cin >> data_1[i];
    for(int i = 0;i<a;i++)
        cin >> data_2[i];

        int ans = 0;
    while(data_1!=data_2){
        ans++;
        next_permutation(data_1.begin(),data_1.end());

    }
    cout << ans;
    return 0;
}






