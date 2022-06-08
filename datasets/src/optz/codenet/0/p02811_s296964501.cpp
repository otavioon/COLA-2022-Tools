
#include <bits/stdc++.h>

class kin{
public:
	inline void open(FILE *,int);
	inline void close(void);
	inline void scan(void);
	inline kin &operator>(char &);
	inline kin &operator>(int &);
	inline kin &operator>(long long &);
	inline kin &operator>(double &);
	inline kin &operator>(long double &);
	inline kin &operator>(char *);
	template <class T> inline void get(T *,int);
private:
	FILE *fp;
	char *buf;
	int siz;
	int idx;
}in;

class kout{
public:
	inline void open(FILE *,int);
	inline void close(void);
	inline void print(void);
	inline kout &operator<(char);
	inline kout &operator<(int);
	inline kout &operator<(long long);
	inline kout &operator<(double);
	inline kout &operator<(long double);
	inline kout &operator<(const char *);
	template <class T> inline void put(T *,int,char,char);
private:
	FILE *fp;
	char *buf;
	int siz;
	int idx;
}out;

int main(int argc,char **argv){
	in.open(stdin,512);
	out.open(stdout,512);
	in.scan();
	int k,x;
	in>k>x;
	out<(500*k>=x?"Yes":"No")<'\n';
	out.print();
	in.close();
	out.close();
	return 0;
}

inline void kin::open(FILE *fpa,int siza){
	fp=fpa;
	buf=new char[siza];
	siz=siza;
	idx=0;
	return;
}
inline void kin::close(void){
	fp=nullptr;
	delete[] buf;
	buf=nullptr;
	siz=0;
	idx=0;
	return;
}
inline void kin::scan(void){
	int readsiz=(int)std::fread((void *)buf,(std::size_t)1,(std::size_t)siz,fp);
	if(readsiz!=siz) buf[readsiz]='\x00';
	idx=0;
	return;
}
inline kin &kin::operator>(char &var){
	if(!buf[idx]){
		var='\x00';
		return *this;
	}
	var=buf[idx];
	if(++idx==siz) scan();
	if(++idx==siz) scan();
	return *this;
}
inline kin &kin::operator>(int &var){
	if(!buf[idx]){
		var=0;
		return *this;
	}
	int sign=-1;
	if(buf[idx]=='-'){
		sign=1;
		if(++idx==siz) scan();
	}
	var=0;
	while(buf[idx]>='0'){
		var=var*10-(int)(buf[idx]-'0');
		if(++idx==siz) scan();
	}
	var*=sign;
	if(++idx==siz) scan();
	return *this;
}
inline kin &kin::operator>(long long &var){
	if(!buf[idx]){
		var=0LL;
		return *this;
	}
	long long sign=-1LL;
	if(buf[idx]=='-'){
		sign=1LL;
		if(++idx==siz) scan();
	}
	var=0LL;
	while(buf[idx]>='0'){
		var=var*10LL-(long long)(buf[idx]-'0');
		if(++idx==siz) scan();
	}
	var*=sign;
	if(++idx==siz) scan();
	return *this;
}
inline kin &kin::operator>(double &var){
	if(!buf[idx]){
		var=0.0;
		return *this;
	}
	double sign=-1.0;
	if(buf[idx]=='-'){
		sign=1.0;
		if(++idx==siz) scan();
	}
	var=0.0;
	while(buf[idx]>='0'){
		var=var*10.0-(double)(buf[idx]-'0');
		if(++idx==siz) scan();
	}
	if(buf[idx]=='.'){
		if(++idx==siz) scan();
		double dig=1.0;
		while(buf[idx]>='0'){
			var-=(double)(buf[idx]-'0')*(dig/=10.0);
			if(++idx==siz) scan();
		}
	}
	var*=sign;
	if(++idx==siz) scan();
	return *this;
}
inline kin &kin::operator>(long double &var){
	if(!buf[idx]){
		var=0.0L;
		return *this;
	}
	long double sign=-1.0L;
	if(buf[idx]=='-'){
		sign=1.0L;
		if(++idx==siz) scan();
	}
	var=0.0L;
	while(buf[idx]>='0'){
		var=var*10.0L-(long double)(buf[idx]-'0');
		if(++idx==siz) scan();
	}
	if(buf[idx]=='.'){
		if(++idx==siz) scan();
		long double dig=1.0L;
		while(buf[idx]>='0'){
			var-=(long double)(buf[idx]-'0')*(dig/=10.0L);
			if(++idx==siz) scan();
		}
	}
	var*=sign;
	if(++idx==siz) scan();
	return *this;
}
inline kin &kin::operator>(char *var){
	if(!buf[idx]){
		var[0]='\x00';
		return *this;
	}
	int ptr=0;
	while(buf[idx]>='!'){
		var[ptr++]=buf[idx];
		if(++idx==siz) scan();
	}
	var[ptr]='\x00';
	if(++idx==siz) scan();
	return *this;
}
template<class T>
inline void kin::get(T *var,int num){
	for(int i=0;i<num;++i) (*this)>var[i];
	return;
}

