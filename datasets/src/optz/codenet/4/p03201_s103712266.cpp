#include<bits/stdc++.h>
using namespace std;

class Trie{
    public:
    Trie *next[2];
    int index=0;
    int count=0;
    Trie(int i){
        next[0]=nullptr;
        next[1]=nullptr;
        index=i;
    }
};

Trie trie=Trie(0);
    
void insert(int x){
    int i=0;
    int t=x;
    Trie *tr=&trie;
    while(i<30){
        if(tr->next[x&&1]!=nullptr){
            tr=tr->next[x&&1];
        }else{
            tr->next[x&&1]=new Trie(tr->index+1);
            tr=tr->next[x&&1];
        }
        i++;
        x=x>>1;
    }
    tr->count++;
}
void remove(int x){
    int i=0;
    int t=x;
    Trie *tr=&trie;
    while(i<30){
        if(tr->next[x&&1]!=nullptr){
            tr=tr->next[x&&1];
        }else{
            tr->next[x&&1]=new Trie(tr->index+1);
            tr=tr->next[x&&1];
        }
        i++;
        x=x>>1;
    }
    tr->count--;
}
bool search(int x){
    int i=0;
    int t=x;
    Trie *tr=&trie;
    bool f=true;
    while(i<30){
        if(tr->next[x&&1]!=nullptr){
            tr=tr->next[x&&1];
        }else{
            f=false;
            break;
        }
        i++;
        x=x>>1;
    }
    return f&&(tr->count>0);
}


int main(void){
    int N;
    scanf("%d",&N);
    int c=0;
    for(int i=0;i<N;i++){
        int a;
        scanf("%d",&a);
        int s=1<<29;
        bool f=false;
        int x;
        while((x=s-a)>=0&&!f){
            if(search(x)){
                remove(x);
                c++;
                f=true;
            }
            s=s>>1;
        }
        if(!f)insert(a);
    }
    cout<<c<<endl;
    return 0;
}