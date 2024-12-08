class Solution {
public:
    int res = INT_MAX;
    void bfs(int node, vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> currentPath(n, INT_MAX);
        vector<int> parent(n, -1);
        
        queue<int> q;
        q.push(node);
        currentPath[node] = 0;
        
        while (!q.empty()) {
            int f = q.front();
            q.pop();  
            for (int i : graph[f]) {
                if (currentPath[i] == INT_MAX) {
                    currentPath[i] = currentPath[f] + 1;
                    parent[i] = f;
                    q.push(i);
                }
                else if (parent[f] != i) {
                    int tmp = currentPath[f] + currentPath[i] + 1;
                    res = min(res, tmp);
                }
            }
        }
    }
    
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for (auto edge:edges) {
            int a=edge[0];
            int b=edge[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        
        for (int i = 0; i < n; i++) {
            bfs(i, graph);
        }
        return res == INT_MAX ? -1 : res;
    }
};