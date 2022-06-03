#include <bits/stdc++.h>
using namespace std;
int c[1000][1000];
int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> c[i][j];
    int a[1000] = {0}, Min = 0;
    for (int i = 0; i < n; i++) {
        int add = 0, m = 1e9;
        for (int j = 0; j < n; j++) {
            if (m > c[i][j] && a[j] != 1) {
                m = c[i][j];
                add = j;
            }
        }  
        a[add] = 1;
        Min += m;
    }
    int b[n]; for (int i = 0; i < n; i++) b[i] = i;
    while (1) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += c[i][b[i]];
        }
        if (sum == Min) {
            for (int i = 0; i < n; i++) {
                cout << "Man" << i + 1 << "->Job" << b[i] + 1 << " ||";
            }
            cout << endl;
        }
        int k, l;
        for (k = n - 2; k >= 0; k--) if (b[k] < b[k + 1]) break;
        if (k == -1) break;
        for (l = n - 1; l > k; l--) if (b[l] > b[k]) break;
        swap(b[k], b[l]);
        for (int i = k + 1, j = n - 1; i < j; i++, j--) swap(b[i], b[j]);
    }
}