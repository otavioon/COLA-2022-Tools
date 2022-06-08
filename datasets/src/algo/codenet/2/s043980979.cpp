// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;



#include<stdio.h>
#include<bits/stdc++.h>
#include<iostream>
bool isPowerOfTwo(int n) 
{ 
   return (ceil(log2(n)) == floor(log2(n))); 
}

void temp(){
  int a;
  std::cin>>a;
  //int * Numbers=(int*)calloc(a,sizeof(int));
  std::vector<int> odd,even;
  for(int i=0;i<a;i++){
    int temp;
    std::cin>>temp;
    if(temp%2==0){
      even.push_back(temp);
    }
    else{
      odd.push_back(temp);
    }
  }
  int oddSize,evenSize;
  int count=0;
  oddSize=odd.size();
  evenSize=even.size();
  int loopSize=evenSize>oddSize?evenSize:oddSize;
  
  
  for(int i=0;i<loopSize;i++){
    for(int j=i+1;j<loopSize;j++){
      if(i<oddSize &&j<oddSize){
        bool oddPow2=isPowerOfTwo(odd[i]+odd[j]);
        if(oddPow2){
          count++;
        }
      }
      if(i<evenSize&&j<evenSize){
        bool oddPow2=isPowerOfTwo(even[i]+even[j]);
        if(oddPow2){
          count++;
        }
      }
      
      
      
    }
  }
}