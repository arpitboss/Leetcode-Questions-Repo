class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> u;
        vector<int> v;
        printSubsets(nums,u,v,0);
        return u;
    }

    void printSubsets(vector<int>& nums,vector<vector<int>>& u, vector<int>& v, int index) {
        if (index==nums.size()) {
            u.push_back(v);
            return;
        }
        
        v.push_back(nums[index]);
        printSubsets(nums,u,v,index+1);
        v.pop_back();
        printSubsets(nums,u,v,index+1);
    }
};