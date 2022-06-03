#include <bits/stdc++.h>
using namespace std;
int add[1000] = {0}, a[1000][1000], b[1000], c[1000], n;
float Max = 10000;
void Tim() {
    int sum = 0;
    for (int i = 0; i < n - 1; i++) sum += a[b[i]][b[i + 1]];
    sum += a[b[n - 1]][0];
    if (Max > sum) {
        Max = sum;
        for (int i = 0; i < n; i++) add[i] = b[i];
    }
}
void Try(int i) {
    for (int j = 1; j < n; j++) {
        if (c[j]) {
            b[i] = j;
            c[j] = 0;
            if (i == n - 1) Tim();
            else Try(i + 1);
            c[j] = 1;
        } 
    }
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) cin >> a[i][j];
    for (int i = 0; i < n; i++) {
        b[i] = i;
        c[i] = 1;
    }
    Try(1);
    cout << fixed << setprecision(1) << Max << endl;
    for (int i = 0; i < n; i++) cout << add[i] + 1 << " ";
    cout << 1;
}