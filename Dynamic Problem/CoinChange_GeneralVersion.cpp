// CoinChange_GeneralVersion.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include <algorithm>
#define MAX 10000000
using namespace std;

int main()
{
	int V, n;
	cin >> V;
	cin >> n;
	int *a = new int[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int *b = new int[V+1];
	for (int i = 1; i <= V; i++) {
		b[i] = MAX;
	}
	b[0] = 0;
	int dem[100];
	memset(dem, 0, sizeof(dem));
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= V; j++) {
			if (j - a[i] >= 0 && b[j - a[i]] < MAX) {
				b[j] = min(b[j], 1 + b[j - a[i]]);
			}
		}
	}
	for (int i = 0; i <= V; i++)
		cout << b[i] <<" ";
	cout << endl;
	for (int i = 0; i <= V; i++)
		cout << dem[i] << " ";
	


	delete b;
	delete a;
    return 0;
}

