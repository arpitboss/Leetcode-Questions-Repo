class Solution {
public:
    bool makeCycle(int node, vector<vector<int>>& graph, vector<int>& currentPath, vector<int>& vis) {
        vis[node]=1;
        currentPath[node]=1;
        for (auto i:graph[node]) {
            if (!vis[i]) {
                if (makeCycle(i,graph,currentPath,vis)) {
                    return true;
                }
            }
            else if (vis[i] && currentPath[i]) {
                return true;
            }
        }
        currentPath[node]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> v;
        vector<int> currentPath(graph.size(),0);
        vector<int> vis(graph.size());
        for (int i=0;i<graph.size();i++) {
            if (!makeCycle(i,graph,currentPath,vis)) {
                v.push_back(i);
            }
        }
        return v;
    }
};