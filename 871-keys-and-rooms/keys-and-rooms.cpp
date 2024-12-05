class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> vis(rooms.size());
        queue<int> q;
        q.push(0);
        vis[0]=1;

        while (!q.empty()) {
            int f=q.front();
            q.pop();
            for (int i:rooms[f]) {
                if (!vis[i]) {
                    vis[i]=1;
                    q.push(i);
                }
            }
        }
        for (int i=0;i<rooms.size();i++) {
            if (!vis[i]) {
                return false;
            }
        }
        return true;
    }
};