#include <bits/stdc++.h>
using namespace std;
int n, kg, a[1000], b[1000], x[1000], kq[1000] = {0};
double maxx = 0;
void ktra() {
    int tong = 0;
    double wei = 0;
    for (int i = 1; i <= n; i++) {
        tong += a[i] * x[i];
        wei += b[i] * x[i];
    }
    if (wei > maxx && tong <= kg) {
        maxx = wei;
        for (int i = 1; i <= n; i++) kq[i] = x[i];
    }
}
void Try(int i) {
    for (int j = 0; j <= 1; j++) {
        x[i] = j;
        if (i == n) ktra();
        else Try(i + 1);
    }
}
int main() {
    cin >> n >> kg;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    Try(1);
    cout << fixed << setprecision(1) << maxx << endl;
    for (int i = 1; i <= n; i++) cout << kq[i] << " ";
}