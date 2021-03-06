// DP_1D.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<iostream>
using namespace std;

int max(int a, int b) {
	if (a >= b) return a;
	return b;
}
int min(int a, int b) {
	if (a >= b) return b;
	return a;
}
int findMaxRangeSum(int A[], int n) {
	int sum = 0, ans = A[0];
	for (int i = 0; i < n; i++) {
		sum = max(sum + A[i],A[i]);
		ans = max (ans , sum);
	}
	return ans;
}
int findMaxRangeProduct(int A[], int n) {
	int Maxproduct = 1, Minproduct = 1, ans = 0, count = 0; //
	for (int i = 0; i < n; i++) {
		if (A[i] > 0) {
			Maxproduct = Maxproduct * A[i]; //Max >0 = Max * A[i] vi a[i]> 0 
			Minproduct = min(Minproduct*A[i], 1); // set min lai vi min co the co 2 truong hop am hoac = 1
		}
		else if (A[i] == 0) {
			Maxproduct = 1; // reset lai max va min
			Minproduct = 1;
			count++; //check all element of array are 0? 
		}
		else {
			int temp = Maxproduct; // 
			Maxproduct = max(Minproduct* A[i], 1);// min *A[i] >=1 lay max
			Minproduct = A[i] * temp;
		}
		if (ans < Maxproduct) //neu max moi lon hon max cu thi reset ans
			ans = Maxproduct;

	}
	if (count == n) return 0;
	return ans;
}
int main()
{
	int n = 9, A[] = { 5,-6,2,-5,1,0,6,4,-8 }; // create array
	int maxsum = findMaxRangeSum(A, n);
	printf("Max 1D Range Sum = %d\n", maxsum);
	int maxProduct = findMaxRangeProduct(A, n);
	printf("Max 1D Range Product = %d\n", maxProduct);

    return 0;
}

