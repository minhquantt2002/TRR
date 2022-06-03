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
    for (int k = 1; k <= n - 2; k++) {
        for (int v = 1; v <= n; v++) {
            if (check[v] == 0) {
                for (int u = 1; u <= n; u++) {
                    if (a[u][v] != MAX && d[v] > d[u] + a[u][v]) {
                        d[v] = d[u] + a[u][v];
                        truoc[v] = u;
                    }
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
9								
3								
0	7	0	9	 4	 0	 0	 0	 0
0	0	3	0	-4	 0	 0	 0	 0
0	0	0	0	-8	 0	-3	 0	 0
0	0	0	0	 0	 0	 0	-4	 0
0	0	0	5	 0	 2	 0	 3	 0
0	0	0	0	 0	 0	 5	 0	 2
0	0	0	0	 0	 0	 0	 0	-7
0	0	0	0	 0	-2	 0	 0	-3
0	0	0	0	 0	 0	 0	 0	 0

output=

K/c 3 -> 1 = INF;
K/c 3 -> 2 = INF;
K/c 3 -> 3 = 0;        3 <- 3
K/c 3 -> 4 = -3;       4 <- 5 <- 3
K/c 3 -> 5 = -8;       5 <- 3
K/c 3 -> 6 = -9;       6 <- 8 <- 4 <- 5 <- 3
K/c 3 -> 7 = -4;       7 <- 6 <- 8 <- 4 <- 5 <- 3
K/c 3 -> 8 = -7;       8 <- 4 <- 5 <- 3
K/c 3 -> 9 = -11;      9 <- 7 <- 6 <- 8 <- 4 <- 5 <- 3

case=2
input=
5				
1				
0	1	0	0	 3
0	0	3	3	 8
0	0	0	1	-5
0	0	2	0	 0
0	0	0	4	 0

output=

K/c 1 -> 1 = 0;        1 <- 1
K/c 1 -> 2 = 1;        2 <- 1
K/c 1 -> 3 = 4;        3 <- 2 <- 1
K/c 1 -> 4 = 3;        4 <- 5 <- 3 <- 2 <- 1
K/c 1 -> 5 = -1;       5 <- 3 <- 2 <- 1
*/