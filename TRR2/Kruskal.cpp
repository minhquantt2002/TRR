#include <bits/stdc++.h>
using namespace std;
int n, check[100], a[101][101];
struct tree {
    int x, y, z;  
};
vector<tree> l;
bool ss(tree a, tree b) {
    if (a.z == b.z) return a.x < b.x;
    return a.z < b.z;
}
queue<tree> kq;
int s = 0;
void dfs(int u) {
    check[u] = 0;
    for (int i = 0; i < l.size(); i++) {
        if (check[l[i].x] || check[l[i].y]) {
            kq.push(l[i]);
            s += l[i].z;
            check[l[i].x] = check[l[i].y] = 0;
        }
    }
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if (a[i][j] != 0) {
                tree k;
                k.x = i; k.y = j; k.z = a[i][j];
                l.push_back(k);
                
            }
        }
        check[i] = 1;
    } 
    sort(l.begin(), l.end(), ss);
    dfs(1);
    cout << "dH = " << s << endl;
    while (!kq.empty()) {
        cout << kq.front().x << " " << kq.front().y << endl;
        kq.pop();
    }
}
/*
case=1

input=

13
0 2 1 3 0 0 0 0 0 0 0 0 0
2 0 2 0 0 5 5 0 0 0 0 0 0
1 2 0 4 0 5 0 0 0 0 0 0 0
3 0 4 0 5 5 0 0 0 0 0 0 0
0 0 0 5 0 6 0 0 0 6 0 0 0
0 5 5 5 6 0 6 6 6 6 0 0 0
0 5 0 0 0 6 0 6 0 0 0 0 0
0 0 0 0 0 6 6 0 7 0 0 7 7
0 0 0 0 0 6 0 7 0 7 7 0 0
0 0 0 0 6 6 0 0 7 0 7 7 0
0 0 0 0 0 0 0 0 7 7 0 8 0
0 0 0 0 0 0 0 7 0 7 8 0 8
0 0 0 0 0 0 0 7 0 0 0 8 0

output=

dH = 60
1   3
1   2
1   4
2   6
2   7
4   5
5   10
6   8
6   9
8   12
8   13
9   11


case=2

input=

5
0    1    0  10  0
1    0    2  0    20
0    2    0  3    4
10  0    3  0    20
0    20  4  20  0

output=

dH = 10
1   2
2   3
3   4
3   5
*/