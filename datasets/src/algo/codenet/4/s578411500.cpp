#include <iostream>
#include <set>

using namespace std;

int main(){
	int N,M;
	int K;
	int n;
	int num;
	int incre = 1;
  	set<int> m;

  	cin >> N >> K;
  	while(K--){
        cin >> n;
  	    m.insert(n);
    }

  	num = N;
    M = N;

    if(N!= 0)
  	{
  	    while(num){
  	    n = num%10;
        while(m.find(n)!=m.end()){
            n++;
            n = n%10;
            N+=incre;
        }
        incre*=10;
        num = N/(incre);
        }

        num = N;
        incre/= 10;
        while(incre){
            int i;
            int temp = num/incre;
            for(i = 0; i < 10;i++){
                if(N-temp*incre+i*incre > M && m.find(i)== m.end()){
                    N = N-temp*incre+i*incre;
                    num = num-temp*incre+i*incre;
                    break;
                }
            }

            num = num%incre;
            //cout << num <<endl;
            incre = incre/10;
            //cout << incre <<endl;
        }
  	}
  	else
    {
        while(m.find(N)!=m.end())
            N++;
    }

    cout << N <<endl;
	return 0;
}
