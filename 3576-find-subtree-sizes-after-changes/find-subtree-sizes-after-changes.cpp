class Solution {
    vector<vector<int>> adj;
    vector<int> vis, ans;
    int last[26];

    void dfs(int x, string &s)
    {
        vis[x] = 1;
        int c = s[x] - 'a';
        int old = last[c];
        last[c] = x;

        for (auto y : adj[x])
        {
            if (vis[y]) continue;
            dfs(y, s);
            int t = last[s[y] - 'a'];
            if (t == -1) t = x;
            ans[t] += ans[y];
        }

        last[c] = old;
    }

public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = s.size();
        vis.assign(n, 0);
        ans.assign(n, 1);
        fill(last, last + 26, -1);
        adj.assign(n, vector<int>());
        for (int u = 1; u < n; u++)
        {
            int v = parent[u];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(0, s);
        return ans;
    }
};