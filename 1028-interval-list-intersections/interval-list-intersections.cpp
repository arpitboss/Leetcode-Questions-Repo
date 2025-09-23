class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> res={};
        if (secondList.empty()) return res;

        int n=firstList.size();
        int m=secondList.size();
        int i=0, j=0;
        while (i<n && j<m) {
            int x=max(firstList[i][0],secondList[j][0]);
            int y=min(firstList[i][1],secondList[j][1]);

            if (x<=y) {
                res.push_back({x,y});
            }

            if (firstList[i][1]<secondList[j][1]) {
                i++;
            } else if (firstList[i][1]>secondList[j][1]) {
                j++;
            } else {
                i++;
                j++;
            }
        }
        return res;
    }
};