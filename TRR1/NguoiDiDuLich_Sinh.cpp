#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    int a[n][n];
    for (int i = 0; i < n; i++)     
        for (int j = 0; j < n; j++) cin >> a[i][j];
    int b[n], add[n];
    double Max = 100000;
    for (int i = 0; i < n; i++) b[i] = i;
    while (1) {
        double tong = 0;
        for (int i = 0; i < n - 1; i++) 
            tong += a[b[i]][b[i + 1]];
        tong += a[b[n - 1]][0];
        if (Max > tong) {
            Max = tong;
            for (int i = 0; i < n; i++) add[i] = b[i];
        }
        int l = n, r;
        for (r = n - 2; r > 0; r--) if (b[r] < b[r + 1]) break;
        if (r == 0) break;
        for (l = n - 1; l > r; l--) if (b[r] < b[l]) break;
        swap(b[l], b[r]);
        for (int i = r + 1, j = n - 1; i < j; i++, j--) swap(b[i], b[j]);
    }
    cout << fixed << setprecision(1) << Max << endl;
    for (int i = 0; i < n; i++) cout << add[i] + 1 << " ";
    cout << 1;
}