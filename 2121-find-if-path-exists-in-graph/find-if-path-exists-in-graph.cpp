class Solution {
public:
    bool dfs(vector<vector<int>> &graph, int s, int d, vector<int> &vis) {
        vis[s]=1;
        for (auto x:graph[s]) {
            if (x==d) {
                return true;
            }
            if (!vis[x]) {
                if (dfs(graph,x,d,vis)) {
                    return true;
                }
            }
        }
        if (vis[d]) {
            return true;
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n);
        for (int i=0;i<edges.size();i++) {
           int a=edges[i][0];
           int b=edges[i][1];
           graph[a].push_back(b);
           graph[b].push_back(a);
        }
        vector<int> vis(n,0);
        return dfs(graph,source,destination,vis);
    }
};