#include <bits/stdc++.h>
using namespace std;
int n, x[1000], cot[1000], xuoi[1000], nguoc[1000];
void in() {
    for (int i = 1; i <= n; i++) cout << x[i] << " ";
    cout << endl;
}
void Try(int i) {
    for (int j = 1; j <= n; j++) {
        if (cot[j] && xuoi[i - j + n] && nguoc[i + j - 1]) {
            x[i] = j;
            cot[j] = xuoi[i - j + n] = nguoc[i + j - 1] = 0;
            if (i == n) in();
            else Try(i + 1);
            cot[j] = xuoi[i - j + n] = nguoc[i + j - 1] = 1;
        }
    }
}
int main() {
    cin >> n;
    for (int i = 1; i <= 2 * n; i++) {
        cot[i] = 1;
        xuoi[i] = 1;
        nguoc[i] = 1;
    }
    Try(1);
}