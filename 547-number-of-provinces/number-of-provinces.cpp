class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int m=isConnected[0].size();
        
        vector<vector<int>> graph(n+1);
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                if (isConnected[i][j] && i!=j) {
                    graph[i+1].push_back(j+1);
                }
            }
        }

        vector<int> vis(n+1);
        queue<int> q;
        vis[0]=1;
        int ans=0;
        for (int i=1;i<=n;i++) {
            if (!vis[i]) {
                q.push(i);
                while (!q.empty()) {
                    int f=q.front();
                    q.pop();
                    for (int j:graph[f]) {
                        if (!vis[j]) {
                            vis[j]=1;
                            q.push(j);
                        }
                    }
                }
                ans++;
            }
        }
        return ans;
    }
};