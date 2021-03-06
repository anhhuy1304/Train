// Max2DRangeSum.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
	int A[4][4] = {
	{ 0, -2, -7, 0 } ,
	{ 9, 2, -6, 2} , 
	{ -4, 1, -4, 1 } ,
	{ -1, 8, 0, -2 }  
	};

	int row = 4, column = 4;
	int ans = A[0][0];
	int left, top, right, bottom;
	left = top = right = bottom = 0;
	int B[4] = { 0 };// set temp column  = 0
	//duyet cot
	for (int l = 0; l < column; l++) {
		for (int r = l; r < column; r++) {
			int sum = 0;
			for (int i = 0; i < row; i++) {
				//set cache array
				if(r==l)
				B[i] = A[i][r];
				else B[i] += A[i][r];
				//find max
				if (i == 0) sum = B[0];
				else sum = max(B[i], sum + B[i]);
				ans = max(sum, ans);
			}
		}
	}
	cout << ans;
    return 0;
}

