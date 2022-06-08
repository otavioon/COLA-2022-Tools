#include <bits/stdc++.h>
using namespace std;
string s;
int k,arr[11];
vector<int>v;
int main(){
    cin>>s>>k;
    for(int i=0;i<k;i++){
        int x;
        cin>>x;
        arr[x]++;
    }
    for(int i=0;i<=9;i++){
        if(arr[i]==0){
            v.push_back(i);
        }
    }
    int id = -1;
    for(int i=0;i<s.size();i++){
        int num = s[i]-'0';
        if(arr[num]){
            id = i;
            break;
        }
    }
    if(id==-1)goto end;
    int j;
    for(j=0;j<v.size();j++){
        if(v[j] > s[id]-'0'){
            s[id] = v[j]+'0';
            break;
        }
    }
    if(j == v.size()){
        if(v[0]==0)
            s[0] = v[1]+'0';
        else
            s[0] = v[0]+'0';
        for(int i=1;i<s.size();i++)
            s[i] = v[0]+'0';
        s += v[0]+'0';
        goto end;
    }
    for(int i=id+1;i<s.size();i++){
        s[i] = v[0]+'0';
    }
    end:;cout<<s<<endl;
}

/*
200 8
2 3 4 5 6 7 8 9

*/
