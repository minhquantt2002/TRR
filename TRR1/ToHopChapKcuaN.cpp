#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k; cin >> k >> n;
    int a[20];
    for (int i = 0; i < 20; ++i) a[i] = i;
    int stop = 0;
    do {
        for (int i = 1; i <= k; ++i) cout << a[i] << " ";
        cout << "\n";
        int l = k;
        while (l > 0 && a[l] == n - k + l) l--;
        if (l > 0) {
            a[l]++;
            for (int i = l + 1; i <= k; ++i) a[i] = a[l] + i - l;
        } else stop = 1;
    } while (stop != 1);
    return 0;
}