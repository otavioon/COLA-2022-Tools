#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL)
#define endl "\n"
#define ll long long
#define N ((int)(3e5 + 5))
#define MOD ((int)(1e9 + 7))


using namespace std;


/*fast io
ios_base::sync_with_stdio(false);
cin.tie(NULL);
*/

int arr[5][5];


int main()
{
    fastio;
    for(int i = 1 ; i<=3 ; i++){
        for(int j = 1 ; j<=3 ; j++) cin>>arr[i][j];
    }
    for(int i = 2 ; i<=3 ; i++){
        for(int j = 2 ; j<4 ; j++){
            if(arr[i][j] - arr[1][j] != arr[i][1] - arr[1][1]){
                cout<<"No\n";
                return 0;
            }
        }
    }
    cout<<"Yes\n";
    return 0;
}
