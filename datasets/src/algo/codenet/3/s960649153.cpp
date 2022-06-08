#include <iostream>
#include <vector>
using namespace std;
 
int main(){
  int N;
  cin >> N;
  
  int max=100000000;
  
  vector<int> vec1(max+1,0);
  vector<int> vec2(max+1,0);
  vector<int> vec3(max+1,0);
 
  int a[N];
  for (int i=0;i<N;i++){
    cin >> a[i];vec1[a[i]] += 1;}
  int b[N];
  for (int i=0;i<N;i++){
    cin >> b[i];vec2[b[i]] += 1;}
  int c[N];
  for (int i=0;i<N;i++){
    cin >> c[i];vec3[c[i]] += 1;}
  
  int answer = 0;
  for (int i=1;i<max;i++){
     if(vec2[i]>0) {
      int front = 0;
      int back = 0;
      for (int j=1;j<i;j++){
       if (vec1[j] >0) front += 1;}
      for (int k= i+1;k<max+1;k++){
       if (vec3[k]>0)  back += 1;}
    
       answer += (front * back); }
  }
  cout << answer;
  
}
       