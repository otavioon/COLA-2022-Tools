#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int n;

int solve(int k, int n, int a[]){
    int lb = -1, ub = n;

    while(ub - lb > 1){
        int mid = (lb - ub) /2;
        if (a[mid] > k){
            ub = mid;
        }
        else{
            lb = mid;
        }
    }
    return ub;
}

int main(){
    //input
    int N;
    scanf("%d\n", &N);
    int a[N];
    int b[N];
    int c[N];
    int i, j;

    for(i = 0; i < 3; i++){
        for(j = 0; j < N;j++){
            switch(i){
                case 0:
                    scanf("%d",&a[j]);
                    break;
                
                case 1:
                    scanf("%d", &b[j]);
                    break;
                case 2:
                    scanf("%d", &c[j]);
                    break;
                default:
                    break;
            }
        }
    }

    sort(a, a+N);
    sort(b, b+N);
    sort(c, c+N);
    int count = 0;
    for(i = 0; i < N; i++){
        int b_ = solve(c[i], N, b);

        if(b_ == N){
            continue;
        }
        for (j = 0; j < (N - b_); j++){
            int a_ = solve(b[b_+j], N, a);

            count += N - a_;
        }
    }

    printf("%d\n", count);
    return 0;
}