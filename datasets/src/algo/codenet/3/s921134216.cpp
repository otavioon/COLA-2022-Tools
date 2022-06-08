#include<stdio.h>
#include<iostream>
#include"string"
#include"math.h"
using namespace std;
bool m;
void m_sort(int a[], int tmp[], int left, int right);
void m_sort(int a[], int tmp[], int left, int right);
void sort(int a[], int total) {
	int tmp;
	for (int i = 0; i < total; i++) {
		for (int j = i + 1; j < total; j++) {
			if (a[i] < a[j]) {
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}
 
}
 
void mergeSort(int a[], int tmp[], int size)
{
	m_sort(a, tmp, 0, size - 1);
}
void merge(int a[], int tmp[], int left, int mid, int right)
{
	int i, left_end, num_elements, tmp_pos;
 
	left_end = mid - 1;
	tmp_pos = left;
	num_elements = right - left + 1; // 要素 
 
	while ((left <= left_end) && (mid <= right))
	{
		if (a[left] <= a[mid])
		{
			tmp[tmp_pos] = a[left];
			tmp_pos = tmp_pos + 1;
			left = left + 1;
		}
		else
		{
			tmp[tmp_pos] = a[mid];
			tmp_pos = tmp_pos + 1;
			mid = mid + 1;
		}
	}
 
 
	while (left <= left_end)
	{
		tmp[tmp_pos] = a[left];
		left = left + 1;
		tmp_pos = tmp_pos + 1;
	}
 
	while (mid <= right)
	{
		tmp[tmp_pos] = a[mid];
		mid = mid + 1;
		tmp_pos = tmp_pos + 1;
	}
 
 
	for (i = 0; i <= num_elements; i++)
	{
		a[right] = tmp[right];
		right = right - 1;
	}
}
void m_sort(int a[], int tmp[], int left, int right)
{
	int mid;
 
	if (right > left)
	{
		mid = (right + left) / 2; 
		m_sort(a, tmp, left, mid);
		m_sort(a, tmp, mid + 1, right);
 
		merge(a, tmp, left, mid + 1, right);
	}
}


int A[100000],B[100000],C[100000],N,D[100000],ka,kc;
long long ans;
string S,s;
int main(){
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>A[i];
	}
	for(int i=0;i<N;i++){
		cin>>B[i];
	}
	for(int i=0;i<N;i++){
		cin>>C[i];
	}

	mergeSort(A,D,N);
	mergeSort(B,D,N);
	mergeSort(C,D,N);
	ans=0;
	ka=0;
	kc=0;

	for(int i=0;i<N;i++){
		while(ka<N){
			if(B[i]>A[ka]){
				ka++;
			}else{
				break;
			}
		}
		while(kc<N){
			if(B[i]>=C[kc]){
				kc++;
			}else{
				break;
			}
		}
		ans+=ka*(N-kc);
	}
	cout<<ans<<endl;
	return 0;
}
