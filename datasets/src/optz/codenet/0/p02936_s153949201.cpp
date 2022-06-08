#include<bits/stdc++.h>
using namespace std;
typedef struct node {
  struct node* child=NULL;
  struct node* next=NULL;
  int val=0;
} node_t;

void addval(node_t *a,int val){
  a->val += val;
  if(a->child != NULL) addval(a->child,a->val);
  if(a->next != NULL) addval(a->next,val);
}

int main(){
  int N,Q;
  cin >> N >> Q; cin.ignore();
  node_t nodes[N];
  for(int i=1;i<N;i++){
    int parent,child;
    cin >> parent >> child; cin.ignore();
    parent -= 1;
    child -= 1;
    node_t *ptmp,*tmp;
    ptmp = nodes+parent;
    tmp = ptmp->child;
    if( tmp == NULL){
      ptmp->child = nodes+child;
    }else{
      while( tmp != NULL ){
        ptmp = tmp;
        tmp = ptmp->next;
      }
      ptmp->next = nodes+child;
    }
  }
  for(int i=0;i<Q;i++){
    int n,val;
    cin >> n >> val; cin.ignore();
    nodes[n-1].val += val;
  }
  addval(nodes[0].child,nodes[0].val);
  cout << nodes[0].val;
  for(int i=1;i<N;i++){
    cout << " " << nodes[i].val;
  }
  cout << endl;
  return 0;
}