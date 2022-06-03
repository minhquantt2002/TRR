#include <bits/stdc++.h>
using namespace std;
int kh, ng, a[1000][1000], Max = 0, x[1000] = {0}, y[1000] = {0};
void ktra() {
    int t[1000] = {0};
    for (int i = 0; i < kh; i++) {
        if (x[i]) {
            int check = 1, ad[1000], sum = 0;
            for (int j = 0; j < ng; j++) {
                ad[j] = t[j];
                ad[j] += a[i][j];
                if (ad[j] > 1) {
                    check = 0;
                    break;
                }
            }
            if (check) {
                for (int j = 0; j < ng; j++) {
                    sum += ad[j];
                    t[j] = ad[j];
                }
                Max = max(Max, sum);
            }
        }
    }
}
void Try1(int i) {
    for (int j = 0; j <= 1; j++) {
        x[i] = j;
        if (i == kh - 1) ktra();
        else Try1(i + 1);
    }
}
void in() {
    int t[1000] = {0};
    for (int i = 0; i < kh; i++) {
        if (y[i]) {
            int check = 1, ad[1000], sum = 0;
            for (int j = 0; j < ng; j++) {
                ad[j] = t[j];
                ad[j] += a[i][j];
                if (ad[j] > 1) {
                    check = 0;
                    break;
                }
            }
            if (check) {
                for (int j = 0; j < ng; j++) {
                    sum += ad[j];
                    t[j] = ad[j];
                }
                if (Max == sum) {
                    for (int j = 0; j < kh; j++) cout << y[j] << " ";
                    cout << endl;
                    break;
                }
            }
        }
    }
}
void Try2(int i) {
    for (int j = 0; j <= 1; j++) {
        y[i] = j;
        if (i == kh - 1) in();
        else Try2(i + 1);
    }
}
int main() {
    cin >> kh >> ng;
    for (int i = 0; i < kh; i++)
        for (int j = 0; j < ng; j++) cin >> a[i][j];
    Try1(0);
    Try2(0);
}