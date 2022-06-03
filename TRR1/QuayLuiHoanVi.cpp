#include <bits/stdc++.h>
using namespace std;
int n, x[1000], check[1000];
void in() {
    for (int i = 1; i <= n; i++) cout << x[i] << " ";
    cout << endl;
}
void Try(int i) {
    for (int j = 1; j <= n; j++) {
        if (check[j]) {
            x[i] = j;
            check[j] = 0;
            if (i == n) in();
            else Try(i + 1);
            check[j] = 1;
        }
    }
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) check[i] = 1;
    Try(1);
}