#include <stdio.h>

int main(void)
{
    char S[101];
    int i, K, S_n=0;
    
    //カウント連続でしないように、前回カウントした時の配列のｎ番目を記憶します！
    int count_ed=-1;
    
    long long int count=0, count_ans;
    
    scanf("%s",S);
    scanf("%d",&K);

    S_n=0;
    while(S[S_n] != '\0'){
        S_n++;
    }
    //printf("S_n = %d\n",S_n);
     
    
    if(S_n == 1){
        count = 0;
        printf("%d\n",K/2);
    } else {
        for(i=1; i<S_n; i++){
            if((S[i-1] == S[i]) && (count_ed != i-1)){
                count++;
                count_ed = i;
            }
        }   
        count_ans = count*K;
    
        if((S[S_n] == S[0]) && (S[S_n] != S[S_n -1])){
            count_ans += K-1; 
        }
        
        printf("%lld\n",count_ans);
    }
    
    return 0;
}