#include<bits/stdc++.h>
using namespace std;
int a[1005][1005];
int MAX = 1e9;

int main(){
    int n, s; cin >> n >> s;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 0) a[i][j] = MAX;
        }
    }
    int d[n + 1], m = n - 1, truoc[n + 1] = {}, check[n + 1] = {};
    d[s] = 0, check[s] = 1;
    for (int i = 1; i <= n; i++) {
        if (check[i] == 0) {
            d[i] = a[s][i];
            truoc[i] = s; 
        }
    }
    for (int k = 1; k <= n - 1; k++) {
        int Min = MAX, u;
        for (int i = 1; i <= n; i++) {
            if (check[i] == 0 && Min > d[i]) {
                Min = d[i];
                u = i;
            }
        }
        if (Min != MAX) {
            check[u] = 1; 
            for (int v = 1; v <= n; v++) {
                if (check[v] == 0 && d[v] > d[u] + a[u][v] && a[u][v] != MAX) {
                    d[v] = d[u] + a[u][v];
                    truoc[v] = u;
                }
            }
        }
        
    }
    // int i = 1;
    for (int i = 1; i <= n; i++) {
        if (d[i] == MAX) {
            cout << "K/c " << s << " -> " << i << " = INF;" << endl;
        } else {
            cout << "K/c " << s << " -> " << i << " = " << d[i] << "; ";
            queue<int> st;
            st.push(i);
            int u = i;
            
            while (u != s) {
                u = truoc[u];
                st.push(u);
            }
            if (st.size() != 1) {
                while (st.size() != 1) {
                    cout << st.front() << " <- ";
                    st.pop();
                }
            } else {
                cout << st.front() << " <- ";
            }
            
            cout << s << endl;
        }
    }
}
/*
case=1

input=
13
1
0   2   8   0   0   0   0   0   0   0   0   0   0
0   0   2   0   0   0   9   0   0   0   0   0   0
0   0   0   6   0   8   1   0   0   0   0   0   0
7   0   0   0   0   0   0   0   0   0   0   0   0
0   0   1   7   0   0   0   0   0   0   0   0   0
0   0   0   0   1   0   0   9   8   0   0   0   0
0   0   0   0   0   2   0   2   0   0   0   0   0
0   0   0   0   0   0   0   0   9   0   0   2   0
0   0   0   0   0   0   0   0   0   6   0   9   8
0   0   0   0   7   6   0   0   0   0   0   0   0
0   0   0   0   0   0   0   0   6   7   0   0   0
0   0   0   0   0   0   0   0   0   0   0   0   2
0   0   0   0   0   0   0   0   0   0   7   0   0

output=
K/c 1 -> 1 = 0;        1 <- 1
K/c 1 -> 2 = 2;        2 <- 1
K/c 1 -> 3 = 4;        3 <- 2 <- 1
K/c 1 -> 4 = 10;       4 <- 3 <- 2 <- 1
K/c 1 -> 5 = 8;        5 <- 6 <- 7 <- 3 <- 2 <- 1
K/c 1 -> 6 = 7;        6 <- 7 <- 3 <- 2 <- 1
K/c 1 -> 7 = 5;        7 <- 3 <- 2 <- 1
K/c 1 -> 8 = 7;        8 <- 7 <- 3 <- 2 <- 1
K/c 1 -> 9 = 15;       9 <- 6 <- 7 <- 3 <- 2 <- 1
K/c 1 -> 10 = 21;      10 <- 9 <- 6 <- 7 <- 3 <- 2 <- 1
K/c 1 -> 11 = 18;      11 <- 13 <- 12 <- 8 <- 7 <- 3 <- 2 <- 1
K/c 1 -> 12 = 9;       12 <- 8 <- 7 <- 3 <- 2 <- 1
K/c 1 -> 13 = 11;      13 <- 12 <- 8 <- 7 <- 3 <- 2 <- 1


case=2
input=
13
10
0   2   8   0   0   0   0   0   0   0   0   0   0
0   0   2   0   0   0   9   0   0   0   0   0   0
0   0   0   6   0   8   1   0   0   0   0   0   0
7   0   0   0   0   0   0   0   0   0   0   0   0
0   0   1   7   0   0   0   0   0   0   0   0   0
0   0   0   0   1   0   0   9   8   0   0   0   0
0   0   0   0   0   2   0   2   0   0   0   0   0
0   0   0   0   0   0   0   0   9   0   0   2   0
0   0   0   0   0   0   0   0   0   6   0   9   8
0   0   0   0   7   6   0   0   0   0   0   0   0
0   0   0   0   0   0   0   0   6   7   0   0   0
0   0   0   0   0   0   0   0   0   0   0   0   2
0   0   0   0   0   0   0   0   0   0   7   0   0

output=
K/c 10 -> 1 = 21;      1 <- 4 <- 5 <- 10
K/c 10 -> 2 = 23;      2 <- 1 <- 4 <- 5 <- 10
K/c 10 -> 3 = 8;       3 <- 5 <- 10
K/c 10 -> 4 = 14;      4 <- 5 <- 10
K/c 10 -> 5 = 7;       5 <- 10
K/c 10 -> 6 = 6;       6 <- 10
K/c 10 -> 7 = 9;       7 <- 3 <- 5 <- 10
K/c 10 -> 8 = 11;      8 <- 7 <- 3 <- 5 <- 10
K/c 10 -> 9 = 14;      9 <- 6 <- 10
K/c 10 -> 10 = 0;      10 <- 10
K/c 10 -> 11 = 22;     11 <- 13 <- 12 <- 8 <- 7 <- 3 <- 5 <- 10
K/c 10 -> 12 = 13;     12 <- 8 <- 7 <- 3 <- 5 <- 10
K/c 10 -> 13 = 15;     13 <- 12 <- 8 <- 7 <- 3 <- 5 <- 10


case=3
input=
6
1
0   1   0   0   0   0
0   0   5   2   0   7
0   0   0   0   0   1
2   0   1   0   4   0
0   0   0   3   0   1
0   0   0   0   0   0

output=
K/c 1 -> 1 = 0;        1 <- 1
K/c 1 -> 2 = 1;        2 <- 1
K/c 1 -> 3 = 4;        3 <- 4 <- 2 <- 1
K/c 1 -> 4 = 3;        4 <- 2 <- 1
K/c 1 -> 5 = 7;        5 <- 4 <- 2 <- 1
K/c 1 -> 6 = 5;        6 <- 3 <- 4 <- 2 <- 1


case=4
input=
6
6
0   1   0   0   0   0
0   0   5   2   0   7
0   0   0   0   0   1
2   0   1   0   4   0
0   0   0   3   0   1
0   0   0   0   0   0

output=
K/c 6 -> 1 = INF;
K/c 6 -> 2 = INF;
K/c 6 -> 3 = INF;
K/c 6 -> 4 = INF;
K/c 6 -> 5 = INF;
K/c 6 -> 6 = 0;         6 <- 6
*/