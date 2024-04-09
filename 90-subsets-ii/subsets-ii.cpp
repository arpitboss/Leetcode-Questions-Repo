class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> v;
        vector<int> ds;
        func(nums,v,ds,0);
        return v;
    }

    void func(vector<int> &nums, vector<vector<int>> &v, vector<int> &ds, int index) {
        v.push_back(ds);
        for (int i=index;i<nums.size();i++) {
            if (i>index && nums[i]==nums[i-1]) {
                continue;
            }
            ds.push_back(nums[i]);
            func(nums,v,ds,i+1);
            ds.pop_back();
        }
    }
};