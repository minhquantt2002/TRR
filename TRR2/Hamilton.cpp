#include <bits/stdc++.h>
using namespace std;
int chuaxet[100] = {0}, kq[100], a[100][100], n, u;
void out() {
    for (int i = 0; i <= n; i++) cout << kq[i] << " ";
    cout << endl;
}
void hmt(int k) {
    for (int i = 1; i <= n; i++) {
        if (a[kq[k - 1]][i] == 1 && chuaxet[i] == 0) {
            kq[k] = i;
            chuaxet[i] = 1;
            if (k < n) hmt(k + 1);
            else if (kq[k] == kq[0]) out();
            chuaxet[i] = 0;
        }
    }
}
int main() {
    cin >> n >> u;
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= n; j++) 
            cin >> a[i][j];
    kq[0] = u;
    hmt(u);
}