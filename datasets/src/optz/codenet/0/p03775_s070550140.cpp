
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
	template<class T>
	inline void get(T *,int);
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
	template<class T>
	inline void put(T *,int,char,char);
private:
	FILE *fp;
	char *buf;
	int siz;
	int idx;
}out;

inline int keta(long long n){
	int ret=0;
	while(n){
		++ret;
		n/=10LL;
	}
	return ret;
}

inline void chmin(int val,int &var){
	if(val<var) var=val;
}

int main(int argc,char **argv){
	in.open(stdin,512);
	out.open(stdout,512);
	in.scan();
	long long n;
	in>n;
	int ans=2147483647;
	for(long long a=1LL;a*a<=n;++a){
		if(n%a) continue;
		chmin(keta(n/a),ans);
	}
	out<ans<'\n';
	out.print();
	in.close();
	out.close();
	return 0;
}

inline void kin::open(FILE *fparg,int sizarg){
	fp=fparg;
	buf=new char[sizarg];
	siz=sizarg;
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
	};
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
inline kin &kin::operator>(char *str){
	if(!buf[idx]){
		str[0]='\x00';
		return *this;
	}
	int ptr=0;
	while(buf[idx]>='!'){
		str[ptr++]=buf[idx];
		if(++idx==siz) scan();
	}
	str[ptr]='\x00';
	if(++idx==siz) scan();
	return *this;
}
template<class T>
inline void kin::get(T *arr,int num){
	for(int i=0;i<num;++i) (*this)>arr[i];
	return;
}

inline void kout::open(FILE *fparg,int sizarg){
	fp=fparg;
	buf=new char[sizarg];
	siz=sizarg;
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
inline kout &kout::operator<(const char *str){
	for(int i=0;str[i];++i){
		buf[idx]=str[i];
		if(++idx==siz) print();
	}
	return *this;
}
template<class T>
inline void kout::put(T *arr,int num,char dlm,char end){
	--num;
	for(int i=0;i<num;++i) (*this)<arr[i]<dlm;
	(*this)<arr[num]<end;
	return;
}
