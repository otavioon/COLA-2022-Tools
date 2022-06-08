#include<bits/stdc++.h>
using namespace std;
long long change(string s){
    long long res = 0;
    for(long long i=0; i<s.length();){
        long long j=i;
        while(j<s.length() && s[j]==s[i])
            j++;
        res += (j-i)/2;
        i = j;
    }
    return res;
}
int main(){
    string s;
    cin >> s;
    long long k;
    cin >> k;
    int len = s.length();
    if(len==1){
        cout << k/2;
        return 0;
    }
    long long res = 0;
    if(s[0]!=s[len-1]){
        long long nchange = change(s);
        res = nchange*k;
    }
    else{
        long long nchange = change(s);
        if(s.length()>=2 && s[len-1]!=s[len-2])
            res = nchange*k + k-1;
        else if(s.length()>=2 && s[len-1]==s[len-2]){
            res = nchange*k;
            int temp = len-1;
            while(temp>=0 && s[temp]==s[len-1])
                temp--;
            // cout << temp << endl;
            if((len-temp-1)%2)
                res += k-1;
        }
    }
    cout << res;
    return 0;
}