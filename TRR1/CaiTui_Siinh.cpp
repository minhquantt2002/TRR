#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, kg; cin >> n >> kg;
    int a[n], c[n] = {0}, d[n] = {0};
    float Max = 0, b[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    while (1) {
        int sum = 0, wei = 0;
        for (int i = 0; i < n; i++) {
            sum += b[i] * c[i];
            wei += a[i] * c[i];
        }
        if (Max < sum && wei <= kg) {
            Max = sum;
            for (int i = 0; i < n; i++) d[i] = c[i];
        }
        int t = n - 1; 
        for (t = n - 1; t >= 0; t--) if (c[t] == 0) break;
        if (t == -1) break;
        for (int i = t; i < n; i++) c[i] = 1- c[i]; 
    }
    cout << fixed << setprecision(1) << Max << "\n";
    for (int i = 0; i < n; i++) cout << d[i] << " ";
}