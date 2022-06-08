#include<iostream>
#include<set>

using namespace std;

int main(){

   int N, K;
   cin>> N>> K;
   int D[K];
   for(int i=0; i<K; i++) cin>> D[i];

   set<int> ng;
   for(int i=0; i<K; i++) ng.insert(D[i]);

   while(1){
      int k=1;
      int d;
      while(N/k){
         d=N/k%10;
         if(ng.count(d)) goto next;
         k*=10;
      }
      {
         cout<< N<< endl;
         break;
      }
      next:;
      N++;
   }

   return 0;
}
