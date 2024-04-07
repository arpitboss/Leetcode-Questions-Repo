class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        func(0, nums, result);
        return result;
    }

    void func(int i, vector<int>& nums, vector<vector<int>>& result) {
        if (i == nums.size()) { result.emplace_back(nums); return; }
        unordered_set<int> st;
        for (int j = i; j < nums.size(); ++j) {
            if (st.count(nums[j]) == 1) { 
                continue; 
            }
            st.insert(nums[j]);
            swap(nums[i], nums[j]);
            func(i + 1, nums, result);
            swap(nums[i], nums[j]);
        }
    }
};