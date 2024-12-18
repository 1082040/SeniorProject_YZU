#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int m, a, b;
multiset <int> st[1000];
vector <int> ans;

void dfs(int x) {
    while (st[x].size()) {
        int nxt = *st[x].begin();
        st[x].erase(st[x].find(nxt));
        st[nxt].erase(st[nxt].find(x));
        dfs(nxt);
    }
    ans.push_back(x);
}

int main() {
    while (cin >> m) {
        if (m == 0) break;
        ans.clear();
        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            st[a].insert(b);
            st[b].insert(a);
        }
        int start = 1;
        for (int i = 1; i <= 500; i++) {
            if (st[i].size() % 2 == 1) {
                start = i;
                break;
            }
        }

        dfs(start);
        if (ans.size() < 3) break;
        reverse(ans.begin(), ans.end());
        cout << "\n";
        int count = ans.size();
        for (int i : ans) {
            cout << i;
            count--;
            if (count != 0)cout << "->";
        }
        cout << "\n";
    }
}
