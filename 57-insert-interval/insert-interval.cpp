class Solution {
public:
    static bool comp(const vector<int> &a, const vector<int> &b) {
        return a[0]<b[0];
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end(),comp);
        vector<int> pr=intervals[0];
        for (int i=1;i<intervals.size();i++) {
            if (pr[1]>=intervals[i][0]) {
                pr[1]=max(pr[1],intervals[i][1]);
            }
            else {
                res.push_back(pr);
                pr=intervals[i];
            }
        }
        res.push_back(pr);
        return res;
    }
};