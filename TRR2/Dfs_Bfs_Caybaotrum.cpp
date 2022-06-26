#include <bits/stdc++.h>
using namespace std;
int a[1005][1005], u, n;
void bfs() {
    cout << "BFS tree\n";
    int vs[1005] = {0};
    queue<int> q;
    q.push(u);
    while (!q.empty()) {
        int s = q.front();
        q.pop();
        for (int i = 1; i <= n; i++) {
            if (i == u) continue;
            if (a[s][i] == 1 && vs[i] == 0) {
                if (s < i) cout << s << " " << i << endl;
                else cout << i << " " << s << endl;
                vs[i] = 1;
                q.push(i);
            }
        }
    }
}
void dfs() {
    cout << "DFS tree \n";
    int vs[1005] = {0};
    stack<int> st;
    st.push(u);
    vs[u] = 1;
    while (!st.empty()) {
        int s = st.top();
        st.pop();
        for (int i = 1; i <= n; i++) {
            if (a[s][i] == 1 && vs[i] == 0) {
                if (i == u) continue;
                if (s < i) cout << s << " " << i << endl;
                else cout << i << " " << s << endl;
                vs[i] = 1;
                st.push(s);
                st.push(i);
                break;
            }
        }
    }
} 
int main() {
    cin >> n >> u;
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= n; j++) 
            cin >> a[i][j];
    dfs();
    bfs();
} 