//============================================================================
// Name        : MergeSort.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
#include<random>
#include<cassert>
#include "MergeSort.h"
#include "median.h"

using namespace std;

void testMergeSort();
void testMedian();
int main() {
	cout << "Start" << endl;
	cout << "  Testing merge sort" << endl;
	testMergeSort();
	cout << "  Testing median" << endl;
	testMedian();

	cout << "End" << endl;
	return 0;
}

int randomArray(default_random_engine r,int maxLength,int maxElement,int**a);
void testMergeSort()
{
	for (int kk = 0; kk < 100; kk++) {

		random_device rr;

		int seed = rr(); //12324; //r();
		cout << "seed:" << seed << endl;
		default_random_engine r;
		r.seed(seed);
		const int maxL = 10000000;
		const int maxE = 30;
		int *a;
		int l = randomArray(r,maxL,maxE,&a);

		mergeSort(a, l);

		for (int i = 0; i + 1 < l; i++)
			if (!(a[i] <= a[i + 1])) {
				cerr << "Error - element not sorted: a[" << i << "] = " << a[i]
						<< ">" << a[i + 1] << "= a[" << i + 1 << "]" << endl;
			}
	//		assert(a[i]<=a[i+1]);
	}
}

int sortPos(int a[],int l,int m);

void testMedian()
{
//	for (int kk = 0; kk < 100; kk++) {

		random_device rr;

		int seed = rr(); //12324; //r();
		cout << "seed:" << seed << endl;
		default_random_engine r;
		r.seed(seed);
		const int maxL = 10000000;
		const int maxVal = 10099999;
		int*a;

		int l = randomArray(r,maxL,maxVal,&a);

		int m = median(a,l);
		int k = sortPos(a,l,m);
		if (k!=l/2)
			cerr << "Error not a median " << m << " position is " << k << "/" << l << endl;
//	}
}

int sortPos(int a[],int l,int m){
	int k = 0;
	for (int i=0;i<l;i++)
		if (a[i]<m)
			k++;
	return k;

}

int randomArray(default_random_engine r,int maxL,int maxE,int**a)
{
	int l = ((static_cast<int>(r()) % maxL) + maxL) % maxL;
	if (l == 0)
		l = maxL;
	cout << "Length:" << l << endl;
	auto aa = new int[l];
	for (int i = 0; i < l; i++)
		aa[i] = (static_cast<int>(r()) % maxE);


	*a = aa;
	return l;
}
