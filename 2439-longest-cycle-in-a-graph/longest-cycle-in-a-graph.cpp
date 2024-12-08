class Solution {
public: 
    int res=-1;
    void dfs(int node, vector<int> &graph, vector<int> &vis, vector<int> &currentPath, int count) {
        count++;
        vis[node]=1;
        currentPath[node]=count;
        int nbr=graph[node];
        if (nbr!=-1) {
            if (!vis[nbr]) {
                dfs(nbr,graph,vis,currentPath,count);
            }
            else if (currentPath[nbr]) {
                int tmp=currentPath[node]-currentPath[nbr]+1;
                res=max(res,tmp);
            }
        }
        currentPath[node]=0;
    }
    int longestCycle(vector<int>& edges) {
        vector<int> currentPath(edges.size());
        vector<int> vis(edges.size());
        for (int i=0;i<edges.size();i++) {
            if (!vis[i])
            dfs(i,edges,vis,currentPath,0);
        }
        return res;
    }
};