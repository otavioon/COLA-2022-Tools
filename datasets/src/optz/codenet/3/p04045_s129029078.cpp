#include <iostream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>
using namespace std;
typedef long long ll;

int main(){

    int n, k; cin >> n >> k;

    int d[k];
    for(int i=0; i<k; i++){
        cin >> d[i];
    }

    vector<int> vgood;
    for(int i=0; i<10; i++){
        for(int j=0; j<k; j++){
            if(i == d[j]){
                break;
            }
            if(j == k-1){
                vgood.push_back(i);
            }
        }
    }

    int ngood = vgood.size();

    int ntemp = n;
    int nprice = 0;
    vector<int> price;
    while(ntemp > 0){
        nprice++;
        price.push_back(ntemp%10);
        ntemp /= 10;
    }

    reverse(price.begin(), price.end());

    vector<int> ans;
    bool same = true;
    bool ngflag = false;
    for(int i=0; i<nprice; i++){
        if(same == false){
            ans.push_back(vgood[0]);
            continue;
        }
        for(int j=0; j<ngood; j++){
            if(price[i] == vgood[j]){
                ans.push_back(vgood[j]);
                break;
            }
            if(price[i] < vgood[j]){
                ans.push_back(vgood[j]);
                same = false;
                break;
            }
            if(j == ngood-1){
                ngflag = true;
                break;
            }
        }
        if(ngflag){
            break;
        }
    }

    if(ngflag){
        ans.clear();
        if(vgood[0] == 0){
            ans.push_back(vgood[1]);
        }
        else{
            ans.push_back(vgood[0]);
        }
        
        for(int i=0; i<nprice; i++){
            ans.push_back(vgood[0]);
        }
    }

    for(auto x : ans){
        cout << x;
    }

    return 0;
}