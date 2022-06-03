#include <bits/stdc++.h>
using namespace std;
int c[1000][1000], n, x[1000], Min = 0, dk[1000] = {0};
void in() {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += c[i][x[i]];
    }
    if (sum == Min) {
        for (int i = 0; i < n; i++) 
            cout << "Man" << i + 1 << "->Job" << x[i] + 1 << " ||";
        cout << endl;
    }
}
void Back(int i) {
    for (int j = 0; j < n; j++) {
        if (!dk[j]) {
            x[i] = j;
            dk[j] = 1;
            if (i == n - 1) in();
            else Back(i + 1);
            dk[j] = 0;
        }
    }
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) cin >> c[i][j];
    int a[1000] = {0};
    for (int i = 0; i < n; i++) {
        int k = 1e9, add = 0;
        for (int j = 0; j < n; j++) {
            if (a[j] == 0 && k > c[i][j]) {
                add = j;
                k = c[i][j];
            }
        }
        a[add] = 1;
        Min += k;
    }
    
    Back(0);
}