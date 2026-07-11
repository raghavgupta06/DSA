#include <vector>

using namespace std;

class Solution {
    struct CM {
        int v = 0;
        int e = 0;

        void add(int d) {
            v += 1;
            e += d;
        }

        bool ok() const {
            if (v == 0) return false;
            return e == (v * (v - 1));
        }
    };

    class NA {
        vector<vector<int>> g;
        vector<bool> vis;

        void dfs(int u, CM& m) {
            vis[u] = true;
            m.add(g[u].size());

            for (int nxt : g[u]) {
                if (!vis[nxt]) {
                    dfs(nxt, m);
                }
            }
        }

    public:
        NA(int n, const vector<vector<int>>& ed) 
            : g(n), vis(n, false) {
            for (const auto& edge : ed) {
                g[edge[0]].push_back(edge[1]);
                g[edge[1]].push_back(edge[0]);
            }
        }

        int rec(int i) {
            if (i >= g.size()) return 0;
            if (vis[i]) return rec(i + 1);

            CM m;
            dfs(i, m);
            
            int res = m.ok() ? 1 : 0;
            return res + rec(i + 1);
        }
    };

public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        NA a(n, edges);
        return a.rec(0);
    }
};