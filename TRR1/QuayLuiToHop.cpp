#include <iostream>
using namespace std;
int n, k, x[1000];
void in(){
    for (int i = 1; i <= k; i++) cout << x[i] << " ";
    cout << endl;
}
void Try(int i) {
    for (int j = x[i - 1] + 1; j <= n - k + i; j++) {
        x[i] = j;
        if (i == k) in();
        else Try(i + 1);
    }
}
int main() {
    cin >> k >> n;
    Try(1);
}