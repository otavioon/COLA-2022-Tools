//qngjewhayjhrjhkreamhkrt
//kwrkghjlk/dlkj/bkjl/dfhzklj;klj/fdkj/lwd
//dfjklnfslkj'dffjlkjldlkj/fdklmdfzk;jDF
//fkkj'kj;kj;jk;fgjkgdjl;blk;Fdlkj;GDZlk;lkhgk:;lkBk:LDFHffddflkdfgdf'g,:"sdfh,.hdg;lk;'shgdlhdf'lfgd
///q234yu8t9gheiahaerggsdvijhuhzds
////agw2rihig3q4jhihhjhjpteahokphte4alhtjotjh4rtheaokjpgrwpo'repojhopk
///awerhgeonelkjerkhtjitehjijk/lllkm;flkj;fdjkerkltheahkplk;l
////&&ytgq3hufg2	4y8ty13y8rwghigwuhuheuoogwhuowefghgvrwd 
//qweghnkgjrekhjerkhkerjhkerjhjerkjhgiwerjiwreajiiwerirweitweweti4t
//qebnkjtghwerkjhjjarewjhearjkhjerkhjkewrjhkwerjhkk3rkwrlekhgekrewlh
//WAR;RHLEKJPTJHHKTEK;ETLJMRTL
//QEFKHOIPEOIJ;ERHKIFEHKL;EHKREHLKELRKOHFL
//akrwehiugrierihoghojkogjeikerhieroij
//waehggjr3hihteiteijfekjlefhifeth
//awhgiojieojhoekihptkhtrsokhtrpoj
//vawergjkgjekatjhirjetahoijhr
//asewrjgihirweahgijreihjeie
//sudo rm -rf
//rwgrhugrwhuwroihrwejietnajhnet
//awehggjhrweaghietfjihejihejgre
#pr\
agma GCC optimize(2)
#pr\
agma GCC optimize(3)
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;
vector<int> a[505] ;
#define go(X) for(REG int X)
#define REG register
char ch ;
int T1 , T2 , L , R ;
inline int read(int& x){ch = getchar() , x = 0 ;while(!isdigit(ch))ch = getchar() ;while(isdigit(ch)) x = 10*x+(ch^48) , ch=getchar() ;return x ;}
int n , m , q ;
int main(){
	read(n) , read(m) , read(q) ;
	go(i=1;i<=m;++i){
		read(T1) , read(T2) ; 
		a[T1] . push_back(T2) ;
	}
	go(i=1;i<=n;++i){
		a[i].push_back(0x7f7f7f7f) ;
		sort( a[i].begin() , a[i].end() ) ;
	}
	go(i=1;i<=q;++i){
		read(L) , read(R) ;
		int ans = 0 ;
		for(REG int j=L;j<=R;++j){
			int p = 0 ;
			while(a[j][p]<=R) /*printf("pos = %d , val = %d\n",p,a[j][p]),*/++p;
			if(p!=0)
				ans+=p ;	
			//printf("ans = %d\n" , ans) ;
		}
		printf("%d\n",ans) ; 
	}
}