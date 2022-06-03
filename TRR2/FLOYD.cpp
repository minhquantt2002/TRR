#include <bits/stdc++.h>
using namespace std;
int a[1005][1005];
int n, m;
int next1[100][100];
int main() {
	cin >> n;
	memset(next1, 0, sizeof next1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			if (a[i][j] != 0) next1[i][j] = j;
			else a[i][j] = INT_MAX;
		}
	} 
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) {
					a[i][j] = 0;
					continue;
				}
				if (a[i][j] > a[i][k] + a[k][j] && a[i][k] != INT_MAX && a[k][j] != INT_MAX) {
					a[i][j] = a[i][k] + a[k][j];
					next1[i][j] = next1[i][k];
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << "K/c " << i << " -> " << j << " = " << a[i][j] << "; "; 
			if (a[i][j] == INT_MAX) cout << "1";
			else {
				int k = i;
				while (k != j) {
					cout << k << " -> ";
					k = next1[k][j];
				}
				cout << j;
			}
			cout << endl;
		}
		cout << endl;
	}
}
/*
input=
4
0  0 -2 0
4  0  3 0
0  0  0 2
0 -1  0 0 

output=

K/c 1 -> 1 = 0;   1

K/c 1 -> 2 = -1;   1 -->   3 -->   4 -->   2

K/c 1 -> 3 = -2;   1 -->   3

K/c 1 -> 4 = 0;   1 -->   3 -->   4


K/c 2 -> 1 = 4;   2 -->   1

K/c 2 -> 2 = 0;   2

K/c 2 -> 3 = 2;   2 -->   1 -->   3

K/c 2 -> 4 = 4;   2 -->   1 -->   3 -->   4


K/c 3 -> 1 = 5;   3 -->   4 -->   2 -->   1

K/c 3 -> 2 = 1;   3 -->   4 -->   2

K/c 3 -> 3 = 0;   3

K/c 3 -> 4 = 2;   3 -->   4


K/c 4 -> 1 = 3;   4 -->   2 -->   1

K/c 4 -> 2 = -1;   4 -->   2

K/c 4 -> 3 = 1;   4 -->   2 -->   1 -->   3

K/c 4 -> 4 = 0;   4
*/