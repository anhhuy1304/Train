// Longest_Increasing_Subsequence.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int* A = new int[n];

	int* Cache = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> A[i];
		Cache[i] = 1;
	}


	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (A[i] > A[j] && Cache[i] < Cache[j]+1)
				Cache[i]++;
		}
	}

	int ans = Cache[0];
	for (int i = 0; i < n; i++) {
		if (ans < Cache[i]) ans = Cache[i];
	}
	int* result = new int[ans];
	for (int i = 0; i < n; i++) {
		result[Cache[i]-1] = A[i];
	}
	for (int i = 0; i < ans; i++)
		cout << result[i] << " ";
	delete result;
	delete A;
	delete Cache;
    return 0;
}

