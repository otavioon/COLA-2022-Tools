#include<bits/stdc++.h>
using namespace std;
int bag[100005];
int main()
{
    map <string, int> mp, mpp;
    map <string, int> :: iterator it;
    int x;
    cin >> x;
    while(x--){
        string s;
        cin >> s;
        mp[s]++;
    }
    int y;
    cin >> y;
    while(y--){
        string ss;
        cin >> ss;
        mpp[ss]++;
    }
    int Max = INT_MIN;
    for(it = mp.begin(); it != mp.end(); it++){
        if(it->second > mpp[it->first]){
            Max = max(Max, it->second - mpp[it->first]);
        }
        else Max = max(Max, 0);
    }
    cout << Max << "\n";
    return 0;
}
