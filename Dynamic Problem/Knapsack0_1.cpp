// Knapsack0_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <algorithm>
#include<iostream>
using namespace std;

int main()
{
	int W, n;
	int* wt;
	int* vl;
	//input number item
	cin >> n;
	//input total weight
	cin >> W;
	wt = new int[n];
	vl = new int[n];
	//input value of wt and vl
	for (int i = 0; i < n; i++) {
		cin >> wt[i];
		cin >> vl[i];
	}


	//create matrix 
	int A[100][100] = { 0 };


	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= W; j++) {
			if (i == 0 || j == 0)
				A[i][j] = 0;
			else if (wt[i - 1] <= j)
				A[i][j] = max(vl[i - 1] + A[i - 1][j - wt[i - 1]], A[i - 1][j]);
			else
				A[i][j] = A[i - 1][j];
		}
	}
	cout << A[n][W];
    return 0;
}

