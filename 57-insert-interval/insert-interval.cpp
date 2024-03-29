class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> v;
        for (int i=0;i<intervals.size();i++) {
            // New Interval is after the range of interval
            if (intervals[i][1]<newInterval[0]) {
                v.push_back(intervals[i]);
            }

            // New Interval is before the range of interval
            else if (intervals[i][0]>newInterval[1]) {
                v.push_back(newInterval);
                newInterval=intervals[i];
            }

            // New Interval is in the range of interval
            else if (intervals[i][1]>=newInterval[0] || intervals[i][0]<=newInterval[1]) {
                newInterval[0]=min(intervals[i][0],newInterval[0]);
                newInterval[1]=max(intervals[i][1],newInterval[1]);
            }
        }
        v.push_back(newInterval);
        return v;
    }
};