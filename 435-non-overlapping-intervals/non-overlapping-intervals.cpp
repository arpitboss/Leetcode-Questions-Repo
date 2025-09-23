class Solution {
public:
    static bool comp(const vector<int> &a, const vector<int> &b) {
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        int c=1, pr=0;
        for (int i=1;i<intervals.size();i++) {
            if (intervals[pr][1]<=intervals[i][0]) {
                c++;
                pr=i;
            }
        }
        return intervals.size()-c;
    }
};