inline void kout::open(FILE *fpa,int siza){
	fp=fpa;
	buf=new char[siza];
	siz=siza;
	idx=0;
	return;
}
inline void kout::close(void){
	fp=nullptr;
	delete[] buf;
	buf=nullptr;
	siz=0;
	idx=0;
	return;
}
inline void kout::print(void){
	std::fwrite((void *)buf,(std::size_t)1,(std::size_t)idx,fp);
	idx=0;
	return;
}
inline kout &kout::operator<(char val){
	buf[idx]=val;
	if(++idx==siz) print();
	return *this;
}
inline kout &kout::operator<(int val){
	if(val<0){
		buf[idx]='-';
		if(++idx==siz) print();
	}
	else val*=-1;
	char dig[10];
	int ptr=0;
	do{
		int tmp=val/10;
		dig[ptr++]=(char)-(val-tmp*10)+'0';
		val=tmp;
	}while(val);
	while(ptr--){
		buf[idx]=dig[ptr];
		if(++idx==siz) print();
	}
	return *this;
}
inline kout &kout::operator<(long long val){
	if(val<0LL){
		buf[idx]='-';
		if(++idx==siz) print();
	}
	else val*=-1LL;
	char dig[19];
	int ptr=0;
	do{
		long long tmp=val/10LL;
		dig[ptr++]=(char)-(val-tmp*10LL)+'0';
		val=tmp;
	}while(val);
	while(ptr--){
		buf[idx]=dig[ptr];
		if(++idx==siz) print();
	}
	return *this;
}
inline kout &kout::operator<(double val){
	if(val<0.0){
		buf[idx]='-';
		if(++idx==siz) print();
	}
	else val*=-1.0;
	double dig=1.0;
	while(val/dig<=-10.0) dig*=10.0;
	int tmp;
	while(dig>=1.0){
		buf[idx]=(char)-(tmp=(int)(val/dig))+'0';
		if(++idx==siz) print();
		val-=(double)tmp*dig;
		dig/=10.0;
	}
	buf[idx]='.';
	if(++idx==siz) print();
	for(int i=0;i<12;++i){
		buf[idx]=(char)-(tmp=(int)(val/dig))+'0';
		if(++idx==siz) print();
		val-=(double)tmp*dig;
		dig/=10.0;
	}
	return *this;
}
inline kout &kout::operator<(long double val){
	if(val<0.0L){
		buf[idx]='-';
		if(++idx==siz) print();
	}
	else val*=-1.0L;
	long double dig=1.0L;
	while(val/dig<=-10.0L) dig*=10.0L;
	int tmp;
	while(dig>=1.0L){
		buf[idx]=(char)-(tmp=(int)(val/dig))+'0';
		if(++idx==siz) print();
		val-=(long double)tmp*dig;
		dig/=10.0L;
	}
	buf[idx]='.';
	if(++idx==siz) print();
	for(int i=0;i<16;++i){
		buf[idx]=(char)-(tmp=(int)(val/dig))+'0';
		if(++idx==siz) print();
		val-=(long double)tmp*dig;
		dig/=10.0L;
	}
	return *this;
}
inline kout &kout::operator<(const char *val){
	for(int i=0;val[i];++i){
		buf[idx]=val[i];
		if(++idx==siz) print();
	}
	return *this;
}
template<class T>
inline void kout::put(T *val,int num,char spc,char end){
	--num;
	for(int i=0;i<num;++i) (*this)<val[i]<spc;
	(*this)<val[num]<end;
	return;
}
