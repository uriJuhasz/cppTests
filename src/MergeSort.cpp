#include "MergeSort.h"
#include <cassert>
//#include <iostream>

template<typename T>void swap(T& a, T& b);

void merge(int a[],int b[],int i,int w,int l);
int* mergeSort(int a[],int l)
{
	if (l<=1)
		return a;
	int* b = new int[l];
	for (int w=1;w<2*l;w=w << 1)
	{
//		std::cout << "w=" << w << std::endl;
		for (int i=0;i<l;i+=2*w)
		{
//			std::cout << " i=" << i << std::endl;
			merge(a,b,i,w,l);
		}
		swap(a,b);
	}
	return a;
}

void merge(int a[],int b[],int s,int w,int l)
{
	assert(s<l);
	int m = s+w;
	int e = m+w;
	if (m>l)
		m=l;
	if (e>l)
		e=l;

	int i = s;
	int j = s+w;
	int k = s;
	while (i<m && j<e){
		if (a[i]<a[j])
		{
			b[k] = a[i];
			i++;
		}else{
			b[k] = a[j];
			j++;
		}
		k++;
	}
	if (i==m){
		i = j;
		m = e;
	}
	while(i<m)
	{
		b[k]=a[i];
		k++;i++;
	}
}


template<typename T>void swap(T& a, T& b){
	T c = a;
	a=b;
	b=c;
}
