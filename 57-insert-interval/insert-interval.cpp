class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        if (intervals.size()==0) {
            return {newInterval};
        }
        int st=0, en=intervals.size()-1;
        while (st<en) {
            int mid=st+(en-st)/2;
            if (intervals[mid][0]>newInterval[0]) {
                en=mid-1;
            }
            else {
                st=mid+1;
            }
        }
        if (intervals[st][0]>newInterval[0]) {
            intervals.insert(intervals.begin()+st,newInterval);
        }
        else {
            intervals.insert(intervals.begin()+st+1,newInterval);
        }
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