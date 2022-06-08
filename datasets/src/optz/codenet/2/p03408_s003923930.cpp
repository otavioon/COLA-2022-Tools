#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n,m;
    int count = 1;
    int ans = 0;
    cin >> n;
    vector<string> s(n);
    for(int i=0;i<n;i++){
        cin >> s[i];
    }
    cin >> m;
    vector<string> t(m);
    for(int i=0;i<m;i++){
        cin >> t[i];
    }
    sort(s.begin(),s.end());
    for(int i=0;i<n;i++){
        if(i==n-1){
            for(int j=0;j<m;j++){
                if(t[j]==s[i]){
                    count--;
                }
            }
            if(ans<count){
                ans = count;
            }
        }
        if(s[i]==s[i+1]){
            count++;
        }else{
            for(int j=0;j<m;j++){
                if(t[j]==s[i]){
                    count--;
                }
            }
            if(count>ans){
                ans = count;
            }
            count=1;
        }
    }
    if(ans <0){
        ans = 0;
    }
    cout << ans << endl;
}