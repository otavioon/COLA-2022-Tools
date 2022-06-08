#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> a(2);
    int i;
    for(i = 0; ;i++){
        scanf("%d %d", &a.at(0), &a.at(1));
        if(a.at(0) == 0 && a.at(1) == 0) break;
        sort(a.begin(), a.end());
        printf("%d %d\n", a.at(0), a.at(1));
    }
}
