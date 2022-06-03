#include <bits/stdc++.h>
using namespace std;
int a[1000][1000], kh, ngay, b[1000] = {0}, Max = 0;
int main() {
    cin >> kh >> ngay;
    for (int i = 0; i < kh; i++) 
        for (int j = 0; j < ngay; j++) cin >> a[i][j];
    while (1) {
        int x[1000] = {0}, sum = 0;
        for (int i = 0; i < kh; i++) {
            if (b[i] == 1) {
                int check = 1, ad[1000], sum = 0;
                for (int j = 0; j < ngay; j++) {
                    ad[j] = x[j];
                    ad[j] += a[i][j];
                    if (ad[j] == 2) {
                        check = 0;
                        break;
                    }
                }
                if (check) {
                    for (int j = 0; j < ngay; j++) {
                        sum += ad[j];
                        x[j] = ad[j];
                    }
                    Max = max(sum, Max);
                }
            }
        }
        int t;
        for (t = kh - 1; t >= 0; t--) if (b[t] == 0) break;
        if (t == -1) break;
        for (int i = t; i < kh; i++) b[i] = 1 - b[i];
    }
    for (int i = 0; i < kh; i++) b[i] = 0;    
    while (1) {
        int x[1000] = {0};
        for (int i = 0; i < kh; i++) {
            if (b[i] == 1) {
                int check = 1, ad[1000], sum = 0;
                for (int j = 0; j < ngay; j++) {
                    ad[j] = x[j];
                    ad[j] += a[i][j];
                    if (ad[j] > 1) {
                        check = 0;
                        break;
                    }
                }
                if (check) {
                    for (int j = 0; j < ngay; j++) {
                        sum += ad[j];
                        x[j] = ad[j];
                    }
                    if (sum == Max) {
                        for (int j = 0; j < kh; j++) cout << b[j] << " ";
                        cout << endl;
                    }
                }
            }
        }
        int t;
        for (t = kh - 1; t >= 0; t--) if (b[t] == 0) break;
        if (t == -1) break;
        for (int i = t; i < kh; i++) b[i] = 1 - b[i];
    }
}