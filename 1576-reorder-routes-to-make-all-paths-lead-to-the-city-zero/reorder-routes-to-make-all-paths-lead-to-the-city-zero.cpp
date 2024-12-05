class Solution {
public:
    void dfs(int node, vector<vector<int>> &forward, vector<vector<int>> &backward, vector<int> &vis, int &ans) {
        vis[node]=1;
        for (auto i:forward[node]) {
            if (!vis[i]) {
                ans++;
                dfs(i,forward,backward,vis,ans);
            }
        }

        for (auto i:backward[node]) {
            if (!vis[i]) {
                dfs(i,forward,backward,vis,ans);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> forward(n), backward(n);
        vector<int> vis(n);
        int ans=0;
        for (int i=0;i<connections.size();i++) {
            int a=connections[i][0];
            int b=connections[i][1];
            forward[a].push_back(b);
            backward[b].push_back(a);
        }
        dfs(0,forward,backward,vis,ans);
        return ans;
    }
};