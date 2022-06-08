#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int main(void){

    long n;
    cin >> n;

    multiset<long> nums;

    while(n--){
        long tmp;
        scanf("%d",&tmp);
        nums.insert(tmp);
    }

    long ans = 0;

    while(!nums.empty()){
        long nval = *nums.begin();
        nums.erase(nums.begin());

        for(long d = 30; d >=0 ;d--){
            long cval = (1<<d) - nval;
            //if(cval < 0 )break;

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
