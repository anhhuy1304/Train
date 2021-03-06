// TSP_travelling_saleman_problem.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#define MaxVertex 1<<13
#include <algorithm>
#include<iostream>
#include<fstream>
using namespace std;

int cost(int start, int n, int Grapth[17][17]) {
	int dp[MaxVertex][17];
	memset(dp, -1, sizeof(dp));
	dp[1<<start][0] = 0;
	for (int i = 1; i < (1 << n); i++) {
		for (int j = 0; j < n; j++) {
			if (dp[i][j] != -1) {
				for (int k = 0; k < n; k++)
				{
					if ((i & (1 << k)) == 0) {
						int p = i | 1 << k;
						if (dp[p][k] == -1) dp[p][k] = dp[i][j] + Grapth[j][k];
						else dp[p][k] = min(dp[p][k], dp[i][j] + Grapth[j][k]);
					}
				}
			}
		}
	}
	int ans = INT32_MAX;
	for (int i = 0; i < n; i++) {
		if(i != start)
		ans = min(ans, dp[(1 << n) - 1][i] + Grapth[i][start]);
	}
	return ans;
}



int main()
{
	int Grapth[17][17];
	int n; //  vertex  number

	//input grapth

	fstream f;
	f.open("input.txt", ios::in);
	f >> n;
	for (int i = 0; i < n*n; i++) {
		f >> Grapth[i / n][i%n];
	}

	cout << cost(0, n, Grapth);



	f.close();
    return 0;
}

