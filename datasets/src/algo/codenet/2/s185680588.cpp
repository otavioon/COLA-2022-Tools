#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int main(void){

    int n;
    cin >> n;

    multiset<int> nums;

    while(n--){
        int tmp;
        scanf("%d",&tmp);
        nums.insert(tmp);
    }

    int ans = 0;

    while(!nums.empty()){
        int nval = *nums.begin();
        nums.erase(nums.begin());

        for(int d = 30; d >=0 ;d--){
            int cval = (1<<d) - nval;
            if(cval < 0 )break;

            if(nums.find(cval) != nums.end()){
                nums.erase(nums.find(cval));
                ans++;
                break;
            }
        }
    }

    cout << ans;

    return 0;
}
