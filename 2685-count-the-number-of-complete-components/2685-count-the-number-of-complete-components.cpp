#include <vector>

using namespace std;

class Solution {
    struct Info {
        int v = 0;
        int e = 0;

        void add(int d) {
            v++;
            e += d;
        }

        bool ok() {
            return v > 0 && e == v * (v - 1);
        }
    };

    struct Solver {
        vector<vector<int>> adj;
        vector<bool> vis;
        vector<int> left;

        Solver(int n, vector<vector<int>>& edges) {
            adj.resize(n);
            vis.assign(n, false);
            for (auto& ed : edges) {
                adj[ed[0]].push_back(ed[1]);
                adj[ed[1]].push_back(ed[0]);
            }
            for (int i = 0; i < n; i++) {
                left.push_back(i);
            }
        }

        void dfs(int u, Info& info) {
            vis[u] = true;
            info.add(adj[u].size());
            for (int nxt : adj[u]) {
                if (!vis[nxt]) dfs(nxt, info);
            }
        }

        int calc() {
            int ans = 0;
            while (!left.empty()) {
                int cur = left.back();
                left.pop_back();
                
                if (vis[cur]) continue;
                
                Info info;
                dfs(cur, info);
                if (info.ok()) ans++;
            }
            return ans;
        }
    };

public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        Solver s(n, edges);
        return s.calc();
    }
};