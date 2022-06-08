#include <stdio.h>

int main(){
  long long int N, i,j, Takahashi=0;
  long long int x[20] ={0};
  long long int c[20] ={0};
  long long int v[20] ={0};
  long long int ans[20] ={0};
  int flag = 0;
  long long int K;

  for (i = 0; i < 1000; i++) {
    for (j = 0; j < 1000; j++) {
      
      
    }
  }



  
  scanf("%lld", &N);
  scanf("%lld", &K);

  printf("%d\n", (N*K) - (N+K-1));
  
 /*  for (i = 0; i < 26; i++) { */
 /*   for (j = 0; j < 15; j++) { */
 /*     if ((4*i) + (7*j) == N) { */
 /*       printf("Yes\n"); */
 /*       goto L1; */
 /*     } */
 /*   } */
 /*  } */
 /*  printf("No\n"); */
 /* L1: */
  /* scanf("%lld", &K); */

  /* if (N % K == 0) printf("%lld\n", 0); */
  /* else {printf("1\n");} */
  /* for(i=0; i < N; i++) { */
  /*   scanf("%lld", &x[i]); */
  /* } */
  /* for(i=0; i < N; i++) { */
  /*   scanf("%lld", &c[i]); */
  /* } */
  /* for(i=0; i < N; i++) { */
  /*   scanf("%lld", &v[i]); */
  /* } */
  /* long long int sum=0; */
  /* for(i=0; i < N; i++) { */
  /*   sum += x[i]; */
  /* } */
  /* for(i=0; i < N; i++) { */
  /*   if (sum < c[i]) { */
  /*     v[i] = 0; */
  /*   } */
  /* } */


  /* for (i=0; i<N-1; i++) { */
  /*   int s; */
  /*   puts(""); */
  /*   for(s=0; s < N; s++) { */
  /*     printf("%lld ", x[s]); */
  /*   } */
  /*   puts(""); */
  /*   for(s=0; s < N; s++) { */
  /*     printf("%lld ", c[s]); */
  /*   } */
  /*   puts(""); */
  /*   for(s=0; s < N; s++) { */
  /*     printf("%lld ", v[s]); */
  /*   } */
  /*   puts(""); */
    
  /*   flag = 1; */
  /*   long long int aa, bb, cc; */
  /*   aa = Takahashi; */
  /*   while (flag == 1) {//購入 */
  /*     int j, t=0; */
  /*     flag = 0; */
  /*     for (j = 0; j < N; j++) { */
  /*       if (v[t] <= v[j] && Takahashi - c[j] >= 0 && v[j] != 0) { */
  /*         t = j; */
  /*         flag=1; */
  /*       } */
  /*     } */
  /*     //tは購入できる一番価値の高い販売中の賞品の添 */
  /*     //flag：購入できるものがあったら1 */
  /*     if (flag == 1 ){ */
  /*       Takahashi -= c[t]; */
  /*       ans[i] += v[t]; */
  /*       c[t] = v[t] = 0; */
  /*     } */
  /*   } */

  /*   Takahashi = aa; */
  /*   Takahashi += x[i]; */
  /*   x[i] = 0; */
  /*   printf("Takahasji : %lld\n", Takahashi); */

    
  /*   flag = 0; */
  /*   int j,t=0; */
  /*   for (j = 0; j < N; j++) { */
  /*     if (Takahashi >= c[j] && v[t] <= v[j]) { */
  /*       t = j; */
  /*       flag = 1; */
  /*     } */
  /*   } */
  /*   if (flag == 0) { */
  /*     for (j = 0; j < N; j++) { */
  /*       if (v[t] <= v[j]) { */
  /*         t = j; */
  /*         flag = 1; */
  /*       } */
  /*     } */
  /*   } */
  /*   if (flag == 0) puts("error"); */
  /*   printf("中止 : [%d]%lld\n", t, c[t]); */
  /*   v[t] = c[t] = 0; */
  /* } */

  /* int t = 0; */
  /* for (i = 0; i < N; i++) { */
  /*   printf("%d\n", ans[i]); */
  /*   if (ans[t] < ans[i]) { */
  /*     t=i; */
  /*   } */
  /* } */
  /* printf("%lld\n", ans[t]); */
  
  /* /\* scanf("%lld%lld", &X, &K); *\/ */
  /* /\* T=1; *\/ */
  /* /\* for (i = 0; i < K; i++) { *\/ */
  /* /\*   T*=10; *\/ */
  /* /\* } *\/ */
  /* /\* L=X/T; *\/ */
  /* /\* L++; *\/ */
  /* /\* L*=T; *\/ */
  /* /\* printf("%lld\n", L); *\/ */




  //long long int X, A, B, C;
  /* //long long int i, j, k, cnt = 0; */
  /* long long int N, max; */
  /* long long int a[2][110]; */


  /* int flag = 0; */
  /* int i; */
  /* char AA[10]; */
  /* scanf("%s", AA); */
  /* for (i = 0; i < 5; i++) { */

  /*   switch(i) { */
  /*   case 0: */
  /*     if (AA[i] != 'y') { */
  /*       flag = -1; */
  /*     } */
  /*     break; */
  /*   case 1: */
  /*     if (AA[i] != 'a') { */
  /*       flag = -1; */
  /*     } */
  /*     break; */
  /*   case 2: */
  /*     if (AA[i] != 'h') { */
  /*       flag = -1; */
  /*     } */
  /*     break; */

  /*   case 4: */
  /*     if (AA[i-1] != AA[i]) { */
  /*       flag = -1; */
  /*     } */
  /*   } */
  /* } */

  /* if (flag == -1) {puts("NO");} */
  /* else {puts("YES");} */
  /* scanf("%lld", &N); */

  /* for (i = 0; i < 2; i++) { */
  /*   for (j = 0; j < N; j++) { */
  /*     scanf("%lld", &a[i][j]); */
  /*   } */
  /* } */

  /* for (i = 1; i <= N; i++) { */
  /*   cnt = 0; */
  /*   for (j = 0; j < i; j++) { */
  /*     cnt += a[0][j]; */
  /*   } */
  /*   for (k = j-1; k < N; k++) { */
  /*     cnt += a[1][k]; */
  /*   } */
  /*   if (cnt > max) {max = cnt;} */
  /*   //printf("aa%lld\n", cnt); */
  /* } */
  
  /* printf("%lld\n", max); */
  
  /* scanf("%ld%ld%ld%ld", &A, &B, &C, &X); */
  /* for (i = 0; i <= A; i++) { */
  /*   for (j = 0; j <= B; j++) { */
  /*     for (k = 0; k <= C; k++) { */
  /*       if (500*i + 100*j + 50*k == X) {cnt++;} */
  /*     } */
  /*   } */
  /* } */
  //printf("%d\n", cnt);
  return 0;
}
