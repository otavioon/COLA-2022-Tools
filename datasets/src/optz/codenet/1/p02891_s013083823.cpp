    #include<bits/stdc++.h>
    int main(){
      std::string s[3];
      long long k,a[3]={};
      std::cin>>s[0]>>k;
      for(size_t i=0;i<2;++i) s[i+1]=s[i]+s[0];
      for(size_t i=0;i<3;++i) for(size_t j=0;j<s[i].length()-1;++j) if(s[i][j]==s[i][j+1]) ++a[i],++j;
      std::cout<<(k&1?a[0]:a[1])+(k-1)/2*(a[2]-a[0])<<std::endl;
    }