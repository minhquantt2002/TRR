#include <bits/stdc++.h>
using namespace std;
int n, s, t;
int a[100][100];
int main() {
    stack<int> st, CE;
    cin >> n >> s;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
    }
    st.push(s);
    while (!st.empty()) {
        bool vs = false;
        s = st.top();
        for (int i = 1; i <= n; ++i) {
            if (a[s][i] == 1) {
                a[s][i] = a[i][s] = 0;
                st.push(i);
                vs = true;
                break;
            }
        }
        if (!vs) {
            st.pop();
            CE.push(s);
        }
    }
    while (!CE.empty()) {
        cout << CE.top() << " ";
        CE.pop();
    }
}

/*
case=1
input=
6
1
0  0  0  1  1  0  
0  0  1  1  1  1  
0  1  0  1  1  1  
1  1  1  0  1  0  
1  1  1  1  0  0  
0  1  1  0  0  0  
output=
1  4  2  3  4  5  2  6  3  5  1

case=2
input=
13
5
0 1 0 0 0 1 0 0 0 0 0 0 0
1 0 1 0 1 1 0 0 0 0 0 0 0
0 1 0 1 1 0 0 0 0 0 1 0 0
0 0 1 0 0 0 1 1 0 0 1 0 0
0 1 1 0 0 1 1 0 0 0 0 0 0
1 1 0 0 1 0 1 0 0 0 0 0 0
0 0 0 1 1 1 0 1 0 0 0 0 0
0 0 0 1 0 0 1 0 1 1 0 0 0
0 0 0 0 0 0 0 1 0 1 0 1 1
0 0 0 0 0 0 0 1 1 0 1 1 0
0 0 1 1 0 0 0 0 0 1 0 1 0
0 0 0 0 0 0 0 0 1 1 1 0 1
0 0 0 0 0 0 0 0 1 0 0 1 0

output=
5 2  1  6  2  3  4  7  5  3  11  4  8  9  10  11  12  9  13  12  10  8  7  6  5

case=3
input=
13
7
0 0 0 1 0 1 0 0 0 0 0 0 0
0 0 1 0 0 0 0 1 0 1 1 0 0
0 1 0 0 0 0 0 0 1 1 0 0 1
1 0 0 0 0 1 0 1 0 0 0 1 0
0 0 0 0 0 0 1 0 1 0 0 0 0
1 0 0 1 0 0 0 0 0 1 0 1 0
0 0 0 0 1 0 0 0 0 0 1 0 1
0 1 0 1 0 0 0 0 0 0 1 1 0
0 0 1 0 1 0 0 0 0 0 0 0 1
0 1 1 0 0 1 0 0 0 0 0 1 0
0 1 0 0 0 0 1 1 0 0 0 0 1
0 0 0 1 0 1 0 1 0 1 0 0 0
0 0 1 0 0 0 1 0 1 0 1 0 0
output=
7  5  9  3  2  8  4  1  6  4  12  6  10  2  11  7  13  3  10  12  8  11  13  9
*/