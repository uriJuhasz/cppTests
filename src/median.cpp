/*
 * median.cpp
 *
 *  Created on: Aug 6, 2016
 *      Author: uri
 */
#include "median.h"
#include <cassert>

int median(int a[],int s,int e, int k);
int median(int a[],int l, int k)
{
	return median(a,0,l,k);
}
int median(int a[],int l){
	return median(a,l,l/2);
}

int medianLT5(int a[],int s, int e);
int min(int a[],int s,int e);
int max(int a[],int s,int e);
int split(int a[],int s, int e,int b[],int am);
int median(int a[],int s,int e, int k){
	assert(s>=0);
	assert(e>=s);
	int l = e-s;
	assert(k>0);
	assert(k<l);
	if (k==0)
		return min(a,s,e);
	else if (k==l-1)
		return max(a,s,e);

	int* b = new int[l];// (l*sizeof int);
	int c = l/5;
	if (5*c<l)
		c++;
	for (int i=0;i<c;i+=5)
		b[i] = medianLT5(a,s+i,e);
	int am = median(b,c,c/2);
	int p = split(a,s,e,b,am);
	if (p>=k)
		return median(b,0,p,k);
	else
		return median(b,p,l,k-p);
}

int split(int a[],int s, int e,int b[],int am){
	assert(e>s);
	int l = e-s;
	int kl = s;
	int kr = e-1;
	for (int i=0;i<l;i++)
	{
		int ai = a[i];
		if (ai<=am)
		{
			b[kl] = ai;
			kl++;
		}else{
			b[kr] = ai;
			kr--;
		}
	}
	assert(b[kl-1]<=am);
	assert(b[kr+1]>am);
	return kl-1;
}

void swapInt(int* a,int* b)
{
	int c = *a;
	*a = *b;
	*b = c;
}
int medianLT5(int a[],int s, int e){
	int b[5];
	int l = e-s;
	assert(l>0);
	assert(l<=5);
	for (int i=0;i<l;i++)
	{//sort first l elements
		int ai = a[i];
		for (int j=0;j<=i;j++)
			if (j==i)
				b[j]=ai;
			else if (ai<b[j])
				swapInt(&ai,&b[j]);
	}
	return b[l/2];
}


int min(int a[],int s,int e)
{
	assert(e>s);
	int m = a[s];
	for (int i=s;i<e;i++)
		if (m>a[i])
			m=a[i];
	return m;
}
int max(int a[],int s,int e)
{
	assert(e>s);
	int m = a[s];
	for (int i=s;i<e;i++)
		if (m<=a[i])
			m=a[i];
	return m;
}
