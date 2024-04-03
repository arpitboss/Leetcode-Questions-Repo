class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> v;
        vector<int> ds;
        func(0,target,candidates,v,ds);
        return v;
    }

    void func(int index, int target, vector<int> &candidates, vector<vector<int>> &v, vector<int> &ds) {
        if (target==0) {
            v.push_back(ds);
            return;
        }
        for (int i=index;i<candidates.size();i++) {
            if (candidates[i]<=target) {
            ds.push_back(candidates[i]);
            func(i,target-candidates[i],candidates,v,ds);
            ds.pop_back();
            }
        }
    }
};