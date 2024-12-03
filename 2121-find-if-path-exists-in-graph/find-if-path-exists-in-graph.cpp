class Solution {
public:
    bool bfs(vector<vector<int>> &graph, int s, int d, int n) {
        vector<int> vis(n,0);
        queue<int> q;
        q.push(s);
        vis[s]=1;

        while (!q.empty()) {
            int f=q.front();
            q.pop();
            for (auto x:graph[f]) {
                if (x==d) {
                    return true;
                }
                if (!vis[x]) {
                    vis[x]=1;
                    q.push(x);
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

        if (bfs(graph,source,destination,n)) {
            return true;
        }
        else {
            return false;
        }
    }
};